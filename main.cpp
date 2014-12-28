#include "Event.h"

using namespace std;

int main() {
    Currency dkk("DKK", "Dansk Krone", 100);
    Person rasmus("Rasmus", "dr@dr.dk");
    Person john("John", "no-reply@dr.dk");
    Expense pizza1("Pizza", rasmus, 55, dkk);
    Expense pizza2("Pizza", rasmus, 65, dkk);
    Expense pizza3("Pizza", rasmus, 75, dkk);
    Event event("Test", dkk);
    event.addPerson(rasmus);
    event.addPerson(john),
    event.addExpense(pizza1);
    event.addExpense(pizza2);
    event.addExpense(pizza3);
    event.print();
    event.removePerson(john);
    event.removeExpense(pizza2);
    event.print();
    return 0;
}
