#ifndef METHODJAVA_H
#define METHODJAVA_H

#include "Unit.h"
#include <vector>

class MethodJava : public Unit {
public:
    enum Modifier {
        STATIC   = 1,
        ABSTRACT = 1 << 1,
        FINAL    = 1 << 2,
        OVERRIDE = 1 << 3
    };

    MethodJava(const std::string& name, const std::string& returnType, Flags flags = 0);
    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODJAVA_H
