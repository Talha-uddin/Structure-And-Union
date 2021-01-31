#include<stdio.h>

typedef struct{
    char *name;
    int acct_no;
    char acct_type;
    float balance;;
} record;

record adjust(record customer);

int main()
{
    static record customer = {"Talha", 3333, 'C', 33.33};
    printf("%s  %d  %c  %.2f\n",customer.name,customer.acct_no,customer.acct_type,customer.balance);

    customer = adjust(customer);
    printf("%s  %d  %c  %.2f\n",customer.name,customer.acct_no,customer.acct_type,customer.balance);

}

record adjust(record cust)
{
    cust.name = "Jones";
    cust.acct_no = 9999;
    cust.acct_type = 'R';
    cust.balance = 99.99;
    return(cust);
}