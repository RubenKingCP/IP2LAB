#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/robot.h"
#include <conio.h>


#define UNICODE
#define _UNICODE

// Step 1: Declare the window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Step 2: Create WinMain function as the entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//Set connection variables
	int port;
	char ip_adress[15];
	SOCKET socketfd;
	
	//Set Labyrinth variables
	char labName[20]; //Get the labyrinth name
	int labyrinthLoadState; //Store success code of labyrinth load
	
	//Set robot variables
	char robotName[10];
	int robotLoadState; //Checks if robot was loaded or not
	int robotMode; //Check if manual or auto mode
	
	//Variable to check if it found exit or not
	int exit;
	
	//Get ip_adress
	printf("Enter ip adress: ");
	scanf("%s", ip_adress);
	
	//Get port
	printf("\nEnter port: ");
	scanf("%d", &port);
	
	//Initiate connection and store connection
	socketfd = connect2Labyrinth(ip_adress, port);
	
	//Get Labyrinth name
	printf("Enter Labyrinth file name: ");
	scanf("%20s", &labName);
	
	//Load labyrinth and store return code
	labyrinthLoadState = loadLabyrinth(socketfd, labName);
	
	//Quality check for labyrinth
	if (labyrinthLoadState == -1) {
		printf("Error loading default!\n");
		loadLabyrinth(socketfd, "labyrinth5.lab");
	}
	
	//Get robot name
	printf("Enter robot name: ");
	scanf("%10s", robotName);
	
	//Load robot and store return code
	robotLoadState = insertRobot(socketfd, robotName);
	
	//Quality check for robot
	if (robotLoadState == -1) {
		printf("File name error reload app!");
		return -1;
	}
	
	//Get robotMode
	printf("Set MANUAL or AUTO(0 or 1): ");
	scanf("%d", &robotMode);
	
	//Quality check for robotMode
	if (robotLoadState == -1) {
		printf("File name error reload app!");
		return -1;
	}

   //Register the window class
    WNDCLASSW wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MyWindowClass";

    RegisterClassW(&wc);
	
    //Create the window
    HWND hwnd = CreateWindowExW(
    	0,
        L"MyWindowClass",
        L"Remote Controller",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
        NULL,
        NULL,
        hInstance,
        NULL
    );
	
	//Quality check for the createWindowW
    if (hwnd == NULL) {
        return 0;
    }
    
    //Pass the socket to the winProc
	SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)socketfd);

    //Check robot mode and do the relevant action
    if (robotMode == 0) {
    	//Command to bring window
    	ShowWindow(hwnd, nCmdShow);
	}
	
	else {
		//While loop to check if it reached exit with a 0.1 sec delay between each loop
		while (exit != 1) {
			usleep(100000);
			exit = robotExitFound(socketfd);
		}
		printf("EXIT FOUND!\n");
		system("pause");
		return 0;
	}

    //Run the message loop
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

//Define the window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	//Get the socket adress from winMain
	SOCKET socketfd = (SOCKET)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	
	//Varible to monitor if it found exit or not
	int exitState = robotExitFound(socketfd);
	
    switch (uMsg) {
    	
    	
    	//Create Buttons
        case WM_CREATE: {
        
        //Forward button
	    HWND btnForward = CreateWindowW(
	        L"BUTTON",         // Predefined class; Unicode assumed
	        L"Left",        // Button text
	        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
	        50, 50, 80, 30,     // x, y, width, height
	        hwnd,              // Parent window
	        (HMENU)1,          // Button ID
	        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
	        NULL
	    );
	
		//Right button
	    HWND btnRight = CreateWindowW(
	        L"BUTTON",
	        L"Forward",
	        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
	        150, 50, 80, 30,
	        hwnd,
	        (HMENU)2,
	        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
	        NULL
	    );
		
		//Left button
	    HWND btnLeft = CreateWindowW(
	        L"BUTTON",
	        L"Right",
	        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
	        250, 50, 80, 30,
	        hwnd,
	        (HMENU)3,
	        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
	        NULL
	    );
	
		//Reset button
	    HWND btnReset = CreateWindowW(
	        L"BUTTON",
	        L"Reset",
	        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
	        100, 100, 80, 30,
	        hwnd,
	        (HMENU)4,
	        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
	        NULL
	    );
	    
	    //Exit button
	    HWND btnExit = CreateWindowW(
			L"BUTTON",
			L"Exit",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			200, 100, 80, 30,
			hwnd,
			(HMENU)5,
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
			NULL
			);
	    }


		//Link each button to an action(HMENU)
        case WM_COMMAND: {
        	
        	//Switch statement with the button id
            switch (LOWORD(wParam)) {
            	
                case 1:
                	//Handle Left button click
                	if (exitState == 1) {
                		MessageBoxW(hwnd, L"Exit Found!\nReset or Exit.", L"Button Click", MB_OK | MB_ICONINFORMATION);
                		return 0;
					}
                    robotTurnLeft(socketfd);
                    break;

                case 2:
                    //Handle Forward button click
                    if (exitState == 1) {
                		MessageBoxW(hwnd, L"Exit Found!\nReset or Exit.", L"Button Click", MB_OK | MB_ICONINFORMATION);
                		return 0;
					}
                    robotStep(socketfd, 8);
                    break;

                case 3:
                    //Handle Right button click
                    if (exitState == 1) {
                		MessageBoxW(hwnd, L"Exit Found!\nReset or Exit.", L"Button Click", MB_OK | MB_ICONINFORMATION);
                		return 0;
					}
                    robotTurnRight(socketfd);
                    break;

                case 4:
                    //Handle Reset button click
                    robotGoHome(socketfd);
                    break;
                
                case 5:
                    //Handle Exit button click
                    SendMessageW(hwnd, WM_CLOSE, 0, 0);
                    break;
            }
            break;
        }
        
		case WM_CLOSE: {
            //Handle the WM_CLOSE message
            if (MessageBoxW(hwnd, L"Are you sure you want to close the window?", L"Confirm Close", MB_YESNO | MB_ICONQUESTION) == IDYES) {
                DestroyWindow(hwnd);
            }
            break;
        }
        
        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
        }
    }

    //Default winProc exit
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
