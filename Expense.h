#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Currency.h"
#include "Person.h"

using namespace std;

class Expense{
public:

    Expense(string title, const Person& person, double amount, const Currency& currency);

    string getTitle() const;
    Person getPerson() const;
    double getAmount() const;
    Currency getCurrency() const;

    int compare(const Expense& right) const;

private:
    Expense();
    string title;
    Person person;
    double amount;
    Currency currency;
};

bool operator==(Expense const &left, Expense const &right);
bool operator!=(Expense const &left, Expense const &right);

#endif