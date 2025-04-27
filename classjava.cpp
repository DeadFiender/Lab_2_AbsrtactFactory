#include "ClassJava.h"

const std::vector<std::string> ClassJava::ACCESS_MODIFIERS = {
    "public", "protected", "private"
};
// Конструктор класса
ClassJava::ClassJava(const std::string& name, Flags)
    : m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}
// Добавление методов в класс
void ClassJava::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if (flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}
// Компиляция класса в текст
std::string ClassJava::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "public class " + m_name + " {\n";
    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        for (const auto& f : m_fields[i]) {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " ";
            std::string compiled = f->compile(level + 1);//Компилируем вложенный элемент (например, метод) через его compile()
            size_t spacePos = compiled.find_first_not_of(" \t");//После компиляции может оказаться, что метод уже имеет свои отступы.
            if (spacePos != std::string::npos)//Поэтому ищем первый непробельный символ (find_first_not_of(" \t")
                compiled = compiled.substr(spacePos);//Убираем лишние отступы с начала строки
            result += compiled;
        }
    }
    result += generateShift(level) + "}\n";
    return result;
}
