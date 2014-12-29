#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <functional>

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

struct person_hash{
    inline size_t operator()(const Person& o) const {
        hash<string> str_hash;
        return str_hash(o.getName()) * 13 + str_hash(o.getMail()) * 17;
    }
};
#endif