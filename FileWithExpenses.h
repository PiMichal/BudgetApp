#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "Expense.h"
#include "Markup.h"
#include "DateValidation.h"
#include "XmlFile.h"

using namespace std;


class FileWithExpenses :public XmlFile{

    CMarkup xml;

public:

    FileWithExpenses(string expenseFileName) : XmlFile(expenseFileName){};

    vector <Expense> loadExpensesFromFile();

    void addExpensesToFile(Expense expense);
};







#endif // FILEWITHEXPENSES_H
