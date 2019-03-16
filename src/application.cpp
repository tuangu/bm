#include <iostream>
#include <string>

#include "application.h"

Application::Application(std::string greeting):
    greeting(greeting) {
    std::cout << "Calling constructor" << std::endl;
}

Application::~Application() {
    std::cout << "Calling destructor" << std::endl;
}

std::string Application::printHelloWorld() {
    std::cout << greeting << std::endl;

    return greeting;
}