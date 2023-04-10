#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods{


    static string removeCharacterFromNumber(string number);

public:

    static bool is_digits(string date);
    static bool checkNumber(string numberToCheck);

    static int convertStringToInteger(string number);

    static float convertStringToFloat(string number);

    static string loadNumber();
    static string loadLine();
    static string convertIntegerToString(int number);
    static string convertFloatToString(float number);

    static char loadCharacter();


};



#endif // AUXILIARYMETHODS_H
