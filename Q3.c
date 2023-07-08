#include "exam.h"


float distance( Location l1, Location l2 )
{
	return (float)sqrt( pow( l1.x - l2.x, 2 ) + pow( l1.y - l2.y, 2 ) );
}

Texi* findTexi(Yango* yango, Client* client, int maxDistance, int *maxPrice)
{
	int minDistance = maxDistance;//Will become the distance of the closest Texi
	Texi* min_distance_texi = NULL;
	//Will become one of the taxis which are the closest to client(can be more then one such taxi)
	for (int i = 0; i < yango->numTexis; i++) {
		Texi* t = yango->texis[i];

		/*texi distance from client*/
		float t_distance_c = distance(t->location, client->location);

		if (t_distance_c <= maxDistance && t_distance_c <= minDistance) {
			minDistance = t_distance_c;
			min_distance_texi = NULL;
		}
	}
	if (!min_distance_texi) {
		return NULL;
	}
	*maxPrice = 5 + (int)(2 * minDistance);
}

Client** getClientsFromSpecificDates( Yango* yango, char *firstTime, char *secondTime, int *numClients)
{
	*numClients = 0;
	Client** appliedClients = NULL;
	for (int i = 0; i < yango->numClients; i++) {
		Client* candidate = yango->clients[i];
		for (int j = 0; j < candidate->numRides; j++) {
			Ride* ride = candidate->rides[j];
			if (dateIsBetween(firstTime, secondTime, ride->date)) {
				appliedClients =
					(Client**)realloc(appliedClients, (*numClients + 1) * sizeof(Client*));
				(*numClients)++;
				break;//No need to check further rides for this client
			}
		}
	}
	return appliedClients;
}
int dateIsBetween(char* d1, char* d2, char* date) {
	/*Assumption: all 3 paramters are of structure:
		dd/mm/yyyy/hh/mm
		ie., to get the year string, one must observe d1[4] to d[7] (including)
	*/
	int day1 = stringToNum(d1, 0, 1);
	int day = stringToNum(date, 0, 1);
	int day2 = stringToNum(d2, 0, 1);

	int month1 = stringToNum(d1, 2, 3);
	int month = stringToNum(date, 2, 3);
	int month2 = stringToNum(d2, 2, 3);

	int year1 = stringToNum(d1, 4, 7);
	int year = stringToNum(date, 4, 7);
	int year2 = stringToNum(d2, 4, 7);

	int hour1 = stringToNum(d1, 8, 9);
	int hour = stringToNum(date, 8, 9);
	int hour2 = stringToNum(d2, 8, 9);

	int min1 = stringToNum(d1, 10, 11);
	int min = stringToNum(date, 10, 11);
	int min2 = stringToNum(d2, 10, 11);

	return year1 < year && year < year2 ||
			year1 <= year && year <= year2 &&
			(month1 < month && month < month2) ||
			year1 <= year && year <= year2 &&
			month1 <= month && month <= month2 &&
			(day1<day&&day<day2) ||
			year1 <= year && year <= year2 &&
			month1 <= month && month <= month2 &&
			day1 <= day && day <= day2 && 
			(hour1 < hour && hour< hour2)||
			year1 <= year && year <= year2 &&
			month1 <= month && month <= month2 &&
			day1 <= day && day <= day2 &&
			hour1 <= hour && hour <= hour2 &&
			(min1 <= min && min<=min2);
}
int stringToNum(char* str, int start_index, int end_index) {
	int num = 0;
	int exp = 1;
	for(int i = end_index; i >= start_index; i--) {
		num += exp*(str[i]-'0');
		exp *= 10;
	}
}