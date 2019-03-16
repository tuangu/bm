#include <iostream>

#include "application.h"

Application::Application(std::string greeting):
    greeting(greeting) {
    std::cout << "Calling constructor" << std::endl;
}

Application::~Application() {
    std::cout << "Calling destructor" << std::endl;
}

void Application::printHelloWorld() {
    std::cout << greeting << std::endl;
}

int main() {
    Application app("Hello world!");
    app.printHelloWorld();

    return 0;
}