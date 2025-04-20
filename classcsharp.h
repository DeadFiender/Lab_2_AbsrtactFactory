#ifndef CLASSCSHARP_H
#define CLASSCSHARP_H

#include <vector>
#include "Unit.h"

class ClassCSharp : public Unit {
public:
    enum AccessModifier { PUBLIC, PROTECTED, PRIVATE, INTERNAL };
    static const std::vector<std::string> ACCESS_MODIFIERS;

    ClassCSharp(const std::string& name, Flags flags = 0);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::vector<std::vector<std::shared_ptr<Unit>>> m_fields;
};

#endif // CLASSCSHARP_H

