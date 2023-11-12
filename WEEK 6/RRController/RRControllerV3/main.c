#include <stdio.h>
#include <stdlib.h>
#include "headers/robot.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
	
	//Set enumaration for directions
	enum directions {
		GO, 
		RIGHT,
		LEFT
	};
	
	int direction;
	
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
		printf("Error loading default!");
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
	
	//System to find end
	int exit = robotExitFound(socketfd);
	while(exit != 1) {
		
		//Ask directions
		if (robotMode == 0) {
			printf("Forward, turn right, turn left(0, 1, 2): ");
			scanf("%d", &direction);
		
			switch(direction){
				case 0:
					robotStep(socketfd, 8);
					break;
				case 1:
					robotTurnRight(socketfd);
					break;
				case 2:
					robotTurnLeft(socketfd);
				default:
					break;
			}	
		}
		//Checks condition to exit loop
		exit = robotExitFound(socketfd);
	}
	system("pause");
	return 0;
}
