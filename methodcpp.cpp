#include "methodcpp.h"
// Конструктор метода
MethodCpp::MethodCpp(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags)
{}
// Метод добавления вложенных операторов в тело метода
void MethodCpp::add(const std::shared_ptr<Unit>& unit, Flags)
{
    m_body.push_back(unit);// Просто добавляем оператор в тело
}
// Метод компиляции метода
std::string MethodCpp::compile(unsigned int level) const
{
    std::string result = generateShift(level);// Генерация отступа
    if(m_flags & STATIC) {// Проверяем и добавляем модификаторы
        result += "static ";
    } else if(m_flags & VIRTUAL) {
        result += "virtual ";
    }
    result += m_returnType + " ";// Возвращаемый тип
    result += m_name + "()";// Имя метода и параметры (пустые)
    if(m_flags & CONST) {// Если метод константный, добавляем const
        result += " const";
    }
    result += " {\n";// Открытие тела метода
    for(const auto& b: m_body) {// Компиляция всех операторов в теле метода
        result += b->compile(level + 1);// Увеличение вложенности
    }
    result += generateShift(level) + "}\n";// Закрытие метода
    return result;// Возвращаем собранный текст
}
