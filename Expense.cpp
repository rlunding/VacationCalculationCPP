#include <ios>
#include "Expense.h"

using namespace std;

Expense::Expense() {
    this->title = "Default";
    this->person = Person();
    this->amount = 0.0;
    this->currency = Currency();
}

Expense::Expense(string title, const Person& person, double amount, const Currency& currency) {
    this->title = title;
    this->person = person;
    this->amount = amount;
    this->currency = currency;
}

string Expense::getTitle() const {
    return title;
}

Person Expense::getPerson() const {
    return person;
}

double Expense::getAmount() const {
    return amount;
}

Currency Expense::getCurrency() const {
    return currency;
}

int Expense::compare(const Expense &right) const {
    if (title.compare(right.title) != 0){
        return title.compare(right.title);
    }
    if (person.compare(right.person) != 0){
        return person.compare(right.person);
    }
    if (currency.compare(right.currency) != 0){
        return currency.compare(right.currency);
    }
    return (int) (amount * 100 - right.amount * 100);
}


bool operator==(const Expense& left, const Expense& right) {
    return left.compare(right) == 0;
}

bool operator!=(const Expense& left, const Expense& right) {
    return left.compare(right) != 0;
}