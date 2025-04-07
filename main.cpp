#include <QCoreApplication>
#include <iostream>
#include "ICodeFactory.h"
#include "CodeFactoryCpp.h"

std::string generateProgram() {
    ClassCpp myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodCpp >( "testFunc1", "void", 0 ),
        ClassCpp::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodCpp >( "testFunc2", "void", MethodCpp::STATIC ),
        ClassCpp::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodCpp >( "testFunc3", "void", MethodCpp::VIRTUAL |
                                                              MethodCpp::CONST ),
        ClassCpp::PUBLIC
        );
    auto method = std::make_shared< MethodCpp >( "testFunc4", "void",
                                               MethodCpp::STATIC );
    method->add (std::make_shared< PrintOperatorCpp >( R"(Hello, world!\n)" ),0);
    myClass.add( method, ClassCpp::PROTECTED );
    return myClass.compile();
}

int main() {
    std::cout << generateProgram() << std::endl;
    return 0;
}



