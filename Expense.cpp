#include "Expense.h"

void Expense::setUserId(int newId) {
    userId = newId;
}

void Expense::setDate(string newDate) {
    date = newDate;
}

void Expense::setItem(string newItem) {
    item = newItem;
}

void Expense::setAmount(float newAmount) {
    amount = newAmount;
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
