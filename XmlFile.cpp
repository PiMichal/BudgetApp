#include "XmlFile.h"

string XmlFile::getFileName(){

    return FILENAME;

}

bool XmlFile::whetherTheFileIsEmpty(){

    bool fileExists = xml.Load(FILENAME);

    return fileExists;

}
