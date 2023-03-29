#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "Income.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes{

    CMarkup xml;

    const string INCOME_FILE_NAME;

    bool isTheFileEmpty();

public:

    FileWithIncomes(string incomeFileName) : INCOME_FILE_NAME(incomeFileName){};

    vector <Income> loadIncomesFromFile();

    void addIncomesToFile(Income income);

};





#endif // FILEWITHINCOMES_H
