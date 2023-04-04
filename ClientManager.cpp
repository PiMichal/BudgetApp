#include "ClientManager.h"

struct ClientManager::fromOldestToNewestIncome {
    inline bool operator() (Income& i1, Income& i2) {
        return (i1.getDate() < i2.getDate());
    }
};

struct ClientManager::fromOldestToNewstExpenses {
    inline bool operator() (Expense& e1, Expense& e2) {
        return (e1.getDate() < e2.getDate());
    }
};

bool ClientManager::checkNumber(string numberToCheck) {

    int counter = 0;
    int wordLength = 0;

    string numbersAfterTheComma = "";

    if (numberToCheck.size() >= 1) {
        for (int i = 0; i < (int) numberToCheck.size(); i++) {
            if (numberToCheck[i] == '.')
                counter += 1;
        }
    } else
        return true;

    if (counter == 1) {
        numbersAfterTheComma = numberToCheck.substr(numberToCheck.find("."),numberToCheck.size());
        wordLength = numbersAfterTheComma.size();
        numberToCheck.erase(find(numberToCheck.begin(), numberToCheck.end(), '.'));
    }


    if (AuxiliaryMethods::is_digits(numberToCheck) && (counter == 0 || counter == 1) && wordLength <= 3)
        return false;

    return true;
}

int ClientManager::dateEntry() {

    string date;
    cout << "Enter date (rrrr-mm-dd): ";
    date = AuxiliaryMethods::loadLine();

    while(dateValidation.dateCheck(date)) {
        cout << "Incorrect date. Enter again: ";
        date = AuxiliaryMethods::loadLine();
    }

    return DateValidation::dateConversionWithoutDash(date);
}

void ClientManager::addIncomes() {

    system("cls");
    cout << " >>> Add income <<<" << endl << endl;

    Income income = introductionOfNewIncomes();

    incomes.push_back(income);

    fileWithIncomes.addIncomesToFile(income);

    cout << "New income added" << endl;

    system("pause");

}

Income ClientManager::introductionOfNewIncomes() {

    Income income;
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Add with today's date (Y/N) ?: ";

    while (char sign = AuxiliaryMethods::loadCharacter()) {

        if (sign == 'n' || sign == 'N') {
            income.setDate(dateEntry());
            break;

        } else if(sign == 'y' || sign == 'Y') {
            income.setDate(dateValidation.currentDate());
            break;
        }

    };

    cout << "Enter what the income relates to ?: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Enter the amount of income: ";

    string number = AuxiliaryMethods::loadNumber();

    while(checkNumber(number)) {
        cout << "Invalid number. Try again: ";
        number = AuxiliaryMethods::loadNumber();
    }

    income.setAmount(AuxiliaryMethods::convertStringToFloat(number));

    return income;
}

void ClientManager::addExpenses() {

    system("cls");
    cout << ">>> Add expense <<<" << endl << endl;

    Expense expense = introductionOfNewExpenses();

    expenses.push_back(expense);

    fileWithExpenses.addExpensesToFile(expense);

    cout << "New expense added" << endl;

    system("pause");

}

Expense ClientManager::introductionOfNewExpenses() {

    Expense expense;
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Add with today's date (Y/N) ?: ";

    while (char sign = AuxiliaryMethods::loadCharacter()) {
        if (sign == 'n' || sign == 'N') {
            expense.setDate(dateEntry());
            break;
        } else if(sign == 'y' || sign == 'Y') {
            expense.setDate(dateValidation.currentDate());
            break;
        }

    }

    cout << "Enter what the expense relates to ?: ";
    expense.setItem(AuxiliaryMethods::loadLine());

    cout << "Enter the amount of expense: ";

    string number = AuxiliaryMethods::loadNumber();

    while(checkNumber(number)) {
        cout << "Invalid number. Try again: ";
        number = AuxiliaryMethods::loadNumber();
    }

    expense.setAmount(AuxiliaryMethods::convertStringToFloat(number));

    return expense;
}


void ClientManager::differenceInIncomeAndExpenses(float incomes, float expenses) {

    if (incomes>expenses) {
        cout << endl;
        cout << "---------------------------" << endl;
        cout << "Total incomes: " << fixed << setprecision(2) << incomes << endl;
        cout << "Total expenses: " << fixed << setprecision(2) << expenses << endl;
        cout << "Generated savings: " << fixed << setprecision(2) << incomes - expenses << endl;
        cout << "---------------------------" << endl;
    }

    else {
        cout << endl;
        cout << "---------------------------" << endl;
        cout << "Total incomes: " << fixed << setprecision(2) << incomes << endl;
        cout << "Total expenses: " << fixed << setprecision(2) << expenses << endl;
        cout << "Debt generated: " << fixed << setprecision(2) << expenses - incomes << endl;
        cout << "---------------------------" << endl;
    }

}

void ClientManager::printingIncomeData(int i) {

    cout << endl;
    cout << DateValidation::dateToFileConversion(incomes[i].getDate()) << endl;
    cout << incomes[i].getItem() << endl;
    cout << incomes[i].getAmount() << endl;

}

void ClientManager::printingExpenseData(int i) {

    cout << endl;
    cout << DateValidation::dateToFileConversion(expenses[i].getDate()) << endl;
    cout << expenses[i].getItem() << endl;
    cout << expenses[i].getAmount() << endl;

}

void ClientManager::balanceThisMonth() {


    balanceOfIncomeAndExpenses(true, false, false);

}

void ClientManager::previousMonthsBalance() {

    balanceOfIncomeAndExpenses(false, true, false);

}

void ClientManager::balanceSheetForTheSelectedPeriod() {

    system("cls");
    cout << "Since when to show the balance sheet ? " << endl;
    dateValidation.setDateFrom(dateEntry());

    cout << endl;

    cout << "By when to show the balance sheet ? " << endl;
    dateValidation.setDateTo(dateEntry());

    balanceOfIncomeAndExpenses(false, false, true);

}

void ClientManager::balanceOfIncomeAndExpenses(bool balanceThisMonth, bool previousMonthsBalance, bool balanceSheetForTheSelectedPeriod) {

    system("cls");
    float incomeCounter = 0;
    float expensesCounter = 0;

    if (!incomes.empty()) {
        sort(incomes.begin(), incomes.end(), fromOldestToNewestIncome());
        cout << ">>> Incomes <<<" << endl;
        for (int i = 0; i < (int) incomes.size(); i++) {

            if (balanceThisMonth && incomes[i].getUserId() == LOGGED_IN_USER_ID && DateValidation::balanceThisMonth(incomes[i].getDate())) {
                printingIncomeData(i);
                incomeCounter += incomes[i].getAmount();

            } else if (previousMonthsBalance && incomes[i].getUserId() == LOGGED_IN_USER_ID && DateValidation::previousMonthsBalance(incomes[i].getDate())) {
                printingIncomeData(i);
                incomeCounter += incomes[i].getAmount();

            } else if (balanceSheetForTheSelectedPeriod && incomes[i].getUserId() == LOGGED_IN_USER_ID && dateValidation.balanceSheetForTheSelectedPeriod(incomes[i].getDate())) {
                printingIncomeData(i);
                incomeCounter += incomes[i].getAmount();
            }
        }
    }
    if (!expenses.empty()) {
        sort(expenses.begin(), expenses.end(), fromOldestToNewstExpenses());
        cout << endl;
        cout << ">>> Expenses <<<" << endl;
        for (int i = 0; i < (int) expenses.size(); i++) {

            if (balanceThisMonth && expenses[i].getUserId() == LOGGED_IN_USER_ID && DateValidation::balanceThisMonth(expenses[i].getDate())) {
                printingExpenseData(i);
                expensesCounter += expenses[i].getAmount();

            } else if (previousMonthsBalance && expenses[i].getUserId() == LOGGED_IN_USER_ID && DateValidation::previousMonthsBalance(expenses[i].getDate())) {
                printingExpenseData(i);
                expensesCounter += expenses[i].getAmount();

            } else if (balanceSheetForTheSelectedPeriod && expenses[i].getUserId() == LOGGED_IN_USER_ID && dateValidation.balanceSheetForTheSelectedPeriod(expenses[i].getDate())) {
                printingExpenseData(i);
                expensesCounter += expenses[i].getAmount();
            }
        }
    }

    if (!incomes.empty() || !expenses.empty())
        differenceInIncomeAndExpenses(incomeCounter, expensesCounter);

    else
        cout << "Incomes and expenses are empty.";

    system("pause");
}


