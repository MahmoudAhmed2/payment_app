#include "Card.h"
char* GetCardUserName() {
	char* User_Input_Card_Name = (char*)malloc(Name_Length * sizeof(char));
	char i = 0;
	printf("Please Enter Full Name On Card:\n");
	fgets(User_Input_Card_Name, Name_Length, stdin);
	while (User_Input_Card_Name[i] != NULL) {                //change space to _ for simplification
		if (User_Input_Card_Name[i] == ' ')
		{
			User_Input_Card_Name[i] = '_';
		}
		i++;
	}
	return User_Input_Card_Name;
}
int* getCardExpiryDate() {
	int* User_Input_Card_Expairation_Date = (int*)malloc(Full_Expairation_Date_Array_Length * sizeof(int));
	int Month, Year;
	printf("Please Enter Expairation Month_date of Card:\n");
	scanf("%d",&Month);
	User_Input_Card_Expairation_Date[Month_Index] = Month;
	printf("Please Enter Expairation Year_date of Card:\n");
	scanf("%d",&Year);
	User_Input_Card_Expairation_Date[Year_Index] = Year;
	return User_Input_Card_Expairation_Date;
}
char* getCardPAN() {
	char* User_Input_Card_PAN = (char*)malloc(PAN_Length * sizeof(char));
	printf("Please Enter  PAN Of Card:\n");
	scanf("%s",User_Input_Card_PAN);
	return User_Input_Card_PAN;
}

