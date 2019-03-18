/** \file enterprise.cpp
 *  \brief Enterprise account implementation
 */

#include <iostream>
#include "enterprise.h"
#include "id_generator.h"

Enterprise::Enterprise(float initial, std::string name, std::string y_tunnus):
    Basic(initial, IdGenerator::getId(AccountType::ENTERPRISE), std::time(nullptr)),
    name(name), y_tunnus(y_tunnus) {
    // TODO: verify the y_tunnus 
}

Enterprise::~Enterprise() {

}

bool Enterprise::queryByName(std::string qName) {
    return qName == name;
}

void Enterprise::printDetails() {
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Enterprise &account) {
    os << "\tCreated on: " << std::asctime(std::localtime(&account.createdDate))
       << "\tAccount ID: " << account.id << std::endl
       << "\tY-tunnus: " << account.y_tunnus << std::endl
       << "\tCompany name: " << account.name << std::endl
       << "\tBalance: " << account.balance;

    return os;
}