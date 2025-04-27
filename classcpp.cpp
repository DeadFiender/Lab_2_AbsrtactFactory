#include "ClassCpp.h"
#include <vector>
// Инициализация статического вектора модификаторов доступа
const std::vector<std::string> ClassCpp::ACCESS_MODIFIERS = {"public", "protected", "private"};

ClassCpp::ClassCpp(const std::string &name, Flags)// Конструктор класса ClassCpp
    :m_name(name) // Инициализация имени класса
{
    m_fields.resize(ACCESS_MODIFIERS.size());// Резервируем место для трёх групп методов (public, protected, private)
}
// Метод добавления элемента в класс
void ClassCpp::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;// По умолчанию элементы добавляются в private секцию
    if(flags < ACCESS_MODIFIERS.size()) {//Если передан корректный флаг доступа (0, 1 или 2), то используем его
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);// Добавляем метод (unit) в соответствующую секцию (public/protected/private)
}
// Метод компиляции класса в текст
std::string ClassCpp::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " {\n";// Начинаем объявление класса
    for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {// Проходим по всем секциям доступа
        if(m_fields[i].empty()) {// Пропускаем пустые секции
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";// Добавляем модификатор доступа (public:/protected:/private:) с переносом строки
        for(const auto& f: m_fields[i]) {// Проходим по каждому элементу (методу) внутри этой секции
            result += f->compile(level + 1);// Компилируем метод/элемент и увеличиваем уровень вложенности (чтобы были правильные отступы)
        }
        result += "\n";// Переход строки между секциями
    }
    result += generateShift(level) + "};\n";// Закрываем класс
    return result;// Возвращаем собранный код
}
