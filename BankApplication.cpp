//
// Created by Ismail Magdy on 04/11/2022.
//

#include "BankApplication.h"
// next ID to be used
int BankApplication::nextID = 202100;

// Choices
int BankApplication::CreateNewAccount = 1;
int BankApplication::ListAllUsers = 2;
int BankApplication::Withdraw = 3;
int BankApplication::Deposit = 4;
int BankApplication::EXIT = 5;

int BankApplication::MinDepositAmount = 100;
int BankApplication::MinSavingBalance = 1000;

BankApplication::BankApplication() {}

BankApplication::~BankApplication() {
    // deallocating memory
    for(const auto& i:accounts){
        delete i;
    }
    for(const auto& i:clients ){
        delete i;
    }
}

void BankApplication::run() {
    while (true){
        cout<<"---------------------------------------------------\n";
        welcomeMessage();
        int mainMenuChoice = mainMenu();
        if(mainMenuChoice == EXIT)
            break;
        performChoice(mainMenuChoice);

    }
}

void BankApplication::welcomeMessage()const{
    cout<<"Welcome to FCAI Banking application\n";
}

int BankApplication::mainMenu()const{
    // display menu
    int choice = -1;
    while (choice != CreateNewAccount && choice != ListAllUsers && choice != Withdraw && choice != Deposit && choice!= EXIT){
        cout<<"1-Create new Account\n";
        cout<<"2-List all Clients and accounts\n";
        cout<<"3-Withdraw\n";
        cout<<"4-Deposit\n";
        cout<<"5-EXIT\n";
        cout<<"Please Enter Choice =========>";
        cin>>choice;
    }
    return choice;
}

void BankApplication::performChoice(const int& choice){
    // perform operation chosen
    if(choice == CreateNewAccount){
        addAccount();
        nextID++;
    }
    else if(choice == ListAllUsers){
        listAllAccounts();
    }
    else if(choice == Withdraw){
        withdraw();
    }
    else if(choice == Deposit){
        deposit();
    }
}

void BankApplication::addAccount(){
    // create new client and new account and store them in the system
    createNewClient();
}

void BankApplication::listAllAccounts()const{
    // display all clients Information stored
    for(const auto& i:clients){
        cout<<"---------------------------------------------------\n";
        i->displayInfo();
    }
}

void BankApplication::withdraw(){
    // get account ID to be deposited in
    string ID ;
    cout<<"Please Enter your account ID =========>";
    cin>>ID;

    // search for account with this ID
    BankAccount* account = findAccount(ID);

    // no such account with this  is stored in the system
    if(account == nullptr){
        cout<<"Account not found\n";
        return;
    }
    account->displayInfo();

    // get account to be deposited
    double amount;
    cout<<"please Enter the amount to be withdrawn =========>";
    cin>>amount;

    // handle saving accounts deposits
    if(dynamic_cast<SavingAccount*>(account) != nullptr){ // check if account is of type  (saving account)
        while (amount<=0){
            cout<<"Sorry cannot withdraw amount less than 0\n";
            cout<<"please Enter the amount to be withdrawn =========>";
            cin>>amount;
        }
        while (account->getBalance() - amount <MinSavingBalance ){
            cout<<"Sorry this is more than you can withdraw , Saving account must have  at least "<<MinSavingBalance<<"L.E. in Balance \n";
            cout<<"please Enter the amount to be deposited =========>";
            cin>>amount;
        }
    }
    else{
        // verify amount to be deposited
        while (amount <= 0){
            cout<<"Sorry cannot withdraw amount less than 0\n";
            cout<<"please Enter the amount to be withdrawn =========>";
            cin>>amount;
        }

        while (account->getBalance() < amount ){
            cout<<"Sorry this is more than you can withdraw\n";
            cout<<"please Enter the amount to be withdrawn =========>";
            cin>>amount;
        }
    }

    // perform transaction
    account->withdraw(amount);

    // display account Info after Transaction
    account->displayInfo();

}

void BankApplication::deposit(){
    // get account ID to be deposited in
    string ID ;
    cout<<"Please Enter your account ID =========>";
    cin>>ID;

    // search for account with this ID
    BankAccount* account = findAccount(ID);

    // no such account with this  is stored in the system
    if(account == nullptr){
        cout<<"Account not found\n";
        return;
    }

    // display account Info before transaction
    account->displayInfo();

    // get account to be deposited
    double amount;
    cout<<"please Enter the amount to be withdrawn =========>";
    cin>>amount;

    // verify amount to be deposited

    // handle saving accounts deposits
    if(dynamic_cast<SavingAccount*>(account) != nullptr){ // check if account is of type  (saving account)
        while (amount < MinDepositAmount){
            if(amount <= 0){
                cout<<"Sorry cannot deposit amount less than 0\n";
                cout<<"please Enter the amount to be deposited =========>";
            }
            else{
                cout<<"Sorry  cannot deposit amount less than "<<MinDepositAmount<<" into a SavingAccount\n";
                cout<<"please Enter the amount to be deposited =========>";
            }
            cin>>amount;
        }
    }
    else{
        while (amount <= 0){
            cout<<"Sorry cannot deposit amount less than 0\n";
            cout<<"please Enter the amount to be deposited =========>";
            cin>>amount;
        }
    }

    // perform transaction
    account->deposit(amount);

    // display account Info after Transaction
    account->displayInfo();
}


void BankApplication::createNewClient(){
    // get client personal Info
    string name;
    cout<<"please Enter Client name =========>";
    cin>>name;

    string address;
    cout<<"please Enter Address =========>";
    cin>>address;

    string phoneNumber;
    cout<<"please Enter your phone number =========>";
    cin>>phoneNumber;

    // create a new account for the client
    BankAccount* account = creatNewAccount();

    // create and store the new client Info
    Client* newClient  = new Client(name,address,phoneNumber,account);
    clients.push_back(newClient);
}

BankAccount *BankApplication::creatNewAccount(){

    // create new account with new ID
    string ID = to_string(nextID);

    // determine  account type
    int type;
    cout<<"please Enter accountType (1)Basic (2)Saving =========>";
    cin>>type;

    // determine account initial balance
    double balance;
    cout<<"please Enter Starting Balance =========>";
    cin>>balance;

    BankAccount* newAccount = nullptr;

    // create new account of the chosen type
    if(type == 1)
        newAccount = new BankAccount(ID, balance);
    else
        newAccount = new SavingAccount(ID, balance);

    // store new account
    accounts.push_back(newAccount);

    return  newAccount;
}

BankAccount *BankApplication::findAccount(const string &ID)const{
    // search for the a specific account with certain ID in accounts stored
    for(const auto& i:accounts){
        if(i->getID() == ID){
            return i;
        }
    }
    return nullptr;
}
