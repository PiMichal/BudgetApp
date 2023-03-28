#ifndef DATEVALIDATION_H
#define DATEVALIDATION_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>


#include "AuxiliaryMethods.h"

using namespace std;


class DateValidation{

    static bool numberOfDaysInTheGivenMonthCheck(string dateEnteredForCheck);

    static int countTheNumberOfDaysInAGivenMonth(int year, int month);

    static string dateConversionWithoutDash(string dateWithDash);

public:

    static bool dateCheck(string date);

    static string currentDate();


};







#endif // DATEVALIDATION_H
