#include<stdio.h>

typedef struct{
    char *name;
    int acct_no;
    char acct_type;
    float balance;
} record;

int main()
{
    void adjust(record *pt);

    static record customer = {"Talha", 3333, 'C', 33.33};
    printf("%s  %d  %c  %.2f\n",customer.name, customer.acct_no, customer.acct_type, customer.balance);
    
    adjust(&customer);
    printf("%s  %d  %c  %.2f\n",customer.name,customer.acct_no, customer.acct_type,customer.balance);
}

void adjust(record *pt)
{
    pt->name = "Al-Amin";
    pt->acct_no = 9999;
    pt->acct_type = 'R';
    pt->balance = 99.99;
    return;
}