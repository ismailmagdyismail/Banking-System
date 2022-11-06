//
// Created by Ismail Magdy on 04/11/2022.
//

#ifndef BANKING_SYSTEM_BANKAPPLICATION_H
#define BANKING_SYSTEM_BANKAPPLICATION_H

#include <iostream>
#include "Client.h"
#include "SavingAccount.h"
#include "BankAccount.h"
#include <vector>

using namespace std;

class BankApplication {
public:
     BankApplication();
    ~BankApplication();
    void run();
private:

    static  int nextID ;

    /// dataBase
    vector<Client*>clients;
    vector<BankAccount*>accounts;

    // choices
    static int CreateNewAccount;
    static int ListAllUsers;
    static int Withdraw;
    static int Deposit;
    static int EXIT;

    static int MinDepositAmount;
    static int MinSavingBalance;

    void welcomeMessage()const;
    int  mainMenu()const;
    void performChoice(const int& choice);
    void deposit();
    void withdraw();
    void addAccount();
    void listAllAccounts()const;

    void  createNewClient(); // utility function
    BankAccount* creatNewAccount();// utility function
    BankAccount* findAccount(const string &ID)const;// utility function


};


#endif //BANKING_SYSTEM_BANKAPPLICATION_H
