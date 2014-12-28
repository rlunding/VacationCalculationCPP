#include "Person.h"

using namespace std;

Person::Person() {
    this->name = "No name";
    this->mail = "no@mail.com";
}

Person::Person(string name, string mail) {
    this->name = name;
    this->mail = mail;
}

string Person::getName() const {
    return name;
}

string Person::getMail() const {
    return mail;
}

int Person::compare(const Person &right) const {
    if (name.compare(right.name) != 0){
        return name.compare(right.name);
    }
    return mail.compare(right.mail);
}

bool operator==(const Person& left, const Person& right) {
    return left.compare(right) == 0;
}

bool operator!=(const Person& left, const Person& right) {
    return left.compare(right) != 0;
}
