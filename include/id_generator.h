/** \file id_generator.h
 *  \brief IdGenerator header
 */

#ifndef __ID_GENERATOR_H__
#define __ID_GENERATOR_H__

#include <cstdint>
#include <map>

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

    static std::int32_t getNextId(std::int32_t base, std::int32_t mask);
private:
    static std::map<std::int32_t, std::int32_t> idPool;
};

#endif /* define __ID_GENERATOR_H__ */