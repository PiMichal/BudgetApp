#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;


class XmlFile{

    CMarkup xml;
    const string USER_FILE_NAME;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:

    XmlFile(string userFileName, string incomesFileName, string expensesFileName) : USER_FILE_NAME(userFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName){};

    string getUserFileName();
    string getIncomesFileName();
    string getExpensesFileName();
    bool whetherTheFileIsEmpty();


};






#endif // XMLFILE_H
