#include<stdio.h>

int main()
{
    typedef struct{
        int month;
        int day;
        int year;
    } date;

    struct{
        int acct_no;
        char acct_type;
        char name[20];
        float balance;
        date lastpayment;
    } customer, *pc = &customer;

    printf("Number of bytes (dec): %d\n",sizeof *pc);
    printf("Number of bytes (hex): %x\n\n",sizeof *pc);
    printf("Starting Address (hex): %x\n",pc);
    printf("Incremented Address (hex): %x", ++pc);
}