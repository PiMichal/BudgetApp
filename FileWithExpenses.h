#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "Expense.h"
#include "Markup.h"
#include "DateValidation.h"

using namespace std;


class FileWithExpenses{

    CMarkup xml;

    const string EXPENSE_FILE_NAME;

    bool isTheFileEmpty();

public:

    FileWithExpenses(string expenseFileName) : EXPENSE_FILE_NAME(expenseFileName){};

    vector <Expense> loadExpensesFromFile();

    void addExpensesToFile(Expense expense);
};







#endif // FILEWITHEXPENSES_H
