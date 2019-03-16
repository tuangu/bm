#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include "application.h"

TEST_CASE("Can print greeting", "[application]") {
    Application app("Hello World!");

    std::string output = app.printHelloWorld();
    REQUIRE_THAT(output, Catch::Matchers::Contains("Hello World!"));
}