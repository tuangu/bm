/** \file basic.h
 *  \brief Basic account header
 */

#ifndef __BASIC_H__
#define __BASIC_H__

#include <ctime>
#include <cstdint>
#include <ostream>
#include <string>
#include <tuple>

constexpr std::int32_t ID_MASK = ~(0 << 31 | 0 << 30 | 0 << 29);            //<! Account ID mask
constexpr std::int32_t BASIC_ID_MASK = (0 << 31 | 1 << 30 | 0 << 29);       //<! Basic account ID mask
constexpr std::int32_t CUSTOMER_ID_MASK = (0 << 31 | 0 << 30 | 1 << 29);    //<! Customer account ID mask
constexpr std::int32_t ENTERPRISE_ID_MASK = (0 << 31 | 1 << 30 | 1 << 29);  //<! Enterprise account ID mask

class Basic {
public:
    friend std::ostream &operator<<(std::ostream &os, const Basic &account);

    /**
     * Basic account constructor
     * \param initial initial balance of the account
     * \param uniqueId unique account id 
     * \param createdDate date representation of the date account was created
     */
    Basic(float initial, std::int32_t uniqueId, std::time_t createdDate);

    /**
     * Basic account destructor
     */
    virtual ~Basic();

    /**
     * Deposit money to the account
     * \param amount amount of money to deposit
     */
    void deposit(float amount);

    /**
     * Withdraw money from the account
     * \param amount amount of money to withdraw
     */
    void withdraw(float amount);

    /**
     * Get account balance
     * \return account balance
     */
    float getBalance();

    /**
     * Get unique id of the account
     * \return the unique id
     */
    std::int32_t getId();

    /**
     * Get the date when the account was created
     * \return the created date
     */
    std::time_t getCreatedDate();

    /**
     * Query if the account exist by name
     * \param name name
     * \return true if the query matches the account's name, false otherwise
     */
    virtual bool queryByName(std::string name);

    /**
     * Print account details
     */
    virtual void printDetails();
protected:
    float balance;              //<! Account balance
    std::int32_t id;            //<! Account unique id
    std::time_t createdDate;    //<! Date representation of the date account was created
};

/**
 * Overload the output operator <<
 * \param os the output stream
 * \param account the Basic instance
 * \return an output stream
 */
std::ostream &operator<<(std::ostream &os, const Basic &account);

#endif /* define __BASIC_H__ */