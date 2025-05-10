#include "ClassCSharp.h"
// Инициализация текстовых представлений модификаторов доступа
const std::vector<std::string> ClassCSharp::ACCESS_MODIFIERS = {
    "public", "protected", "private", "internal", "file", "private protected", "protected internal"
};

ClassCSharp::ClassCSharp(const std::string& name, Flags)// Конструктор класса
    : m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());// Резервируем место для модификаторов
}

void ClassCSharp::add(const std::shared_ptr<Unit>& unit, Flags flags)
// Метод добавления элемента (метода или поля) в класс
{
    int accessModifier = PRIVATE;// По умолчанию private
    if (flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);// Добавляем метод в соответствующую группу
}
// Метод компиляции класса
std::string ClassCSharp::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + "\n{\n";
    // Проход по каждой группе модификаторов
    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        for (const auto& f : m_fields[i]) {//Для каждого метода или элемента f в текущей секции (public, protected и т.д.) выполняем обработку.
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " ";
            std::string compiled = f->compile(level + 1);
            // Убираем лишние пробелы в начале вложенного кода
            size_t spacePos = compiled.find_first_not_of(" \t");
            if (spacePos != std::string::npos)
                compiled = compiled.substr(spacePos);
            result += compiled;
        }
    }
    result += generateShift(level) + "}\n";
    return result;
}
