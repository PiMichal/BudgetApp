#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "User.h"
#include "Markup.h"

using namespace std;


class FileWithUsers{

    CMarkup xml;

    const string USER_FILE_NAME;

    bool isTheFileEmpty();


public:

    FileWithUsers(string userFileName) : USER_FILE_NAME(userFileName){};
    vector <User> loadUsersFromFile();

    void addUserToFile(User user);


};







#endif // FILEWITHUSERS_H
