/** \file customer.h
 *  \brief Customer account header
 */

#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <ostream>
#include <string>
#include <utility>
#include "basic.h"

class Customer: public Basic {
public:
    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);

    /**
     * Customer constructor
     * \param initial initial account balance
     * \param firstName fist name of the customer
     * \param lastName last name of the customer
     */
    Customer(float initial, std::string firstName, std::string lastName);
    
    /**
     * Customer destructor
     */
    virtual ~Customer();

    /**
     * Get account holder's name
     * \return pair of first name and last name
     */
    std::pair<std::string, std::string> getName();

    /**
     * Query if the account exist by name
     * \param qName name in format of \b FirstName+LastName
     * \return true if the query matches the account's name, false otherwise
     */
    virtual bool queryByName(std::string qName);

    /**
     * Print account details
     */
    virtual void printDetails();
private:
    std::pair<std::string, std::string> name;    //<! Customer's name (first name, last name)
};

/**
 * Overload the output operator <<
 * \param os the output stream
 * \param customer the Customer instance
 * \return an output stream
 */
std::ostream &operator<<(std::ostream &os, const Customer &customer);

#endif /* define __CUSTOMER_H__ */