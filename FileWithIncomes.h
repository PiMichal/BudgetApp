#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "Income.h"
#include "Markup.h"
#include "DateValidation.h"
#include "XmlFile.h"

using namespace std;

class FileWithIncomes :public XmlFile{

    CMarkup xml;

public:

    FileWithIncomes(string incomeFileName) : XmlFile(incomeFileName){};

    vector <Income> loadIncomesFromFile();

    void addIncomesToFile(Income income);

};





#endif // FILEWITHINCOMES_H
