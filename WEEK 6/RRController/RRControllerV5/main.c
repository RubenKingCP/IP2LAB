#include <stdio.h>
#include <stdlib.h>
#include "headers/robot.h"
#include <conio.h>

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
	
	//Algorithm variables
	int robotMoveState;
	int justTurned; //Variable to test if the robot did a right turn or not
	int start = 1; //Start of program or not
	
	//Set structure 
	struct sensors robotSensors; 
	
	//Right turn counter
	int countRight = 0;
	
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
		loadLabyrinth(socketfd, "labyrinth6.lab");
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
	
	//Quality check for sensor
	int checkSensor = robotGetSensors(socketfd, &robotSensors);
	if (checkSensor == 1) {
		printf("SENSOR ERROR");
		return -1;
	}
	
	
	while(exit != 1) {
		
		//If conditional to check for wall 
		if (robotMode == 0) {
			
			robotGoAhead(socketfd);
			
			//If it sees empty right wall turn.
			if (robotSensors.right.wall == 0) {
				if (start == 1) {
					usleep(800000);
					start = 0;
				}
				else {
					//Center robot before turning
					robotStep(socketfd, 2);
					robotTurnRight(socketfd);
				
					//Do 6 steps to prevent turning again
					robotStep(socketfd, 6);
				
					//Added to remove a small amount of stutter
					robotGoAhead(socketfd);
				}
			}
			//If in deadend make a uturn
			else if (robotSensors.right.wall == 1 && robotSensors.left.wall == 1 && robotSensors.right.wall == 1 && robotSensors.front.distance == 2) {
				robotTurnRight(socketfd);
				robotTurnRight(socketfd);
				robotGoAhead(socketfd);
			}
			
			//If a right corner turn left
			else if (robotSensors.right.wall == 1 && robotSensors.front.wall == 1 && robotSensors.front.distance <= 2) {
				robotTurnLeft(socketfd);
				robotGoAhead(socketfd);
			}
			
			
			/*SECOND VERSION
			//If in deadend make a uturn
			if (robotSensors.right.wall == 1 && robotSensors.left.wall == 1 && robotSensors.right.wall == 1 && robotSensors.front.distance == 2) {
				robotStop(socketfd);
				robotTurnRight(socketfd);
				robotTurnRight(socketfd);
				justTurned == 0;
			}
			
			//If a right corner turn left
			else if (robotSensors.right.wall == 1 && robotSensors.front.wall == 1 && robotSensors.front.distance <= 2) {
				robotStop(socketfd);
				robotTurnLeft(socketfd);
				robotStep(socketfd, 8);
			}
			
			//If a left corner turn right
			else if (robotSensors.left.wall == 1 && robotSensors.front.wall == 1 && robotSensors.front.distance <= 2) {
				robotStop(socketfd);
				robotTurnRight(socketfd);
				robotStep(socketfd, 8);
			}
			
			//Right hug
			else if (robotSensors.right.wall == 0 && robotSensors.front.wall == 0 && justTurned == 0) {
				robotStop(socketfd);
				robotTurnRight(socketfd);
			}
			*/
			
			
			
			/*First Version of algorithm
			//Start robot if no wall in front
			if (robotSensors.front.wall == 0) robotGoAhead(socketfd);
			
			
			//Check if there is wall in front and at which distance
			else if (robotSensors.front.wall == 1 && robotSensors.front.distance <= 2) {
				
					//Stop robot
					robotStop(socketfd);
				
					//Check for right wall
					if (robotSensors.right.wall == 1) robotTurnLeft(socketfd);
				
					//Check left wall
			 		else if (robotSensors.left.wall == 1) robotTurnRight(socketfd);
			 		
			}
			*/
		}
		
		//Slight delay to the while loop
		usleep(100000);
		
		//Checks condition to exit loop
		exit = robotExitFound(socketfd);
		robotGetSensors(socketfd, &robotSensors);
	}
	
	//Center robot on exit and stop it
	robotStep(socketfd, 4);
	robotStop(socketfd);
	
	system("pause");
	return 0;
}
