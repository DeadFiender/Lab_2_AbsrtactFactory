#include "methodjava.h"

MethodJava::MethodJava(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags)
{}

void MethodJava::add(const std::shared_ptr<Unit>& unit, Flags)
{
    m_body.push_back(unit);
}

std::string MethodJava::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & OVERRIDE) result += "@Override\n" + generateShift(level);// Спец.аннотация Java
    if (m_flags & STATIC)   result += "static ";
    if (m_flags & FINAL)    result += "final ";
    if (m_flags & ABSTRACT) result += "abstract ";

    result += m_returnType + " " + m_name + "()";

    if (m_flags & ABSTRACT) {
        result += ";\n";
    } else {
        result += " {\n";
        for (const auto& b : m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
    }

    return result;
}
