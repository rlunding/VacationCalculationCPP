#include <string>
#include <iostream>
#include "Event.h"

using namespace std;

Event::Event() {
    this->name = "Default event";
    this->currency = Currency();
    this->totalExpenses = 0;
    this->pricePerPerson = 0;
}

Event::Event(string name, Currency currency) {
    this->name = name;
    this->currency = currency;
}

string Event::getName() const {
    return name;
}

vector<Person> Event::getPersons() const {
    return persons;
}

vector<Expense> Event::getExpenses() const {
    return expenses;
}

double Event::getTotalExpenses() const {
    return totalExpenses;
}

double Event::getPricePerPerson() const {
    return pricePerPerson;
}

void Event::addPerson(Person& person) {
    persons.push_back(person);
}

void Event::removePerson(Person& person) {
    persons.erase(remove(persons.begin(), persons.end(), person), persons.end());
}

void Event::addExpense(Expense& expense) {
    expenses.push_back(expense);
}

void Event::removeExpense(Expense& expense) {
    expenses.erase(remove(expenses.begin(), expenses.end(), expense), expenses.end());
}

vector<WhoPay> Event::CalculateWhoPayWho() {
    vector<WhoPay> result(10);

    return result;
}

void Event::print() const {
    cout << "----- " + name + " -----" << endl;
    cout << "Persons" << endl;
    for(auto &p : persons){
        cout << "\t" + p.getName() << endl;
    }
    cout << "Expenses" << endl;
    for(auto &expen : expenses){
        cout << "\t" << expen.getTitle() << ": " << expen.getAmount() << " " << expen.getCurrency().getCode() << endl;
    }
}
