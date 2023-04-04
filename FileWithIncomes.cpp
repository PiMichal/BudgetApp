#include "FileWithIncomes.h"

void FileWithIncomes::addIncomesToFile(Income income){

    if (!isTheFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Clients");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Client");
    xml.IntoElem();
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", DateValidation::dateToFileConversion(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(income.getAmount()));

    xml.Save(getFileName());
    xml.ResetPos();

}

vector <Income> FileWithIncomes::loadIncomesFromFile() {

    Income income;
    vector <Income> incomes;

    if (xml.Load(getFileName())) {
        xml.FindElem("Clients");
        xml.IntoElem();

        while (xml.FindElem("Client")) {

            xml.IntoElem();
            xml.FindElem("UserId");
            income.setUserId(AuxiliaryMethods::convertStringToInteger(xml.GetData()));
            xml.FindElem("Date");
            income.setDate(DateValidation::dateConversionWithoutDash(xml.GetData()));
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(AuxiliaryMethods::convertStringToFloat(xml.GetData()));
            incomes.push_back(income);
            xml.OutOfElem();
        }
    }
    xml.ResetPos();
    return incomes;
}
