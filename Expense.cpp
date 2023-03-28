#include "Expense.h"

void Expense::setUserId(int newId) {
    userId = newId;
}

void Expense::setAmount(float newAmount) {
    amount = newAmount;
}

void Expense::setDate(string newDate) {
    date = newDate;
}

void Expense::setItem(string newItem) {
    item = newItem;
}

int Expense::getUserId() {
    return userId;
}

string Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

float Expense::getAmount() {
    return amount;
}
