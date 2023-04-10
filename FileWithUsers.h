#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "User.h"
#include "XmlFile.h"

using namespace std;


class FileWithUsers :public XmlFile{


public:

    FileWithUsers(string userFileName) : XmlFile(userFileName){};
    vector <User> loadUsersFromFile();

    void addUserToFile(User user);
    void changeUserPasswordOnFile(int idOfTheLoggedInUser, string newPassword);

};







#endif // FILEWITHUSERS_H
