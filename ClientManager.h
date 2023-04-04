#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

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

    struct fromOldestToNewestIncome;
    struct fromOldestToNewstExpenses;

    Income introductionOfNewIncomes();
    Expense introductionOfNewExpenses();

    bool checkNumber(string numberToCheck);
    void balanceOfIncomeAndExpenses(bool balanceThisMonth, bool previousMonthsBalance, bool balanceSheetForTheSelectedPeriod);
    void printingIncomeData(int i);
    void printingExpenseData(int i);



    void differenceInIncomeAndExpenses(float incomes, float expenses);

public:

    ClientManager(int loggedInUserId, string incomeFileName, string expenseFileName) : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(incomeFileName), fileWithExpenses(expenseFileName){
        incomes = fileWithIncomes.loadIncomesFromFile();
        expenses = fileWithExpenses.loadExpensesFromFile();
    };

    int dateEntry();

    void addIncomes();
    void addExpenses();
    void balanceThisMonth();
    void previousMonthsBalance();
    void balanceSheetForTheSelectedPeriod();
};








#endif // CLIENTMANAGER_H
