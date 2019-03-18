/** \file customer.cpp
 *  \brief Customer account implementation
 */

#include <iostream>
#include <string>
#include "customer.h"
#include "id_generator.h"

Customer::Customer(float initial, std::string firstName, std::string lastName):
    Basic(initial, IdGenerator::getId(AccountType::CUSTOMER), std::time(nullptr)), 
    name(std::make_pair(firstName, lastName)) {

}

Customer::~Customer() {

}

std::pair<std::string, std::string> Customer::getName() {
    return name;
}

bool Customer::queryByName(std::string qName) {
    std::string::size_type signPos;
    std::string qFirstName, qLastName;

    signPos = qName.find("+");
    if (signPos == std::string::npos) {
        return false;
    }
    qFirstName = qName.substr(0, signPos);
    qLastName = qName.substr(signPos + 1);
    if (qFirstName == name.first && qLastName == name.second) {
        return true;
    } else {
        return false;
    }
}

void Customer::printDetails() {
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
    os << "\tCreated on: " << std::asctime(std::localtime(&customer.createdDate))
       << "\tAccount ID: " << customer.id << std::endl
       << "\tName: " << std::get<0>(customer.name) << " " << std::get<1>(customer.name) << std::endl
       << "\tBalance: " << customer.balance;

    return os;
}