#include<stdio.h>
#include<string.h>
#include<ctype.h>

void readinput(int);
void writeoutput(int i);

struct date{
    int month;
    int day;
    int year;
};

struct account{
    char name[50];
    char street[80];
    char city[50];
    int acct_no;
    char acct_type;
    float oldbalance;
    float newbalance;
    float payment;
    struct date lastpayment;
}customer[100];

int main()
{
    int i,n;

    printf("CUSTOMER BILLING SYSTEM\n\n");
    printf("How many customers are there? ");
    scanf("%d",&n);

    for(i=0; i<n; i++){
        readinput(i);

        if(customer[i].payment>0){
            customer[i].acct_type = (customer[i].payment < 0.1 * customer[i].oldbalance) ?  '0'  :  'C';
        }
        else{   
            customer[i].acct_type = (customer[i].oldbalance > 0)  ?  'D'  :  'C';
        }
        
        customer[i].newbalance = customer[i].oldbalance - customer[i].payment;
    };
    for(i=0; i<n; i++){
        writeoutput(i);
    }
}

void readinput(int i)
{
    printf("\nCustomer no. %d\n",i+1);
    printf("\tName: ");
    scanf(" %[^\n]",customer[i].name);
    printf("\tStreet: ");
    scanf(" %[^\n]",customer[i].street);
    printf("\tCity: ");
    scanf(" %[^\n]",customer[i].city);
    printf("\tAccount Number: ");
    scanf("%d",&customer[i].acct_no);
    printf("\tPrevious Balance: ");
    scanf("%f",&customer[i].oldbalance);
    printf("\tCurrent Payment: ");
    scanf("%f",&customer[i].payment);
    printf("\tPayment date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&customer[i].lastpayment.month,&customer[i].lastpayment.day,&customer[i].lastpayment.year);
    return;
}

void writeoutput(int i)
{
    printf("\nName:\t %s\n",customer[i].name);
    printf("    Account Number:\t %d\n",customer[i].acct_no);
    printf("Street:\t %s\n",customer[i].street);
    printf("City:\t %s\n",customer[i].city);
    printf("Old Balance:\t %7.2f",customer[i].oldbalance);
    printf("  Current Payment:\t %7.2f",customer[i].payment);
    printf("  New Balance:\t %7.2f\n\n",customer[i].newbalance);
    printf("Account Status: ");

    switch(customer[i].acct_type){
        case 'C': 
                printf("Current\n\n");
                break;
        case 'O': 
                printf("OVERDUE\n\n");
                break;
        case 'D': 
                printf("DELINQUENT\n\n");
                break;
        default: 
                printf("ERROR\n\n");
    }
    return;
}