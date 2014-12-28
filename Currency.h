#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

using namespace std;

class Currency{
public:

    Currency();
    Currency(string code, string name, double rate);

    string getCode() const;
    string getName() const;
    double getRate() const;

    int compare(const Currency& right) const;

private:
    string code;
    string name;
    double rate;
    double EPSILON = 0.1;

};

bool operator==(Currency const &left, Currency const &right);

#endif
