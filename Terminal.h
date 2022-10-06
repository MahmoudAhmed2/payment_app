#ifndef Terminal_H
#define Terminal_H
#define _CRT_SERCURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Time_Year_Const 1900
#define Time_Month_Const 1
#define Transaction_Date_from_Os_Array_Size 2
#define Month_Index 0
#define Year_Index  1
#define Admin_Setting_Max_Amount 20000
enum Bool_Check_ { False_, True_ };
int* getTransactionDate();
int isCardExpried(int* Input_Expiration_Date, int* Transaction_Date_from_Os);
int getTransactionAmount();
int isBelowMaxAmount(int Input_Transaction_Amount, int Max_transaction_Amount);
int setMaxAmount(int Set_Max_Transaction_Amount);
/*getTransactionDate()
isCardExpried()
getTransactionAmount()
isBelowMaxAmount()
setMaxAmount()*/
#endif // !Terminal_H


