#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
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
    vector<WhoPay> result;
    vector<Person> giveMoney;
    vector<Person> getMoney;
    unordered_map<Person, double, person_hash> expense (persons.size());

    totalExpenses = 0.0;
    cout << "Who had expenses, and how much (in " << currency.getCode() << "):" <<  endl;
    for (auto &person : persons){
        for (auto &exp : expenses){
            if (person == exp.getPerson()){
                double amount = getAmountInEventCurrency(exp);
                expense[person] = amount + expense[person];
                totalExpenses += amount;
            }
        }
    }
    for (auto &person : persons){
        cout << "\t" << person.getName() << ": " << expense[person] << endl;
    }
    pricePerPerson = totalExpenses / persons.size();


    cout << "Who had expenses when the price pr. person is subtracted (in " << currency.getCode() << "):" <<  endl;
    for (auto &person : persons){
        double amount = expense[person] - pricePerPerson;
        expense[person] = amount;
        if (amount > 0){
            getMoney.push_back(person);
        } else if(amount < 0){
            giveMoney.push_back(person);
        }
    }
    for (auto &person : persons){
        cout << "\t" << person.getName() << ", " << expense[person] << endl;
    }
    cout << "These need some money" << endl;
    for (auto &person : getMoney){
        cout << "\t" << person.getName() << endl;
    }
    cout << "These will give some money" << endl;
    for (auto &person : giveMoney){
        cout << "\t" << person.getName() << endl;
    }


    cout << "Who is going to pay who: " << endl;
    while(!getMoney.empty() && !giveMoney.empty()){
        Person get = getMoney.back();
        Person give = giveMoney.back();
        double amountGet = expense[get];
        double amountGive = abs(expense[give]);
        double pay = 0;
        if (amountGet > amountGive){
            pay = amountGive;
            giveMoney.pop_back();
            expense[give] = 0;
            expense[get] = expense[get] - pay;
        } else if(amountGet < amountGive){
            pay = amountGet;
            getMoney.pop_back();
            expense[give] = expense[give] + pay;
            expense[get] = 0;
        } else {
            pay = amountGive;
            giveMoney.pop_back();
            getMoney.pop_back();
            expense[give] = 0;
            expense[get] = 0;
        }
        result.push_back(WhoPay(give, get, pay, currency));

        for (auto &wp : result) {
            cout << wp.getPayer().getName() << " give " << wp.getAmount() << wp.getCurrency().getCode() << " to: " << wp.getReceiver().getName() << endl;
        }
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

double Event::getAmountInEventCurrency(Expense expense) {
    if (currency == expense.getCurrency()){
        return expense.getAmount();
    }
    return (expense.getAmount() * expense.getCurrency().getRate()) / currency.getRate();
}
