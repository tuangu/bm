#include "catch2/catch.hpp"

#include <ctime>
#include "basic.h"
#include "id_generator.h"

TEST_CASE("basic account can be created, deposited, and withdrew", "[basic_account]") {
    std::time_t now = std::time(nullptr);
    Basic basicAcc(0.0f, IdGenerator::getId(AccountType::BASIC), now);
    
    REQUIRE(basicAcc.getBalance() == 0.0f);
    REQUIRE((basicAcc.getId() >> 29) == (BASIC_ID_MASK >> 29));
    REQUIRE(basicAcc.getCreatedDate() == now);

    SECTION("can deposit money") {
        basicAcc.deposit(123.4f);
        REQUIRE(basicAcc.getBalance() == 123.4f);
    }

    SECTION("cannot deposit money with invalid number") {
        basicAcc.deposit(-123.4f);
        REQUIRE(basicAcc.getBalance() == 0.0f);
    }

    SECTION("can withdraw money") {
        basicAcc.deposit(123.4f);
        basicAcc.deposit(100.0f);
        basicAcc.withdraw(23.4f);
        REQUIRE(basicAcc.getBalance() == (123.4f + 100.0f - 23.4f));
    }

    SECTION("cannot overdraw money") {
        basicAcc.deposit(123.4f);
        basicAcc.withdraw(123.5f);
        REQUIRE(basicAcc.getBalance() == 0.0f);
    }
}