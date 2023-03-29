#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "ClientManager.h"

using namespace std;


class BudgetApp{

    UserManager userManager;
    ClientManager *clientManager;

    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

    void displayTheMainMenu();
    void customerMenuDisplay();
    void selectTheOptionInTheCustomerMenu();

public:

    BudgetApp(string userFileName, string incomeFileName, string expenseFileName) : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName){
        clientManager = NULL;
    };

    ~BudgetApp(){
        delete clientManager;
        clientManager = NULL;
    };

    void selectAnOptionInTheMainMenu();

};









#endif // BUDGETAPP_H
