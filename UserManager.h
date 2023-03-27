#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithUsers.h"

using namespace std;


class UserManager{

    FileWithUsers fileWithUsers;
    vector <User> users;
    User enterANewUser();

    bool DoesLoginExist(string login);
    int getNewUserId();

public:

    UserManager(string userFileName) : fileWithUsers(userFileName){

        users = fileWithUsers.loadUsersFromFile();
    };

    void userRegistration();

    void printvector();
};











#endif // USERMANAGER_H
