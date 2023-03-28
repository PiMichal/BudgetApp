#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{

    int userId;
    float amount;

    string date;
    string item;



public:

    Expense(int userId = 0, float amount = 0, string date = "", string item = ""){

    this -> userId = userId;
    this -> amount = amount;
    this -> date = date;
    this -> item = item;

    };

    void setUserId(int newId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    float getAmount();

    string getDate();
    string getItem();


};


#endif // EXPENSE_H
