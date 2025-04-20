#ifndef PRINTOPERATORCSHARP_H
#define PRINTOPERATORCSHARP_H

#include "Unit.h"

class PrintOperatorCSharp : public Unit {
public:
    PrintOperatorCSharp(const std::string& text);
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_text;
};

#endif // PRINTOPERATORCSHARP_H
