#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "User.h"
#include "Markup.h"
#include "XmlFile.h"

using namespace std;


class FileWithUsers :public XmlFile{

    CMarkup xml;


public:

    FileWithUsers(string userFileName, string incomesFileName, string expensesFileName) : XmlFile(userFileName, incomesFileName, expensesFileName){};

    vector <User> loadUsersFromFile();

    void addUserToFile(User user);


};







#endif // FILEWITHUSERS_H
