#include <stdio.h>
#include "myBank.h"

static double accounts [2][50]; //[0]- current cash flow. [1]- boolean occupied.

// Opens a new bank account
void O(double amount){
    for (int i = 0; i < 50; ++i) {
            if (accounts[1][i] == 0) {
                accounts[1][i] = 1;
                accounts[0][i] = amount;
                printf("The new account number is: %d \n", i + 901);
                break;

        }
    }
}

// Shows the current balance in the bank account
void B(int account_number) {
    if (accounts[1][account_number-901] == 1) {
        printf("The current balance in account %d is: %0.2f\n", account_number, accounts[0][account_number-901] );
    }
}

// Shows the new balance in the bank account after deposit
void D (int account_number, double deposit) {
    if (accounts[1][account_number-901] == 1){
        accounts[0][account_number-901] += deposit;
        printf("The new balance after deposit in account %d is: %0.2f\n", account_number, accounts[0][account_number-901] );
    }
}

// Shows the new balance in the bank account after withdraw
void W(int account_number, double withdraw){
    if (accounts[1][account_number-901] == 1){
        if (accounts[0][account_number-901] >= withdraw){
            accounts[0][account_number-901] -= withdraw;
            printf("The new balance after withdraw in account %d is: %0.2f\n", account_number, accounts[0][account_number-901] );
        }
    }else printf("The current bank account is not active\n");
}

// Closes the bank account
void C(int account_number){
    if (accounts[1][account_number-901] == 1) {
        accounts[0][account_number-901] = 0;
        accounts[1][account_number-901] = 0;
    }
}

// Adds interest to all of the bank accounts
void I(int interest_rate){
    for (int i = 0; i < 50; ++i) {
        if (accounts[1][i] == 1) {
            accounts[0][i] += ((interest_rate * accounts[0][i]) /100);
        }
    }
}

// Prints all the active account numbers and their balance
void P(){
    for (int i = 0; i < 50; ++i) {
        if (accounts[1][i] == 1) {
            B(i+901);
        }
    }
}

// Closes all bank accounts and exits program
void E(){
    for (int i = 0; i < 50; ++i) {
        if (accounts[1][i] == 1) {
            C(i+901);
        }
    }
}

int main() {
    O(2); // O tester
    B(901); // B tester
    D(901,2.4); // D test
    W(901, 2.1); // W test
    C(901); // C test
    W(901, 2.1); // C test
    O(81);
    O(82);
    O(83);
    O(84);
    C(903);
    O(85);
    O(86);
    C(906);
    O(87);
    O(88);
    P();
    W(901,5);
    I(25);
    P();
    return 0;
}