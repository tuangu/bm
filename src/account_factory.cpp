/** \file account_factory.cpp
 *  \brief Account factory implementation
 */

#include <ctime>
#include "account_factory.h"
#include "id_generator.h"

std::shared_ptr<AccountFactory> AccountFactory::factoryInstance = nullptr;

std::shared_ptr<AccountFactory> AccountFactory::getInstance() {
    if (factoryInstance != nullptr)
        return factoryInstance;

    factoryInstance = std::shared_ptr<AccountFactory>(new AccountFactory);
    return factoryInstance;
}

std::shared_ptr<Basic> AccountFactory::makeBasic(float initial) {
    std::shared_ptr<Basic> basicAccount = std::make_shared<Basic>(
        initial, 
        IdGenerator::getNextId(ID_MASK, BASIC_ID_MASK), 
        std::time(nullptr)
    );

    return basicAccount;
}

std::shared_ptr<Basic> AccountFactory::makeCustomer(
    float initial, std::string firstName, std::string lastName) {
    std::shared_ptr<Customer> customerAccount = std::make_shared<Customer>(
        initial,
        firstName,
        lastName
    );

    return customerAccount;
}

std::shared_ptr<Basic> AccountFactory::makeEnterprise(
    float initial, std::string name, std::string y_tunnus) {
    std::shared_ptr<Enterprise> enterpriseAccount = std::make_shared<Enterprise>(
        initial,
        name,
        y_tunnus
    );

    return enterpriseAccount;
}

