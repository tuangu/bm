/** \file application.cpp
 *  \brief Application implementation
 */

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include "account_factory.h"
#include "basic.h"
#include "application.h"

Application::Application() {
    
}

Application::~Application() {

}

void Application::run() {
    bool stop = false;
    int selection;

    while (!stop) {
        // Print out the selections
        std::cout << "\n**** MAIN APPLICATION ****" << std::endl;
        std::cout << "1. Create account" << std::endl;
        std::cout << "2. Deposit to your account" << std::endl;
        std::cout << "3. Withdraw from your account" << std::endl;
        std::cout << "4. Query account details" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your selection (1-5): ";

        std::cin >> selection;
        switch (selection) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                query();
                break;
            case 5:
                stop = true;
                break;
            default:
                break;
        }
    }
}

void Application::getAccountDetails(std::string query) {
    bool found = false;

    for (auto &account : accounts) {
        if (account->queryByName(query)) {
            std::cout << ">> Account details: " << std::endl;
            account->printDetails();

            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << ">> Cannot find your account" << std::endl;
    }
}

void Application::createAccount() {
    bool stop = false;
    int selection;

    while (!stop) {
        std::cout << "\n**** CREATE ACCOUNT ****" << std::endl;
        std::cout << "1. Create basic account" << std::endl;
        std::cout << "2. Create customer account" << std::endl;
        std::cout << "3. Create company account" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your selection (1-4): ";

        std::cin >> selection;
        switch (selection) {
            case 1: // Basic account
            {
                std::shared_ptr<Basic> ptr = AccountFactory::getInstance()->makeBasic(0.0f);
                accounts.push_back(ptr);
                std::cout << ">> Created your basic account." << std::endl;
                std::cout << "\tAccount ID: " << ptr->getId() << std::endl;
                
                break;
            }
            case 2: // Customer account
            {   
                std::string firstName, lastName;

                std::cout << "Your first name: ";
                std::cin >> firstName;
                std::cout << "Your last name: ";
                std::cin >> lastName;

                std::shared_ptr<Basic> ptr = AccountFactory::getInstance()->makeCustomer(
                    0.0f,
                    firstName,
                    lastName
                );
                accounts.push_back(ptr);
                std::cout << ">> Created your customer account" << std::endl;
                std::cout << "\tAccount ID: " << ptr->getId() << std::endl;
                
                break;
            }
            case 3: // Enterprise account
            {
                std::string name;
                std::string y_tunnus;

                std::cout << "Company name: ";
                std::cin >> name;
                std::cout << "Y-tunnus: ";
                std::cin >> y_tunnus;

                std::shared_ptr<Basic> ptr = AccountFactory::getInstance()->makeEnterprise(
                    0.0f,
                    name,
                    y_tunnus
                );
                accounts.push_back(ptr);
                std::cout << ">> Created your company account" << std::endl;
                std::cout << "\tAccount ID: " << ptr->getId() << std::endl;

                break;
            }
            case 4:
                stop = true;
                break;
            default:
                break;
        }
    }
}

void Application::deposit() {
    bool found = false;
    float amount;
    std::int32_t id;

    std::cout << "\n**** DEPOSIT TO ACCOUNT ****" << std::endl;
    std::cout << "Enter your account ID: ";
    std::cin >> id;
    std::cout << "Enter the amount of money to deposit: ";
    std::cin >> amount;
    for (auto &account : accounts) {
        if (id == account->getId()) {
            account->deposit(amount);
            std::cout << ">> New balance: " << account->getBalance() << std::endl;
            
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << ">> Invalid account ID" << std::endl;
    }
}

void Application::withdraw() {
    bool found = false;
    float amount;
    std::int32_t id;

    std::cout << "\n**** WITHDRAW FROM ACCOUNT ****" << std::endl;
    std::cout << "Enter your account ID: ";
    std::cin >> id;
    std::cout << "Enter the amount of money to withdraw: ";
    std::cin >> amount;
    for(auto &account : accounts) {
        if (id == account->getId()) {
            account->withdraw(amount);
            std::cout << ">> New balance: " << account->getBalance() << std::endl;
            
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << ">> Invalid account ID" << std::endl;
    }
}

void Application::query() {
    bool stop = false;
    int selection;
    std::string name;

    while (!stop) {
        std::cout << "\n**** QUERY ACCOUNT DETAILS ****" << std::endl;
        std::cout << "1. Customer account" << std::endl;
        std::cout << "2. Company account" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your selection (1-3): ";

        std::cin >> selection;
        switch (selection) {
            case 1:
                std::cout << "Enter your name as FirstName+LastName: ";
                std::cin >> name;
                getAccountDetails(name);
                break;
            case 2:
                std::cout << "Enter company name: ";
                std::cin >> name;
                getAccountDetails(name);
                break;
            case 3:
                stop = true;
                break;
            default:
                break;
        }
    }
}