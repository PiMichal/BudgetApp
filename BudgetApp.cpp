#include "BudgetApp.h"

void BudgetApp::displayTheMainMenu() {

    system ("cls");
    cout << ">>>>> Main menu <<<<<" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "-----------------------" << endl;
    cout << "Your choice: ";

}

void BudgetApp::selectAnOptionInTheMainMenu(){

    while (true) {
        displayTheMainMenu();
        switch (getchar()) {
        case '1':
            userManager.userRegistration();
            break;
        case '2':
            userManager.loginUser();
            if (userManager.getLoggedInUserId() > 0) {
                cout << "WITAM WITAM";
                system("pause");
                //adresatMenadzer = new AdresatMenedzer(plikTekstowy.pobierzNazwePliku(), uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
                //wybierzOpcjeZMenuUzytkownika();
            }

            break;
        case '9':
            exit(0);
            break;
        }
    }
}
