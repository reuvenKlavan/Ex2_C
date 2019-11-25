#include <stdio.h>
#include "myBank.h"

int main() {

    printf("Welcome to Israel Bank\n"
           
           "* O -- Open a new account\n"
           "* B -- Shows your current balance in your bank account\n"
           "* D -- Shows your updated balance in your bank account after deposit\n"
           "* W -- Shows your updated balance in your bank account after withdraw\n"
           "* C -- Closes and erases your bank account\n"
           "* I -- Adds interest to all of the bank accounts\n"
           "* P -- Prints all the active account numbers and their balance\n"
           "* E -- Closes and erases all bank accounts and exits program\n");
    char operator;
    printf("Please enter your choice: ");
    scanf("%c", & operator);
    switch(operator)
    {
        case 'O':
            printf("Please enter the amount of money you would like to deposit: ");
            double deposit = 0;
            scanf("%lf", &deposit);
            O(deposit);
            break;
        case 'B':
            printf("Please enter your account number: ");
            int account_number = 0;
            scanf("%lf", &account_number);
            B(account_number);
            break;
        case 'D':
            printf("Please enter the amount of money you would like to deposit: ");
            double deposit_1 = 0;
            scanf("%d %lf",account_number, &deposit_1);
            D(account_number, deposit_1);
            break;
        case 'W':
            printf("Please enter the amount of money you would like to withdraw: ");
            double withdraw = 0;
            scanf("%d %lf",account_number, withdraw);
            W(account_number, withdraw);
            break;
        case 'C':
            printf("Please enter the bank account number you would like to erase: ");
            scanf("%d",account_number);
            C(account_number);
            break;
        case 'I':
            printf("Please enter the interest rate you would like to add to all of the accounts: ");
            int interest_rate;
            scanf("%d",interest_rate);
            I(interest_rate);
            break;
        case 'P':
            printf("Printing all of the open accounts information: ");
            P();
            break;
        case 'E':
            printf("Closing and erasing all of the bank accounts, and exits program");
            P();
            printf("Erase succeeded\nGood bey!");
            break;
            // operator doesn't match any case constant
        default:
            printf("Error! operator is not valid");
    }
    return 0;
}