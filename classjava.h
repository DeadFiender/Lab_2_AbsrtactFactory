#ifndef CLASSJAVA_H
#define CLASSJAVA_H

#include <vector>
#include "Unit.h"

class ClassJava : public Unit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;

    ClassJava(const std::string& name, Flags flags = 0);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::vector<std::vector<std::shared_ptr<Unit>>> m_fields;
};

#endif // CLASSJAVA_H
