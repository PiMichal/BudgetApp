#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"

using namespace std;


class BudgetApp{

    UserManager userManager;

    void displayTheMainMenu();

public:

    void selectAnOptionInTheMainMenu();

};









#endif // BUDGETAPP_H
