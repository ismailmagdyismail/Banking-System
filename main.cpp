#include <iostream>
#include "Client.h"
#include "BankAccount.h"
#include "SavingAccount.h"
#include "BankApplication.h"
using namespace std;
int main() {
    BankApplication bankSystem;
    bankSystem.run();

    return 0;
}
