#include "AuxiliaryMethods.h"



int AuxiliaryMethods::convertStringToInteger(string number) {

    int convertedNumber = stoi(number);
    return convertedNumber;

}

string AuxiliaryMethods::convertIntegerToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine() {
    cin.sync();
    string in = "";
    getline(cin, in);
    return in;
}

char AuxiliaryMethods::loadCharacter()
{
    string in = "";
    char character  = {0};

    while (true)
    {
        in = loadLine();

        if (in.length() == 1)
        {
            character = in[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return character;
}


