#include "exam.h"

unsigned int tobin(unsigned int n10) 
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	
	/*Write your code down here*/	

	if (n10 / 2 == 0) {
		return 1;//MSB
	}
	return n10 % 2 + 10 * tobin(n10 / 2);
}