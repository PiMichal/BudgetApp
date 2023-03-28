#include "DateValidation.h"

bool DateValidation::numberOfDaysInTheGivenMonthCheck(string dateEnteredForCheck){

    int baseYearMin = 20000101;
    int baseYearMax = AuxiliaryMethods::convertStringToInteger(dateConversionWithoutDash(currentDate()));

    int date = AuxiliaryMethods::convertStringToInteger(dateConversionWithoutDash(dateEnteredForCheck));

    int convertYearToInt = AuxiliaryMethods::convertStringToInteger(dateEnteredForCheck.substr(0,4));
    int convertMonthToInt = AuxiliaryMethods::convertStringToInteger(dateEnteredForCheck.substr(5,2));
    int convertDayToInt = AuxiliaryMethods::convertStringToInteger(dateEnteredForCheck.substr(8,2));


    if (convertDayToInt <= countTheNumberOfDaysInAGivenMonth(convertYearToInt, convertMonthToInt) && (date >= baseYearMin && date <= baseYearMax))
        return true;

    return false;

}

int DateValidation::countTheNumberOfDaysInAGivenMonth(int year, int month) {

    int numberOfDaysInAGivenMonth = 0;
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 400) || ((year % 100 != 0) && (year % 4 == 0))))
        numberOfDaysInAGivenMonth = arr[month-1]+1;

    else
        numberOfDaysInAGivenMonth = arr[month-1];

    return numberOfDaysInAGivenMonth;

}

string DateValidation::dateConversionWithoutDash(string dateWithDash){

    string dateWithoutDash = "";

    dateWithoutDash = dateWithDash.substr(0,4);
    dateWithoutDash += dateWithDash.substr(5,2);
    dateWithoutDash += dateWithDash.substr(8,2);

    return dateWithoutDash;
}

bool DateValidation::dateCheck(string dateEnteredForCheck) {

    if (dateEnteredForCheck.size() == 10 && AuxiliaryMethods::is_digits(dateConversionWithoutDash(dateEnteredForCheck)) && numberOfDaysInTheGivenMonthCheck(dateEnteredForCheck))
        return true;

    return false;

}

string DateValidation::currentDate() {

    auto t = time(nullptr);
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();

    return str;
}
