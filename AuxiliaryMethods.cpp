#include "AuxiliaryMethods.h"

string AuxiliaryMethods::removeCharacterFromNumber(string number) {

    number.erase(find(number.begin(), number.end(), '.'));

    return number;
}

bool AuxiliaryMethods::is_digits(string date) {
    return all_of(date.begin(), date.end(), ::isdigit);
}

int AuxiliaryMethods::convertStringToInteger(string number) {

    return stoi(number);
}

float AuxiliaryMethods::convertStringToFloat(string number) {

    return stof(number);
}

string AuxiliaryMethods::loadLine() {

    cin.sync();
    string in = "";

    while (true){
        getline(cin, in);
        if (in.size() > 0)
            break;
    }

    return in;
}

string AuxiliaryMethods::loadNumber() {

    string number = "";
    number = loadLine();

    replace(number.begin(), number.end(), ',', '.');

    return number;
}

string AuxiliaryMethods::convertIntegerToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatToString(float number){

    return to_string(number);
}

char AuxiliaryMethods::loadCharacter() {
    string in = "";
    char character  = {0};

    while (true) {
        in = loadLine();

        if (in.length() == 1) {
            character = in[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return character;
}


