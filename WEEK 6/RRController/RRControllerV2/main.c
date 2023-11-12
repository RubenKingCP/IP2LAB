#include <stdio.h>
#include <stdlib.h>
#include "headers/robot.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void repeatSteps(SOCKET sock, int times) {
	int i;
	for (i = 0; i < times; i++) {
		robotStep(sock, 8);
	}
}

int main() {
	//Set connection variables
	int port;
	char ip_adress[15];
	
	//Set robot variables
	char robotName[10];
	
	//Set robotMode variables
	int robotMode = 0;
	
	//Get ip_adress
	printf("Enter ip adress: ");
	scanf("%s", ip_adress);
	
	//Get port
	printf("\nEnter port: ");
	scanf("%d", &port);
	
	//Initiate connection
	SOCKET socketfd = connect2Labyrinth(ip_adress, port);
	
	//Load labyrinth and store return code
	int labyrinthLoadState = loadLabyrinth(socketfd, "labyrinth5.lab");
	
	//Quality check for labyrinth
	if (labyrinthLoadState == -1) {
		printf("File name error reload app!");
		return -1;
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
	
	//Set robotMode
	int robotModeLoadState = robotSetMode(socketfd, robotMode);
	
	//Quality check for robotMode
	if (robotLoadState == -1) {
		printf("File name error reload app!");
		return -1;
	}
	
	//Directions
	//First Turn
	repeatSteps(socketfd, 2);
	robotTurnRight(socketfd);
	
	//Second Turn
	repeatSteps(socketfd, 1);
	robotTurnLeft(socketfd);
	
	//Third Turn
	repeatSteps(socketfd, 2);
	robotTurnRight(socketfd);
	
	//Fourth Turn
	repeatSteps(socketfd, 2);
	robotTurnRight(socketfd);
	
	//Fifth Turn
	repeatSteps(socketfd, 2);
	robotTurnRight(socketfd);
	
	//Sixth Turn
	repeatSteps(socketfd, 1);
	robotTurnLeft(socketfd);
	
	//Seventh Turn
	repeatSteps(socketfd, 1);
	robotTurnLeft(socketfd);
	
	//Eighth Turn
	repeatSteps(socketfd, 1);
	robotTurnRight(socketfd);
	
	//NInth Turn
	repeatSteps(socketfd, 1);
	robotTurnLeft(socketfd);
	
	//Tenth Turn
	repeatSteps(socketfd, 1);
	robotTurnLeft(socketfd);
	
	//Final line
	repeatSteps(socketfd, 4);

	
	
	//System to find end
	int exit = robotExitFound(socketfd);
	while(exit != 1) {
		exit = robotExitFound(socketfd);
	}
	system("pause");
	return 0;
}
