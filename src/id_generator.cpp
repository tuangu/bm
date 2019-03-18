/** \file id_generator.cpp
 *  \brief IdGenerator implementation
 */

#include <cstdint>
#include "id_generator.h"

std::int32_t IdGenerator::nextBasicId = 0;
std::int32_t IdGenerator::nextCustomerId = 0;
std::int32_t IdGenerator::nextEnterpriseId = 0;

IdGenerator::IdGenerator() {

}

IdGenerator::~IdGenerator() {

}

std::int32_t IdGenerator::getId(AccountType type) {
    std::int32_t uniqueId;

    switch (type) {
        case AccountType::BASIC:
            uniqueId = (IdGenerator::nextBasicId & ID_MASK) | BASIC_ID_MASK;
            IdGenerator::nextBasicId += 1;
            break;
        case AccountType::CUSTOMER:
            uniqueId = (IdGenerator::nextCustomerId & ID_MASK) | CUSTOMER_ID_MASK;
            IdGenerator::nextCustomerId += 1;
            break;
        case AccountType::ENTERPRISE:
            uniqueId = (IdGenerator::nextEnterpriseId & ID_MASK) | ENTERPRISE_ID_MASK;
            IdGenerator::nextEnterpriseId += 1;
            break;
        default:
            break;
    }

    return uniqueId;
}