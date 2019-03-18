/** \file basic.cpp
 *  \brief Basic account implementation
 */

#include <ctime>
#include <iostream>
#include <iomanip>
#include "basic.h"

Basic::Basic(float initial, std::int32_t uniqueId, std::time_t createdDate):
    balance(initial), id(uniqueId), createdDate(createdDate) {
    
}

Basic::~Basic() {

}

void Basic::deposit(float amount) {
    if (amount <= 0.0f) {
        return;
    }
    float newBalance = amount + balance;
    balance = newBalance;
}

void Basic::withdraw(float amount) {
    float newBalance = balance - amount;
    if (newBalance < 0.0f) {
        newBalance = 0.0f;
    }
    balance = newBalance;
}

float Basic::getBalance() {
    return balance;
}

std::int32_t Basic::getId() {
    return id;
}

std::time_t Basic::getCreatedDate() {
    return createdDate;
}

bool Basic::queryByName(std::string name) {
    return false;
}

void Basic::printDetails() {
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Basic &account) {
    std::time_t createdDate = account.createdDate;
#ifdef __unix__
    auto tm = *std::localtime(&createdDate);
#elif defined(_WIN32) || defined(_WIN64)
    std::tm tm;
    localtime_s(&tm, &createdDate);
#endif

    os << "\tCreated on: " << std::put_time(&tm, "%d-%m-%Y %H:%M:%S") << std::endl
       << "\tAccount ID: " << account.id << std::endl
       << "\tBalance: " << account.balance;

    return os;
}