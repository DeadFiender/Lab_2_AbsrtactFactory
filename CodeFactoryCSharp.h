#ifndef CODEFACTORYCSHARP_H
#define CODEFACTORYCSHARP_H

#include "ICodeFactory.h"
#include "classcsharp.h"
#include "MethodCSharp.h"
#include "PrintOperatorCSharp.h"

class CodeFactoryCSharp : public ICodefactory {
public:
    std::shared_ptr<Unit> createClass(const std::string& name, Unit::Flags flags) const override {
        return std::make_shared<ClassCSharp>(name, flags);
    }

    std::shared_ptr<Unit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override {
        return std::make_shared<MethodCSharp>(name, returnType, flags);
    }

    virtual std::shared_ptr<Unit> createPrintOperator(const std::string& text) const override {
        return std::make_shared<PrintOperatorCSharp>(text);
    }
};

#endif // CODEFACTORYCSHARP_H
