#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{

    int userId;
    int date;

    string item;

    float amount;



public:

    Income(int userId = 0, int date = 0, string item = "", float amount = 0){

    this -> userId = userId;
    this -> date = date;
    this -> amount = amount;
    this -> item = item;

    };

    void setUserId(int newId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    int getDate();

    float getAmount();

    string getItem();


};






#endif // INCOME_H
