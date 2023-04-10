#include "AuxiliaryMethods.h"

string AuxiliaryMethods::removeCharacterFromNumber(string number) {

    number.erase(find(number.begin(), number.end(), '.'));

    return number;
}

bool AuxiliaryMethods::is_digits(string date) {
    return all_of(date.begin(), date.end(), ::isdigit);
}

bool AuxiliaryMethods::checkNumber(string numberToCheck) {

    int counter = 0;
    int wordLength = 0;

    string numbersAfterTheComma = "";

    if (numberToCheck.size() >= 1) {
        for (int i = 0; i < (int) numberToCheck.size(); i++) {
            if (numberToCheck[i] == '.')
                counter += 1;
        }
    } else
        return true;

    if (counter == 1) {
        numbersAfterTheComma = numberToCheck.substr(numberToCheck.find("."),numberToCheck.size());
        wordLength = numbersAfterTheComma.size();
        numberToCheck.erase(find(numberToCheck.begin(), numberToCheck.end(), '.'));
    }


    if (is_digits(numberToCheck) && (counter == 0 || counter == 1) && wordLength <= 3)
        return false;

    return true;
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


