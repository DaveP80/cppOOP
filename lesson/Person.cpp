#include "Person.h"
#include <sstream>

Person::Person() {
    age = 0;
    name = "";
}


string Person::toString() {
    stringstream ss;

    ss << "Name: ";
    ss << name;
    ss << "; age: ";
    ss << age;
    return ss.str();
}