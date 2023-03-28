#include <iostream>
#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("users.xml", "incomes.xml", "expenses.xml");

    budgetApp.selectAnOptionInTheMainMenu();

}
