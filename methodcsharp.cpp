#include "MethodCSharp.h"
// Конструктор
MethodCSharp::MethodCSharp(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags)
{}
// Добавление операторов в тело метода
void MethodCSharp::add(const std::shared_ptr<Unit>& unit, Flags)
{
    m_body.push_back(unit);
}

std::string MethodCSharp::compile(unsigned int level) const
{
    std::string result = generateShift(level);
// Проверка и добавление модификаторов
    if (m_flags & ASYNC)    result += "async ";
    if (m_flags & STATIC)   result += "static ";
    if (m_flags & VIRTUAL)  result += "virtual ";
    if (m_flags & ABSTRACT) result += "abstract ";
    if (m_flags & OVERRIDE) result += "override ";

    result += m_returnType + " ";
    result += m_name + "()";

    if (m_flags & ABSTRACT) {
        result += ";\n";// Абстрактный метод заканчивается точкой с запятой
    } else {
        result += "\n" + generateShift(level) + "{\n";// Начало тела метода
        for (const auto& b : m_body) {
            result += b->compile(level + 1);// Компиляция операторов
        }
        result += generateShift(level) + "}\n";// Закрытие метода
    }

    return result;
}
