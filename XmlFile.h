#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;


class XmlFile{

    CMarkup xml;
    const string FILE_NAME;


public:

    XmlFile(string fileName) : FILE_NAME(fileName){};

    string getFileName();

    bool isTheFileEmpty();

};






#endif // XMLFILE_H
