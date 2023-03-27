#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"

using namespace std;


class BudgetApp{

    UserManager userManager;

    void displayTheMainMenu();

public:
    BudgetApp(string userFileName) : userManager(userFileName){};

    void selectAnOptionInTheMainMenu();

};









#endif // BUDGETAPP_H
