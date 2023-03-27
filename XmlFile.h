#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;


class XmlFile{

    CMarkup xml;
    const string FILENAME;


public:

    XmlFile(string userFileName) : FILENAME(userFileName){};

    string getFileName();
    bool whetherTheFileIsEmpty();


};






#endif // XMLFILE_H
