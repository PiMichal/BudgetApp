#include "Income.h"

void Income::setUserId(int newId) {
    userId = newId;
}

void Income::setAmount(float newAmount) {
    amount = newAmount;
}

void Income::setDate(string newDate) {
    date = newDate;
}

void Income::setItem(string newItem) {
    item = newItem;
}

int Income::getUserId() {
    return userId;
}

string Income::getDate() {
    return date;
}

string Income::getItem() {
    return item;
}

float Income::getAmount() {
    return amount;
}
