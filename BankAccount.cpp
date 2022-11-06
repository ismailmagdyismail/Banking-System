//
// Created by Ismail Magdy on 04/11/2022.
//

#include "BankAccount.h"


BankAccount::BankAccount(const string& ID, const double &balance) {
    if(balance>=0)
        this->balance = balance;
    else
        this->balance = 0 ;
    this->accountID = ID;
}

string BankAccount::getID()const{
    return this->accountID;
}

double BankAccount::getBalance()const{
    return this->balance;
}


void BankAccount::withdraw(const double &amount) {
    if(amount<=balance)
        this->balance -= amount;
}

void BankAccount::deposit(const double &amount) {
    this->balance += amount;
}

void BankAccount::displayInfo() const {
    cout<<"Account Id:"<<getID()<<'\n';
    cout<<"Account Type:Basic Account\n";
    cout<<"Account Balance:"<<getBalance()<<'\n';
}
