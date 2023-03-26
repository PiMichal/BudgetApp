#include "AuxiliaryMethods.h"

int AuxiliaryMethods::convertStringToInteger(string number){

    int convertedNumber = stoi(number);
    return convertedNumber;

}

string AuxiliaryMethods::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine()
{
    cin.sync();
    string in = "";
    getline(cin, in);
    return in;
}

