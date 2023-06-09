#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {

    if (!isTheFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(getFileName());
    xml.ResetPos();

}

vector <User> FileWithUsers::loadUsersFromFile() {

    User user;
    vector <User> users;

    if (xml.Load(getFileName())) {
        xml.FindElem("Users");
        xml.IntoElem();

        while (xml.FindElem("User")) {

            xml.IntoElem();
            xml.FindElem("UserId");
            user.setUserId(AuxiliaryMethods::convertStringToInteger(xml.GetData()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());
            users.push_back(user);
            xml.OutOfElem();
        }
    }
    xml.ResetPos();
    return users;
}

void FileWithUsers::changeUserPasswordOnFile(int idOfTheLoggedInUser, string newPassword) {


    xml.FindElem("Users");
    xml.IntoElem();

    while (xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("UserId");

        if (AuxiliaryMethods::convertStringToInteger(xml.GetData()) == idOfTheLoggedInUser){
            xml.FindElem("Login");
            xml.FindElem("Password");
            xml.SetData(newPassword);
            break;
        }
            xml.OutOfElem();
    }
    xml.Save(getFileName());
    xml.ResetPos();
}
