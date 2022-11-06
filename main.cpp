#include <iostream>
#include "Client.h"
#include "BankAccount.h"
#include "SavingAccount.h"
#include "BankApplication.h"
using namespace std;
int main() {
    BankApplication bankSystem;
    bankSystem.run();

   // SavingAccount account("100",100);

    //Client c("ISMAIL","CAIRO","01157077022",&account);

    //    c.displayInfo();
    return 0;
}
