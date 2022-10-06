#include "Server.h"
Card_Data_t* recieveTransactionData(char* Input_PAN, char* Input_NAME) {
	FILE* Server_Database;
	int tmp = False;
	long List_Counter = NULL;
	Card_Data_t* To_Read_Account_Data = (Card_Data_t*)malloc(sizeof(Card_Data_t));
	fopen_s(&Server_Database, "Server_Accounts_Data_Base.txt", "r");
	while (!feof(Server_Database)) {
		fscanf(Server_Database, "%s %s %s %s %s", Server_Accounts_Formation);
		while (To_Read_Account_Data->PAN[tmp] != NULL) {
			if (To_Read_Account_Data->PAN[tmp] ==Input_PAN[tmp]) 
			{
				tmp++;
		    }
			else { 
				tmp = False;
			   break; 
			}
		}
		if (tmp == strlen(To_Read_Account_Data->PAN)) {
			tmp = False;
			while (To_Read_Account_Data->Name[tmp] != NULL) {
				if (To_Read_Account_Data->Name[tmp] == Input_NAME[tmp])
				{
					tmp++;
				}
				else {
					tmp = 0;
					break;
				}
			}
			if (tmp == strlen(To_Read_Account_Data->Name)) {

				fclose(Server_Database);
				return To_Read_Account_Data;
			}
		}
		
	}
	fclose(Server_Database);
	return NULL;
}
void saveTransaction(Card_Data_t* To_Save_Transaction, int TransactionAmount, char *Input_PAN) {
	FILE* Server_Database;
	FILE* Server_Database_BACKUP;
	time_t now;
	int tmp = False;
	int Amount_Server_Update=False;
	time(&now);
	struct tm* t = localtime(&now);
	fopen_s(&Server_Database, "Saved_Transactions.txt", "a");
	fprintf(Server_Database, Server_Transaction_Formation);
	fclose(Server_Database);
	fopen_s(&Server_Database, "Server_Accounts_Data_Base.txt", "r");
	fopen_s(&Server_Database_BACKUP, "Server_Accounts_Data_Base_BACKUP.txt", "a");
	while (!feof(Server_Database)) {                //replace value in text
		fscanf(Server_Database, Server_Accounts_Update_Formation);
		while (To_Save_Transaction->PAN[tmp] != NULL) {
			if (To_Save_Transaction->PAN[tmp] == Input_PAN[tmp])
			{
				tmp++;
			}
			else {
				tmp =False;
				break;
			}
		} 
		if (tmp == strlen(To_Save_Transaction->PAN)) {
			Amount_Server_Update = atoi(To_Save_Transaction->Amount) - TransactionAmount;//string to int
			itoa(Amount_Server_Update, To_Save_Transaction->Amount, Base_Decimal);//int to string
			fprintf(Server_Database_BACKUP, Server_Accounts_Update_Formation);
			tmp = False;
		}
		
		else {
			fprintf(Server_Database_BACKUP,Server_Accounts_Update_Formation);
		}
	}

	fclose(Server_Database);
	fclose(Server_Database_BACKUP);
	remove("Server_Accounts_Data_Base.txt");
	rename("Server_Accounts_Data_Base_BACKUP.txt", "Server_Accounts_Data_Base.txt");
}
int isValidAccount(Card_Data_t* To_Read_Account_Data,char*Input_PAN) {
	char password[5];
	int tmp = False;
	if (To_Read_Account_Data->Is_Blocked[0] == 'S') {
		return False;
	}
	while (To_Read_Account_Data->PAN[tmp] != NULL) {
		if (To_Read_Account_Data->PAN[tmp] == Input_PAN[tmp])
		{
			tmp++;
		}
		else {
			tmp = False;
			break;
		}
	}
	if (tmp != strlen(To_Read_Account_Data->PAN))
	{
		return False;
	}
	tmp = False;
	printf("Please Enter Your Password:\n");
	scanf("%s", password);
	while (To_Read_Account_Data->Password[tmp] != NULL) {
		if (To_Read_Account_Data->Password[tmp] == password[tmp])
		{
			tmp++;
		}
		else {
			tmp = False;
			break;
		}
	}
	if (tmp == strlen(To_Read_Account_Data->Password))
	{
		return True;
	}
	return False;
}
int isAmountAvailable(Card_Data_t*To_Read_Account_Data,int Input_Amount) {
	if (atoi(To_Read_Account_Data->Amount) >= Input_Amount) {
		return True;
	}
	else {
		return False;
	}
}