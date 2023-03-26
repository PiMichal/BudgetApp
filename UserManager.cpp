#include "UserManager.h"

void UserManager::userRegistration() {
    system("cls");
    User user = enterANewUser();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "The account has been successfully created" << endl << endl;
    system("pause");
}

User UserManager::enterANewUser() {

    User user;
    user.setUserId(getNewUserId());

    string login;
    do {
        cout << "Enter login: ";
        login = AuxiliaryMethods::loadLine();
        user.setLogin(login);

    } while (DoesLoginExist(user.getLogin()));

    string password;
    cout << "Enter password: ";
    password = AuxiliaryMethods::loadLine();
    user.setPassword(password);

    string name;
    cout << "Enter name: ";
    name = AuxiliaryMethods::loadLine();
    user.setName(name);

    string surname;
    cout << "Enter surname: ";
    surname = AuxiliaryMethods::loadLine();
    user.setSurname(surname);

    return user;
}

bool UserManager::DoesLoginExist(string login)
{

   for (int i = 0; i < (int) users.size(); i++){
        if (users[i].getLogin() == login)
        {
            cout << "There is a user with this login !" << endl;
            return true;
        }
   }
    return false;
}

int UserManager::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::printvector(){
    for (int i = 0; i < (int) users.size(); i++){
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
    system("pause");

}
