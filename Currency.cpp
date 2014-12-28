#include "Currency.h"
#include "cmath"

using namespace std;


Currency::Currency() {
    this->code = "Default";
    this->name = "Default";
    this->rate = 1;
}

Currency::Currency(string code, string name, double rate) {
    this->code = code;
    this->name = name;
    this->rate = rate;
}

string Currency::getCode() const{
    return code;
}

string Currency::getName() const{
    return name;
}

double Currency::getRate() const {
    return rate;
}

int Currency::compare(const Currency& right) const{
    if (code.compare(right.code) != 0) {
        return code.compare(right.code);
    } if (abs(rate - right.rate) < EPSILON){
        return 0;
    } else {
        return rate / EPSILON - right.rate / EPSILON;
    }
}


bool operator==(const Currency& left, const Currency& right) {
    return left.compare(right) == 0;
}


