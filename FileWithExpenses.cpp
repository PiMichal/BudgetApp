#include "FileWithExpenses.h"

void FileWithExpenses::addExpensesToFile(Expense expense){

    if (!isTheFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Clients");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Client");
    xml.IntoElem();
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", DateValidation::dateToFileConversion(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));

    xml.Save(getFileName());
    xml.ResetPos();

}

vector <Expense> FileWithExpenses::loadExpensesFromFile() {

    Expense expense;
    vector <Expense> expenses;

    if (xml.Load(getFileName())) {
        xml.FindElem("Clients");
        xml.IntoElem();

        while (xml.FindElem("Client")) {

            xml.IntoElem();
            xml.FindElem("UserId");
            expense.setUserId(AuxiliaryMethods::convertStringToInteger(xml.GetData()));
            xml.FindElem("Date");
            expense.setDate(DateValidation::dateConversionWithoutDash(xml.GetData()));
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(AuxiliaryMethods::convertStringToFloat(xml.GetData()));
            expenses.push_back(expense);
            xml.OutOfElem();
        }
    }
    xml.ResetPos();
    return expenses;
}
