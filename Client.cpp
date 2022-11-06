//
// Created by Ismail Magdy on 04/11/2022.
//

#include "Client.h"

Client::Client(const string &name, const string &address, const string &phoneNumber, BankAccount* account) {
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->account = account;
}

string Client::getName() const {
    return this->name;
}

string Client::getAddress() const {
    return this->address;
}

string Client::getPhoneNumber() const {
    return this->phoneNumber;
}

///BankAccount* Client::getAccount() const { /// should it be removed for better encapsulation , data Hiding??
   /// return account;
///}

void Client::displayInfo() const {
    cout<<"Client Name:"<<getName()<<'\n';
    cout<<"Client Address:"<<getAddress()<<'\n';
    account->displayInfo();
}
