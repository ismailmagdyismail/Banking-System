//
// Created by Ismail Magdy on 04/11/2022.
//

#ifndef BANKING_SYSTEM_SAVINGACCOUNT_H
#define BANKING_SYSTEM_SAVINGACCOUNT_H
#include "BankAccount.h"

class SavingAccount:public BankAccount{
public:
    // constructor
    SavingAccount(const string& ID,const double& amount);
    virtual ~SavingAccount() = default;

    // overridden transaction
    virtual void withdraw(const double& amount)override;
    virtual void deposit(const double& amount)override;

    // displaying information
    virtual void displayInfo()const override;

private:
    static double minimumBalance;       // minimum balance account can hold
    static double minimumDepositAmount;// minimum amount to be deposited
};


#endif //BANKING_SYSTEM_SAVINGACCOUNT_H
