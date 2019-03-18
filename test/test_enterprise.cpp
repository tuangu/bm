#include "catch2/catch.hpp"

#include <ctime>
#include <string>
#include "enterprise.h"
#include "id_generator.h"

TEST_CASE("enterprise account can be created, deposited, and withdrew", "[enterprise_account]") {
    std::string name("CompanyName");
    std::string y_tunnus("1234567-9");
    Enterprise acc(0.0f, name, y_tunnus);
    
    REQUIRE(acc.getBalance() == 0.0f);
    REQUIRE((acc.getId() >> 29) == (ENTERPRISE_ID_MASK >> 29));
    REQUIRE(acc.getName() == name);
    REQUIRE(acc.getYTunnus() == y_tunnus);

    SECTION("can deposit money") {
        acc.deposit(123.4f);
        REQUIRE(acc.getBalance() == 123.4f);
    }

    SECTION("cannot deposit money with invalid number") {
        acc.deposit(-123.4);
        REQUIRE(acc.getBalance() == 0.0f);
    }

    SECTION("can withdraw money") {
        acc.deposit(123.4f);
        acc.deposit(100.0f);
        acc.withdraw(23.4f);
        REQUIRE(acc.getBalance() == (123.4f + 100.0f - 23.4f));
    }

    SECTION("cannot overdraw money") {
        acc.deposit(123.4f);
        acc.withdraw(123.5f);
        REQUIRE(acc.getBalance() == 0.0f);
    }

    SECTION("can be queried by name") {
        std::string otherName("OtherCompany");
        REQUIRE(acc.queryByName(otherName) == false);
        REQUIRE(acc.queryByName(name) == true);
    }
}