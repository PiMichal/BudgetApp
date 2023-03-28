#include "XmlFile.h"

string XmlFile::getUserFileName(){

    return USER_FILE_NAME;
}

string XmlFile::getIncomesFileName(){

    return INCOMES_FILE_NAME;
}

string XmlFile::getExpensesFileName(){

    return EXPENSES_FILE_NAME;
}

bool XmlFile::whetherTheFileIsEmpty(){

    bool fileExists = xml.Load(USER_FILE_NAME);

    return fileExists;

}
