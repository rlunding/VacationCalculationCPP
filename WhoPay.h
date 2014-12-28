#ifndef WHOPAY_H
#define WHOPAY_H

#include "Currency.h"
#include "Person.h"

using namespace std;

class WhoPay{
public:
    WhoPay();
    WhoPay(Person payer, Person receiver, double amount, Currency currency);

    Person getPayer() const;
    Person getReceiver() const;
    double getAmount() const;
    Currency getCurrency() const;

private:
    Person payer;
    Person receiver;
    double amount;
    Currency currency;

};

#endif