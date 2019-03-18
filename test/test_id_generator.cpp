#include "catch2/catch.hpp"

#include <cstdint>
#include "id_generator.h"

TEST_CASE("can get next unique id", "[id_generator]") {
    SECTION("can get next id for basic account") {
        std::int32_t id = IdGenerator::getId(AccountType::BASIC);
        REQUIRE(id >= INT32_MIN);
        REQUIRE(id <= INT32_MAX);
    }

    SECTION("can get next id for customer account") {
        std::int32_t id = IdGenerator::getId(AccountType::CUSTOMER);
        REQUIRE(id >= INT32_MIN);
        REQUIRE(id <= INT32_MAX);
    }

    SECTION("can get next id for enterprise account") {
        std::int32_t id = IdGenerator::getId(AccountType::ENTERPRISE);
        REQUIRE(id >= INT32_MIN);
        REQUIRE(id <= INT32_MAX);
    }
}