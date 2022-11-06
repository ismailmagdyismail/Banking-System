//
// Created by Ismail Magdy on 04/11/2022.
//

#ifndef BANKING_SYSTEM_BANKACCOUNT_H
#define BANKING_SYSTEM_BANKACCOUNT_H

#include <iostream>

using namespace std;

class BankAccount {
public:

    // constructor
    BankAccount(const string& ID, const double& balance = 0 );
    // destructor
    virtual ~BankAccount() = default;

    // getters
    string getID()const;
    double getBalance() const;

    // account transactions
    virtual void withdraw(const double& amount);
    virtual void deposit(const double& amount);

    // displaying Info
    virtual void displayInfo()const;

private:
    string accountID;
    double balance;
};


#endif //BANKING_SYSTEM_BANKACCOUNT_H
