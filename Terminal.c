#include "Terminal.h"
int* getTransactionDate()
{
    int* Transaction_Date_from_Os = (int*)malloc(Transaction_Date_from_Os_Array_Size* sizeof(int));
    time_t Time_now;
    time(&Time_now);
    int Month;
    int Year;
    struct tm * t = localtime(&Time_now);
    Month = t->tm_mon + Time_Month_Const;
    Year = t->tm_year + Time_Year_Const;
    Transaction_Date_from_Os[Month_Index] = Month;
    Transaction_Date_from_Os[Year_Index] = Year;
    return Transaction_Date_from_Os;
}
int isCardExpried(int *Input_Expiration_Date,int *Transaction_Date_from_Os){
    if (Input_Expiration_Date[Year_Index] > Transaction_Date_from_Os[Year_Index]) {
        return False_;
    }
    if(Input_Expiration_Date[Year_Index] == Transaction_Date_from_Os[Year_Index])
    {
            if (Input_Expiration_Date[Month_Index] >= Transaction_Date_from_Os[Month_Index]) {
                return False_;
            }
    
    }
    return True_;
    
}
int getTransactionAmount() {
    int Transaction_Amount;
    printf("Please Enter Transcation Amount:\n");
    scanf("%d", &Transaction_Amount);
    return Transaction_Amount;
}
int isBelowMaxAmount(int Input_Transaction_Amount, int Max_transaction_Amount) {
    if (Max_transaction_Amount >= Input_Transaction_Amount) {
        return True_;
    }
    return 0;
}
int setMaxAmount(int Set_Max_Transaction_Amount) {
    int Max_Transaction_Amount;
    Max_Transaction_Amount = Set_Max_Transaction_Amount;
    return Max_Transaction_Amount;
}