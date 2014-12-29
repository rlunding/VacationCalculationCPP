#include "Event.h"

using namespace std;

int main() {
    Currency dkk("DKK", "Dansk Krone", 100);
    Currency sek("SEK", "Svensk Krone", 80);
    Person rasmus("Rasmus", "dr@dr.dk");
    Person john("John", "no-reply@dr.dk");
    Person gert("Gert", "no-reply@dr.dk");
    Person hans("Hans", "no-reply@dr.dk");
    Expense pizza1("Pizza", rasmus, 50, dkk);
    Expense pizza2("Pizza", rasmus, 100, dkk);
    Expense pizza3("Pizza", rasmus, 650, dkk);
    Expense pizza4("Pizza", gert, 1000, sek);
    Event event("Test", dkk);
    event.addPerson(rasmus);
    event.addPerson(john);
    event.addPerson(gert);
    event.addPerson(hans);
    event.addExpense(pizza1);
    event.addExpense(pizza2);
    event.addExpense(pizza3);
    event.addExpense(pizza4);
    event.calculateWhoPayWho();
    event.print();
    return 0;
}
