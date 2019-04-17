/** \file id_generator.cpp
 *  \brief IdGenerator implementation
 */

#include <cstdint>
#include "id_generator.h"

std::map<std::int32_t, std::int32_t> IdGenerator::idPool;

IdGenerator::IdGenerator() {

}

IdGenerator::~IdGenerator() {

}

std::int32_t IdGenerator::getNextId(std::int32_t base, std::int32_t mask) {
    std::int32_t nextId;
    
    auto element = idPool.find(mask);
    if (element != idPool.end()) {
        idPool[mask]++;
        nextId = (idPool[mask] & base) | mask;
    } else {
        nextId = (0 & base) | mask;
        idPool[mask] = 0;
    }

    return nextId;
}