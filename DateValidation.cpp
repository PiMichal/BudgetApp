#include "DateValidation.h"

void DateValidation::setDateFrom(int newDateFrom) {
    dateFrom = newDateFrom;
}

void DateValidation::setDateTo(int newDateTo) {
    dateTo = newDateTo;
}

bool DateValidation::numberOfDaysInTheGivenMonthCheck(string dateEnteredForCheck) {

    const int baseDateMin = 20000101;
    const int baseMonth = 12;
    int baseDateMax = currentDate();

    int date = dateConversionWithoutDash(dateEnteredForCheck);

    int month = AuxiliaryMethods::convertStringToInteger(dateEnteredForCheck.substr(5,2));
    int day = AuxiliaryMethods::convertStringToInteger(dateEnteredForCheck.substr(8,2));

    if (day <= countTheNumberOfDaysInAGivenMonth(dateEnteredForCheck) && (date >= baseDateMin && date <= baseDateMax) && month <= baseMonth)
        return true;

    return false;

}

bool DateValidation::balanceThisMonth(int date) {

    string todaysYearAndMonth = AuxiliaryMethods::convertIntegerToString(currentDate()).substr(0,6);
    string yearAndMonthToCheck = AuxiliaryMethods::convertIntegerToString(date).substr(0,6);

    if (todaysYearAndMonth == yearAndMonthToCheck)
        return true;

    return false;

}

bool DateValidation::previousMonthsBalance(int date) {

    string todaysYear = AuxiliaryMethods::convertIntegerToString(currentDate()).substr(0,4);
    string todayMonth = AuxiliaryMethods::convertIntegerToString(currentDate()).substr(5,2);
    int temp = 0;

    if (AuxiliaryMethods::convertStringToInteger(todayMonth) >= 10) {
        temp = AuxiliaryMethods::convertStringToInteger(todayMonth) - 1;
        todayMonth = AuxiliaryMethods::convertIntegerToString(temp);
    } else if (AuxiliaryMethods::convertStringToInteger(todayMonth) >= 2) {
        temp = AuxiliaryMethods::convertStringToInteger(todayMonth) - 1;
        todayMonth = AuxiliaryMethods::convertIntegerToString(temp);
        todayMonth = "0" + todayMonth;
    } else {
        temp = 12;
        todayMonth = AuxiliaryMethods::convertIntegerToString(temp);
    }

    string todaysYearAndMonth = todaysYear + todayMonth;
    string yearAndMonthToCheck = AuxiliaryMethods::convertIntegerToString(date).substr(0,6);

    if (todaysYearAndMonth == yearAndMonthToCheck)
        return true;

    return false;

}

bool DateValidation::balanceSheetForTheSelectedPeriod(int date){

    if (dateFrom <= date && dateTo >= date)
        return true;

    return false;

}

int DateValidation::countTheNumberOfDaysInAGivenMonth(string dateEnteredForCheck) {

    int numberOfDaysInAGivenMonth = 0;
    int year = AuxiliaryMethods::convertStringToInteger(dateEnteredForCheck.substr(0,4));
    int month = AuxiliaryMethods::convertStringToInteger(dateEnteredForCheck.substr(5,2));

    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (((year % 100 == 0) && (year % 400 == 0)) || (year % 4 == 0))
        numberOfDaysInAGivenMonth = arr[month-1]+1;

    else
        numberOfDaysInAGivenMonth = arr[month-1];

    return numberOfDaysInAGivenMonth;

}

bool DateValidation::dateCheck(string dateEnteredForCheck) {

    const int valueToHelpCheckDate = 0;

    if (dateEnteredForCheck.size() == 10 && dateConversionWithoutDash(dateEnteredForCheck) > valueToHelpCheckDate && numberOfDaysInTheGivenMonthCheck(dateEnteredForCheck))
        return false;

    return true;

}

int DateValidation::currentDate() {

    auto t = time(nullptr);
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();

    return dateConversionWithoutDash(str);
}

int DateValidation::dateConversionWithoutDash(string dateWithDash) {

    string dateWithoutDash = "";

    dateWithoutDash = dateWithDash.substr(0,4);
    dateWithoutDash += dateWithDash.substr(5,2);
    dateWithoutDash += dateWithDash.substr(8,2);

    if (AuxiliaryMethods::is_digits(dateWithoutDash))
        return AuxiliaryMethods::convertStringToInteger(dateWithoutDash);

    return 0;
}

int DateValidation::dateEntry() {

    string date;
    cout << "Enter date (rrrr-mm-dd): ";
    date = AuxiliaryMethods::loadLine();

    while(dateCheck(date)) {
        cout << "Incorrect date. Enter again: ";
        date = AuxiliaryMethods::loadLine();
    }

    return dateConversionWithoutDash(date);
}

string DateValidation::dateToFileConversion(int dateToConvert) {

    string date = AuxiliaryMethods::convertIntegerToString(dateToConvert);

    date.insert(4, "-");
    date.insert(7, "-");

    return date;
}
