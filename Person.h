#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
public:
    Person();
    Person(string name, string mail);
    string getName() const;
    string getMail() const;
    int compare(const Person& right) const;

private:
    string name;
    string mail;
};

bool operator==(Person const &left, Person const &right);
bool operator!=(Person const &left, Person const &right);

#endif