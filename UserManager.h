#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;


class UserManager{

    vector <User> users;
    User enterANewUser();

    bool DoesLoginExist(string login);
    int getNewUserId();

public:

    void userRegistration();

    void printvector();
};











#endif // USERMANAGER_H
