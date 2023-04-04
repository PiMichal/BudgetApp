#include "XmlFile.h"


string XmlFile::getFileName(){

    return FILE_NAME;
}

bool XmlFile::isTheFileEmpty(){

    bool fileExists = xml.Load(FILE_NAME);

    return fileExists;
}

