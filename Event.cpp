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

vector<WhoPay> Event::calculateWhoPayWho() {
    vector<WhoPay> result(10);

    totalExpenses = 0.0;
    cout << "Who had expenses, and how much (in " << currency.getCode() << "):" <<  endl;
    for (auto &person : persons){
        for (auto &exp : expenses){
            if (person == exp.getPerson()){
                //TODO: add to persons total expense
                totalExpenses += exp.getAmount();
            }
        }
    }
    for (auto &person : persons){
        cout << "\t" << person.getName() << ": " << endl;
    }
    pricePerPerson = totalExpenses / persons.size();


    cout << "Who had expenses when the price pr. person is subtracted (in " << currency.getCode() << "):" <<  endl;
    for (auto &person : persons){
        //TODO: do something
    }

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
    cout << "Price per person " << pricePerPerson << endl;
    cout << "Total price: " << totalExpenses << endl;
}
