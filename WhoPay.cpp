#include <ios>
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
    return payer;
}

Person WhoPay::getReceiver() const {
    return receiver;
}

double WhoPay::getAmount() const {
    return amount;
}

Currency WhoPay::getCurrency() const {
    return currency;
}

int WhoPay::compare(const WhoPay &right) const {
    if (payer.compare(right.getPayer()) != 0){
        return payer.compare(right.getPayer());
    }
    if (receiver.compare(right.getReceiver()) != 0){
        return receiver.compare(right.getReceiver());
    }
    if (currency.compare(right.getCurrency()) != 0){
        return currency.compare(right.getCurrency());
    }
    return (int) (amount * 100 - right.getAmount() * 100);
}


bool operator==(const WhoPay& left, const WhoPay& right) {
    return left.compare(right) == 0;
}

bool operator!=(const WhoPay& left, const WhoPay& right) {
    return left.compare(right) != 0;
}