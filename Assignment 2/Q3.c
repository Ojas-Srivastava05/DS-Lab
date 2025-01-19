#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BankMgmt
{
    int AccNumber;
    char CustName[100];
    float AvlBalance;
    char AccType[20];
    char BankName[10];
}BankMgmt;
void main()
{
    printf("Kindly enter the bank name \n");
    scanf("%s",&BankMgmt.BankName);
    printf("Enter you Account number \n");
    scanf("%d",&BankMgmt.AccNumber);
    printf("Enter your name \n");
    scanf("%s",&BankMgmt.CustName);
    printf("Enter the available balance \n");
    scanf("%f",&BankMgmt.AvlBalance);
    printf("Enter the account type \n");
    scanf("%s",&BankMgmt.AccType);


    printf("ENTER YOUR CHOICE IN 1,2,3 OR 4....1.WITHDRAWAL  2.DEPOSIT  3.DISPLAY BALANCE  4.EXIT \n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        int amt;
        printf("ENTER THE AMOUNT YOU WANT TO WITHDRAW \n");
        if(BankMgmt.AvlBalance>=amt)
        {
            printf("THE AMOUNT %d CAN BE SUCESSFULLY WITHDRAWN \n",amt);
            printf("THE REMAINING BANK BALANCE IS %d \n",BankMgmt.AvlBalance-amt);
        }
    }
    if(choice==2)
    {
        printf("ENTER THE AMOUNT TO BE DEPOSITED IN THE BANK ACCOUNT \n");
        float dep;
        scanf("%f",&dep);
        BankMgmt.AvlBalance=BankMgmt.AvlBalance+dep;
        printf("THE NEW AVAILABLE BALANCE OF THE ACCOUNT IS %f \n",BankMgmt.AvlBalance);
    }
    if(choice==3)
    {
        printf("THE CURRENT BALANCE OF THE BANK ACCOUNT IS %f ",BankMgmt.AvlBalance);
    }
    if(choice==4)
    {
        exit(0);
    }

}