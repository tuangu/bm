/** \file enterprise.h
 *  \brief Enterprise header
 */

#ifndef __ENTERPRISE_H__
#define __ENTERPRISE_H__

#include <ostream>
#include <string>
#include "basic.h"

class Enterprise: public Basic {
public:
    friend std::ostream &operator<<(std::ostream &os, const Enterprise &account);

    /**
     * Enterprise constructor
     * \param initial initial account balance
     * \param name company name
     * \param y_tunnus y-tunnus (Business ID)
     */
    Enterprise(float initial, std::string name, std::string y_tunnus);
    
    /**
     * Enterprise destructor
     */
    virtual ~Enterprise();

    /**
     * Query if the account exist by name
     * \param qName company name
     * \return true if the query matches the account's name, false otherwise
     */
    virtual bool queryByName(std::string qName);

    /**
     * Get company name
     * \return company name
     */
    std::string getName() { return name; };

    /**
     * Get Y-tunnus (Business ID)
     * \return Y-tunnus
     */
    std::string getYTunnus() { return y_tunnus; };

    /**
     * Print account details
     */
    virtual void printDetails();
private:
    std::string name;       //<! Company name
    std::string y_tunnus;   //<! Y-tunnus (Business ID)
};

/**
 * Overload the output operator <<
 * \param os the output stream
 * \param account the Enterprise instance
 * \return an output stream
 */
std::ostream &operator<<(std::ostream &os, const Enterprise &account);

#endif /* define __ENTERPRISE_H__ */