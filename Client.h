//
// Created by Ismail Magdy on 04/11/2022.
//

#ifndef BANKING_SYSTEM_CLIENT_H
#define BANKING_SYSTEM_CLIENT_H
#include "SavingAccount.h"
#include "BankAccount.h"
#include <iostream>

using namespace std;

class Client{
public:
    // constructors
    Client(const string& name, const string& address, const string& phoneNumber , BankAccount*);

    // getters
    string getName()const;
    string getAddress()const;
    string getPhoneNumber()const;
   /// BankAccount* getAccount()const; i think we should not use this

    // displaying info
    void displayInfo()const;

private:
    string name;
    string address;
    string phoneNumber;
    BankAccount* account;
};


#endif //BANKING_SYSTEM_CLIENT_H
