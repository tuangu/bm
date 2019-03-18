#include "catch2/catch.hpp"

#include <ctime>
#include <string>
#include "customer.h"
#include "id_generator.h"

TEST_CASE("customer account can be created, deposited, and withdrew", "[customer_account]") {
    std::string firstName("Tuan");
    std::string lastName("Nguyen");
    Customer acc(0.0f, firstName, lastName);
    
    REQUIRE(acc.getBalance() == 0.0f);
    REQUIRE((acc.getId() >> 29) == (CUSTOMER_ID_MASK >> 29));
    REQUIRE(acc.getName().first == firstName);
    REQUIRE(acc.getName().second == lastName);

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
        std::string query("Tuan+Nguyen");
        std::string otherQuery1("Tuan+");
        std::string otherQuery2("+Nguyen");
        REQUIRE(acc.queryByName(otherQuery1) == false);
        REQUIRE(acc.queryByName(otherQuery2) == false);
        REQUIRE(acc.queryByName(query) == true);
    }
}