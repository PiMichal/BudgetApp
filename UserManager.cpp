#include "UserManager.h"

void UserManager::setLoggedInUserId(int newIdOfTheLoggedInUser){
    idOfTheLoggedInUser = newIdOfTheLoggedInUser;
}

int UserManager::getLoggedInUserId(){
    return idOfTheLoggedInUser;
}

void UserManager::userRegistration() {
    system("cls");
    User user = enterANewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

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

int UserManager::loginUser()
{
    system("cls");
    User user;
    string login = "", password = "";

    cout << "Enter login: ";
    login = AuxiliaryMethods::loadLine();

    for (int i = 0; i < (int) users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfTrials = 3; numberOfTrials > 0; numberOfTrials--)
            {
                cout << "Enter password. Attempt: " << numberOfTrials << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");

                    return idOfTheLoggedInUser = users[i].getUserId();
                }
            }
            cout << "The wrong password was entered 3 times." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    return 0;
}
