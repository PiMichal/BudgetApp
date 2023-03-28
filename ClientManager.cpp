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

    while(!dateValidation.dateCheck(date)){
        cout << "Incorrect date. Enter again: ";
        date = AuxiliaryMethods::loadLine();
    }

    return date;
}

Income ClientManager::introductionOfNewIncomes() {

    Income income;
    income.setUserId(LOGGED_IN_USER_ID);
    char sign;

    cout << "Add with today's date (Y/N) ?" << endl;
    sign = AuxiliaryMethods::loadCharacter();

    if (sign == 'n' || sign == 'N') {
        income.setDate(dateEntry());
    } else
        income.setDate(dateValidation.currentDate());
/*
        cout << "Podaj imie: ";
        adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
        adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

        cout << "Podaj nazwisko: ";
        adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
        adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

        cout << "Podaj numer telefonu: ";
        adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

        cout << "Podaj email: ";
        adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

        cout << "Podaj adres: ";
        adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

        return income;
*/
}

