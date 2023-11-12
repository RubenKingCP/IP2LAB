#include <stdio.h>
#include <stdlib.h>
#include "headers/robot.h"
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*This is the V4 of the robot controller in which the user can control the robot with the use of w,a,d without needing to input a command each time plus the use of e to exit program
and the use of r to reset the robot*/

int main() {
	//Set connection variables
	int port;
	char ip_adress[15];
	
	//Set Labyrinth variables
	char labName[20]; //Get the labyrinth name
	
	//Set robot variables
	char robotName[10];
	
	//Set robotMode variables
	int robotMode;
	
	//Store user input
	int ascii;
	
	//Get ip_adress
	printf("Enter ip adress: ");
	scanf("%s", ip_adress);
	
	//Get port
	printf("\nEnter port: ");
	scanf("%d", &port);
	
	//Initiate connection
	SOCKET socketfd = connect2Labyrinth(ip_adress, port);
	
	//Get Labyrinth name
	printf("Enter Labyrinth file name: ");
	scanf("%20s", &labName);
	
	//Load labyrinth and store return code
	int labyrinthLoadState = loadLabyrinth(socketfd, labName);
	
	//Quality check for labyrinth
	if (labyrinthLoadState == -1) {
		printf("Error loading default!\n");
		loadLabyrinth(socketfd, "labyrinth5.lab");
	}
	
	//Get robot name
	printf("Enter robot name: ");
	scanf("%10s", robotName);
	
	//Load robot and store return code
	int robotLoadState = insertRobot(socketfd, robotName);
	
	//Quality check for robot
	if (robotLoadState == -1) {
		printf("File name error reload app!");
		return -1;
	}
	
	//Get robotMode
	printf("Set MANUAL or AUTO(0 or 1): ");
	scanf("%d", &robotMode);
	
	//Set robotMode
	int robotModeLoadState = robotSetMode(socketfd, robotMode);
	
	//Quality check for robotMode
	if (robotLoadState == -1) {
		printf("File name error reload app!");
		return -1;
	}
	
	if (robotMode == 0) {
		printf("Use w,a,d to navigate.\nPress r to reset.\nPress e to exit.");
	}
	//System to find end
	int exit = robotExitFound(socketfd);
	int labyrinthActive = 1;
	
	while(labyrinthActive != 0) {
    	
		//Ask directions
		if (robotMode == 0) {
			
			int ascii = getch();
		
			switch(ascii){
				case 119:
					robotStep(socketfd, 8);
					break;
				case 100:
					robotTurnRight(socketfd);
					break;
				case 97:
					robotTurnLeft(socketfd);
					break;
				case 114:
					robotGoHome(socketfd);
					break;
				case 101:
					labyrinthActive = 0;
				default:
					break;
			}	
		}
		//Checks condition to exit loop
		exit = robotExitFound(socketfd);
	}
	
	return 0;
}
