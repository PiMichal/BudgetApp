#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"
#include "DateValidation.h"

using namespace std;


class ClientManager{

    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
    DateValidation dateValidation;

    const int LOGGED_IN_USER_ID;

    vector <Income> incomes;
    vector <Expense> expenses;

    Income introductionOfNewIncomes();

    string dateEntry();

public:

    ClientManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId){

    };

    void addIncomes();


};








#endif // CLIENTMANAGER_H
