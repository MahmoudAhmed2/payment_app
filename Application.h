#ifndef Application_H
#define Application_H
#define _CRT_SERCURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Card_data_input {
	char* Name;
	char* PAN;
	char* Password;
	char* Amount;
	int* Expiration_Date;
	char* Is_Blocked;

}Card_Data_Input_t;
#endif // !Application_H


