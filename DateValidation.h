#ifndef DATEVALIDATION_H
#define DATEVALIDATION_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>


#include "AuxiliaryMethods.h"

using namespace std;


class DateValidation{

    int dateFrom;
    int dateTo;

    static bool numberOfDaysInTheGivenMonthCheck(string dateEnteredForCheck);

    static int countTheNumberOfDaysInAGivenMonth(string dateEnteredForCheck);




public:

    void setDateFrom(int newDateFrom);
    void setDateTo(int newDateTo);

    static bool dateCheck(string date);
    static bool balanceThisMonth(int date);
    static bool previousMonthsBalance(int date);
    bool balanceSheetForTheSelectedPeriod(int date);

    static int dateConversionWithoutDash(string dateWithDash);
    static int currentDate();

    static string dateToFileConversion(int dateToConvert);


};







#endif // DATEVALIDATION_H
