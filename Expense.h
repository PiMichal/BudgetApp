#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{

    int userId;
    string date;
    string item;
    float amount;


public:

    void setUserId(int newId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    string getDate();
    string getItem();
    float getAmount();

};


#endif // EXPENSE_H
