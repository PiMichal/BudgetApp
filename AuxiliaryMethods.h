#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class AuxiliaryMethods{



public:


    static int convertStringToInteger(string number);

    static string convertIntegerToString(int number);
    static string loadLine();

    static char loadCharacter();

};



#endif // AUXILIARYMETHODS_H
