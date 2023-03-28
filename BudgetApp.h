#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "ClientManager.h"

using namespace std;


class BudgetApp{

    UserManager userManager;
    ClientManager *clientManager;

    void displayTheMainMenu();
    void customerMenuDisplay();
    void selectTheOptionInTheCustomerMenu();

public:
    BudgetApp(string userFileName, string incomesFileName, string expensesFileName) : userManager(userFileName, incomesFileName, expensesFileName){
        clientManager = NULL;

    };

    ~BudgetApp(){
        delete clientManager;
        clientManager = NULL;
    };

    void selectAnOptionInTheMainMenu();

};









#endif // BUDGETAPP_H
