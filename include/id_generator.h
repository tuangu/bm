/** \file id_generator.h
 *  \brief IdGenerator header
 */

#ifndef __ID_GENERATOR_H__
#define __ID_GENERATOR_H__

#include <cstdint>

constexpr std::int32_t ID_MASK = ~(0 << 31 | 0 << 30 | 0 << 29);
constexpr std::int32_t BASIC_ID_MASK = (0 << 31 | 1 << 30 | 0 << 29);
constexpr std::int32_t CUSTOMER_ID_MASK = (0 << 31 | 0 << 30 | 1 << 29);
constexpr std::int32_t ENTERPRISE_ID_MASK = (0 << 31 | 1 << 30 | 1 << 29);

/**
 * Different types of bank account
 */
enum AccountType {
    BASIC,      //<! Basic account
    CUSTOMER,   //<! Customer account
    ENTERPRISE, //<! Enterprise account
};

class IdGenerator {
public:
    /**
     * IdGenerator constructor
     */
    IdGenerator();

    /**
     * IdGenerator destructor
     */
    virtual ~IdGenerator();

    /**
     * Get next unique id based on account type. 
     * This is a static function.
     * \param type account type (\b Basic, \b Customer, \b Enterprise)
     * \return the unique id 
     */
    static std::int32_t getId(AccountType type);
private:
    static std::int32_t nextBasicId;         //<! Next unique id for basic account
    static std::int32_t nextCustomerId;      //<! Next unique id for customer account
    static std::int32_t nextEnterpriseId;    //<! Next unique id for enterprise account
};

#endif /* define __ID_GENERATOR_H__ */