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
                clientManager = new ClientManager(userManager.getLoggedInUserId(), INCOME_FILE_NAME, EXPENSE_FILE_NAME);
                selectTheOptionInTheCustomerMenu();
            }
            break;
        case '9':
            exit(0);
            break;
        }
    }
}

void BudgetApp::customerMenuDisplay() {

    system("cls");
    cout << " >>> MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add incomes" << endl;
    cout << "2. Add expenses" << endl;
    cout << "3. Balance this month" << endl;
    cout << "4. Previous month's balance" << endl;
    cout << "5. Balance sheet for the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}

void BudgetApp::selectTheOptionInTheCustomerMenu() {

    bool logOut = true;
    while(logOut) {
        customerMenuDisplay();
        switch (getchar()) {
        case '1':
            clientManager -> addIncomes();
            break;
        case '2':
            clientManager -> addExpenses();
            break;
        case '3':
            clientManager -> balanceThisMonth();
            break;
        case '4':
            clientManager -> previousMonthsBalance();
            break;
        case '5':
            clientManager -> balanceSheetForTheSelectedPeriod();
            break;
        case '6':
            //adresatMenadzer->edytujAdresata();
            break;
        case '9':
            logOut = false;
            userManager.setLoggedInUserId(0);
            delete clientManager;
            clientManager = NULL;
            break;
        }
    }
}
