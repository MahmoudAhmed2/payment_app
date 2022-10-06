#ifndef Server_H
#define Server_H
#define _CRT_SERCURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Base_Decimal 10
#define Max_Cards_On_List 200000000
#define Server_Accounts_Formation   To_Read_Account_Data->Name,To_Read_Account_Data->PAN,To_Read_Account_Data->Password,To_Read_Account_Data->Amount,To_Read_Account_Data->Is_Blocked
#define Server_Transaction_Formation  "\n%s %s %d %d:%d:%d %d/%d/%d",To_Save_Transaction->Name, To_Save_Transaction->PAN,TransactionAmount,t->tm_hour,t->tm_min,t->tm_sec,t->tm_mday,t->tm_mon + 1,t->tm_year + 1900
#define Server_Accounts_Update_Formation  "%s %s %s %s %s\n", To_Save_Transaction->Name, To_Save_Transaction->PAN,To_Save_Transaction->Password, To_Save_Transaction->Amount,To_Save_Transaction->Is_Blocked
typedef struct Card_data {
	char  Name[30];
	char  PAN[17];
	char  Password[5];
	char  Amount[15];
	int Expiration_Date[2];
	char Is_Blocked[1];

}Card_Data_t;
enum Bool_Check { False, True };
//server - side accounts(); is emulated as a text file on system (Server_Accounts_Data_Base.txt) 'updated while execution'
//server - side transactions();s emulated as a text file on system (Server_Transactions.txt) 'updated while execution'
Card_Data_t* recieveTransactionData(char*Input_PAN, char* Input_NAME);
int isValidAccount(Card_Data_t* To_Read_Account_Data, char* Input_PAN);
int isAmountAvailable(Card_Data_t* To_Read_Account_Data, int Input_Amount);
void saveTransaction(Card_Data_t* To_Save_Transaction, int TransactionAmount, char* Input_PAN);
/*
server - side accounts();
server - side transactions();
recieveTransactionData()
isValidAccount()
isAmountAvailable()
saveTransaction()*/
#endif // !Server_H