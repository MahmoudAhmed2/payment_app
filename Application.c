#define _CRT_SERCURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include"Application.h"
#include"Card.h"
#include"Terminal.h"
#include"Server.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	Card_Data_Input_t Card_All_Data_Input;
	Card_Data_t* Card_All_Data = (Card_Data_t*)malloc(sizeof(Card_Data_t));
	int* Transaction_Date_From_Os;
	int state;
	int Transaction_Amount;
	int Max_Amount;
	printf("***Welcome***\n");
	Card_All_Data_Input.Name = GetCardUserName();
	Card_All_Data_Input.Expiration_Date = getCardExpiryDate();
	Card_All_Data_Input.PAN = getCardPAN();
	Transaction_Date_From_Os = getTransactionDate();
	state = isCardExpried(Card_All_Data_Input.Expiration_Date, getTransactionDate());
	if (state == True_) {
		printf("Declined Card Is Expired\n");
		return 0;
	}
	Transaction_Amount = getTransactionAmount();
	Max_Amount = setMaxAmount(Admin_Setting_Max_Amount);
	if(Transaction_Amount>Max_Amount){
		printf("Declined Exceeded Amount\n");
		return 0;
	}
	Card_All_Data = recieveTransactionData(Card_All_Data_Input.PAN,Card_All_Data_Input.Name);
	if (Card_All_Data == NULL) {
		printf("Declined Card Invalid\n");
		return 0;
	}
	state = isValidAccount(Card_All_Data,Card_All_Data_Input.PAN);
	if (state == False_) {
		printf("Declined Card Invalid\n");
		return 0;
	}

	state = isAmountAvailable(Card_All_Data,Transaction_Amount);
	if(state == False_) {
		printf("Declined Amount Not available\n");
		return 0;
	}
	saveTransaction(Card_All_Data, Transaction_Amount, Card_All_Data_Input.PAN);
	printf("***Transaction Succeeded***\n");
	return 0;
}
