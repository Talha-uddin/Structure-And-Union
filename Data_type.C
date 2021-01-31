#include<stdio.h>

int main()
{
    int n = 3333;
    char t = 'C';
    float b = 99.99;

    typedef struct {
        int month;
        int day;
        int year;
    }date;

    struct{
        int *acct_no;
        char *acct_type;
        char *name;
        float *balance;
        date lastpayment;
    }customer, *pc = &customer;

    customer.acct_no = &n;
    customer.acct_type = &t;
    customer.name = "Talha";
    customer.balance = &b;

    printf("%d  %c  %s  %.2f\n",*customer.acct_no,*customer.acct_type,customer.name,*customer.balance);
    printf("%d  %c  %s  %.2f",*pc->acct_no,*pc->acct_type,pc->name,*pc->balance);
}