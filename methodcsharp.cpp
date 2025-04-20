#include "MethodCSharp.h"

MethodCSharp::MethodCSharp(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags)
{}

void MethodCSharp::add(const std::shared_ptr<Unit>& unit, Flags)
{
    m_body.push_back(unit);
}

std::string MethodCSharp::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & ASYNC)    result += "async ";
    if (m_flags & STATIC)   result += "static ";
    if (m_flags & VIRTUAL)  result += "virtual ";
    if (m_flags & ABSTRACT) result += "abstract ";
    if (m_flags & OVERRIDE) result += "override ";

    result += m_returnType + " ";
    result += m_name + "()";

    if (m_flags & ABSTRACT) {
        result += ";\n";
    } else {
        result += "\n" + generateShift(level) + "{\n";
        for (const auto& b : m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
    }

    return result;
}
