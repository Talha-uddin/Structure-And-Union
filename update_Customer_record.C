#include<stdio.h>

typedef struct{
    int month;
    int day;
    int year;
} date;

typedef struct{
    char name[20];
    char street[30];
    char city[50];
    int acct_no;
    char acct_type;
    float oldbalance;
    float newbalance;
    float payment;
    date lastpayment;
} record;

record readinput(int i);
void writeoutput(record customer);

int main()
{
    int i,n;
    record customer[100];

    printf("CUSTOMER BILLING SYSTEM\n\n");
    printf("How many customers are there? ");
    scanf("%d",&n);

    for(i=0; i<n; ++i)
    {
         readinput[i];

        if(customer[i].payment > 0){
            customer[i].acct_type = (customer[i].payment< 0.1 * customer[i].oldbalance) ? 'O' : 'C';
        }
        else{
            customer[i].acct_type = (customer[i].oldbalance > 0) ? 'D' : 'C';
        }
        customer[i].newbalance = customer[i].oldbalance - customer[i].payment;
    }
    for(i=0; i<n; ++i){
        writeoutput(customer[i]);
    }
}

record readinput(int i)
{
    printf("Customer no. %d\n",i+1);
    printf("\tName: ");
    scanf(" %[^\n]",customer.name);
    printf("\tStreet: ");
    scanf(" %[^\n]",customer.street);
    printf("\tCity: ");
    scanf(" %[^\n]",customer.city);
    printf("\tAccount Number: ");
    scanf("%d",&customer.acct_no);
    printf("\tPrevious balance: ");
    scanf("%f",&customer.oldbalance);
    printf("\tCurrent payment: ");
    scanf("%f",&customer.payment);
    printf("\tPayment Date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
    return(customer);
}

void writeoutput(record customer)
{
    printf("\nName:\t %s",customer.name);
    printf("'\tAccount Number: %d\n",customer.acct_no);
    printf("Street: %s\n",customer.street);
    printf("City: %s\n\n",customer.city);
    printf("Old Balance: %7.2f",customer.oldbalance);
    printf("\tCurrent Balance: %7.2f",customer.payment);
    printf("\tNew Balance: %7.2f\n\n",customer.newbalance);
    printf("Account Status: ");

    switch(customer.acct_no)
    {
        case 'C': printf("CURRENT\n\n");
        break;
        case 'O': printf("OVERDUE\n\n");
        break;
        case 'D': printf("DELINQUENT\n\n");
        break;
        default: printf("ERROR\n\n");
    }
    return;
}