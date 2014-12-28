#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include "Currency.h"
#include "Person.h"
#include "Expense.h"
#include "WhoPay.h"

using namespace std;

class Event{
public:
    Event();
    Event(string name, Currency currency);

    string getName() const;
    vector<Person> getPersons() const;
    vector<Expense> getExpenses() const;
    double getTotalExpenses() const;
    double getPricePerPerson() const;
    void addPerson(Person& person);
    void removePerson(Person& person);
    void addExpense(Expense& expense);
    void removeExpense(Expense& expense);

    vector<WhoPay> CalculateWhoPayWho();

    void print() const;

private:
    string name;
    Currency currency;
    vector<Person> persons;
    vector<Expense> expenses;
    double totalExpenses;
    double pricePerPerson;

    double getAmountInEventCurrency(Expense expense);
};

#endif