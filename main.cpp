#include <QCoreApplication>
#include <iostream>
#include "ICodeFactory.h"
#include "CodeFactoryCpp.h"
#include "CodeFactoryCSharp.h"
#include "CodeFactoryJava.h"

std::string generateProgram(const ICodefactory& factory) {
    auto myClass = factory.createClass("MyClass", 0);

    myClass->add(factory.createMethod("testFunc1", "void", 0), ClassCpp::PUBLIC);

    myClass->add(factory.createMethod("testFunc2", "void", MethodCpp::STATIC), ClassCpp::PRIVATE);

    myClass->add(factory.createMethod("testFunc3", "void", MethodCpp::VIRTUAL | MethodCpp::CONST), ClassCpp::PUBLIC);

    auto method = factory.createMethod("testFunc4", "void", MethodCpp::STATIC);
    method->add(factory.createPrintOperator("Hello, world!"), 0);
    myClass->add(method, ClassCpp::PROTECTED);

    return myClass->compile();
}


int main() {
    std::unique_ptr<ICodefactory> factory;

    std::cout << "Choose language (1 - C++, 2 - C#, 3 - Java): ";
    int choice=3;
    std::cin >> choice;

    if (choice == 1) {
        factory = std::make_unique<CodeFactoryCpp>();
    } else if (choice == 2) {
        factory = std::make_unique<CodeFactoryCSharp>();
    } else if (choice == 3) {
        factory = std::make_unique<CodeFactoryJava>();
    } else {
        std::cerr << "Invalid choice.\n";
        return 1;
    }

    std::cout << generateProgram(*factory) << std::endl;

    return 0;
}


