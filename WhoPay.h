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
    int compare(const WhoPay& right) const;

private:
    Person payer;
    Person receiver;
    double amount;
    Currency currency;
};

bool operator==(WhoPay const &left, WhoPay const &right);
bool operator!=(WhoPay const &left, WhoPay const &right);

struct whopay_hash{
    inline size_t operator()(const WhoPay& o) const {
        hash<double> doubleHash;
        return doubleHash(o.getAmount()) * 13;
        //TODO: tell the c++ that this is fucking hopeless!
    }
};

#endif