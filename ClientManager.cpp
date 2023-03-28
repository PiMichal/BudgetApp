#include "ClientManager.h"

void ClientManager::addIncomes() {

    system("cls");
    cout << " >>> Add income <<<" << endl << endl;

    Income income = introductionOfNewIncomes();

    incomes.push_back(income);

    /*
    if (plikZadresatami.dopiszAdresataDoPliku(adresat))
        cout << "New income added" << endl;
    else
        cout << "Error. Failed to add new income" << endl;

    system("pause");
    */
}

string ClientManager::dateEntry() {

    string date;
    cout << "Enter date (rrrr-mm-dd): ";
    date = AuxiliaryMethods::loadLine();

    while(!dateValidation.dateCheck(date)) {
        cout << "Incorrect date. Enter again: ";
        date = AuxiliaryMethods::loadLine();
    }

    return date;
}

bool ClientManager::checkNumber(string numberToCheck) {

    int counter = 0;
    if (numberToCheck.size() >= 1) {
        for (int i = 0; i < numberToCheck.size(); i++) {
            if (numberToCheck[i] == '.')
                counter += 1;
        }

    }
    else
        return true;

    if (counter >= 1)
        numberToCheck.erase(find(numberToCheck.begin(), numberToCheck.end(), '.'));

    if (AuxiliaryMethods::is_digits(numberToCheck) && (counter == 0 || counter == 1))
        return false;


    return true;
}

Income ClientManager::introductionOfNewIncomes() {

    Income income;
    income.setUserId(LOGGED_IN_USER_ID);
    char sign;

    cout << "Add with today's date (Y/N) ?: ";
    sign = AuxiliaryMethods::loadCharacter();

    if (sign == 'n' || sign == 'N') {
        income.setDate(dateEntry());
    } else
        income.setDate(dateValidation.currentDate());

    cout << "Enter what the income relates to ?: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Enter the amount of income: ";

    string number = AuxiliaryMethods::loadNumber();

    while(checkNumber(number)) {
        cout << "Invalid number. Try again: ";
        number = AuxiliaryMethods::loadNumber();
    }

    income.setAmount(stof(number));

    return income;
}

