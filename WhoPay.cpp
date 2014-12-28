#include "Currency.h"
#include "WhoPay.h"

using namespace std;

WhoPay::WhoPay() {
    this->payer = Person();
    this->receiver = Person();
    this->amount = 0.0;
    this->currency = Currency();
}

WhoPay::WhoPay(Person payer, Person receiver, double amount, Currency currency) {
    this->payer = payer;
    this->receiver = receiver;
    this->amount = amount;
    this->currency = currency;
}

Person WhoPay::getPayer() const {
    return Person();
}

Person WhoPay::getReceiver() const {
    return Person();
}

double WhoPay::getAmount() const {
    return 0;
}

Currency WhoPay::getCurrency() const {
    return Currency();
}


