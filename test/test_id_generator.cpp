#include "catch2/catch.hpp"

#include <cstdint>
#include "id_generator.h"

TEST_CASE("can get next unique id", "[id_generator]") {
    std::int32_t base = ~(0 << 31 | 0 << 30 | 0 << 29);
    std::int32_t mask = (0 << 31 | 1 << 30 | 0 << 29);

    SECTION("can get several different ids") {
        std::int32_t id001 = IdGenerator::getNextId(base, mask);

        REQUIRE(id001 >= INT32_MIN);
        REQUIRE(id001 <= INT32_MAX);

        std::int32_t id002 = IdGenerator::getNextId(base, mask);
        std::int32_t id003 = IdGenerator::getNextId(base, mask);

        REQUIRE(id001 != id002);
        REQUIRE(id002 != id003);
        REQUIRE(id003 != id001);
    }
}