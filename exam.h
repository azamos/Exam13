#ifndef EXAM_H_
#define EXAM_H_

#ifndef NULL
#define NULL 0
#endif

#define COLS 4
#define _CRT_SECURED_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
	int x, y;
}Location;

typedef struct
{
	int id;
	Location location;
	int statusBusy;
}Texi;

typedef struct
{
	char date[13]; // ddmmyyyyhhmm  e.g 250320221430 means 25/03/2022 at 14:30
	Location from, to;
	int texiId;
	int minutes;
	int clientID;
	float price;
}Ride;


typedef struct
{
	char fname[20];
	char lname[20];
	int id;
	Location location;
	int numRides;
	Ride** rides;
}Client;

typedef struct
{
	int numTexis;
	Texi** texis;
	int numRides;
	Ride** rides;
	int numClients;
	Client** clients;
}Yango;



//Q1
int getNumFlowers(int mat[][COLS], int rows);
//Q2
unsigned int tobin(unsigned int num10);
void fx1();

//Q3
Texi* findTexi(Yango* yango, Client* client, int maxDistance, int* maxPrice);
Client** getClientsFromSpecificDates(Yango* yango, char* firstTime, char* secondTime, int* numClients);

#endif