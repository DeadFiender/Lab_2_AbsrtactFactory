#ifndef CLASSCPP_H
#define CLASSCPP_H

#include <vector>
#include "Unit.h"

class ClassCpp : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    // Статический вектор строк с текстовыми представлениями модификаторов
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    // Конструктор класса: принимает имя класса и флаги
    ClassCpp(const std::string &name, Flags modifier = 0);
    // Метод добавления вложенного элемента в класс (например, метода)
    void add(const std::shared_ptr<Unit> &unit, Flags flags) override;
    // Метод генерации текста класса
    std::string compile(unsigned int level = 0) const override;
private:
    std::string m_name;// Имя класса
    using Fields = std::vector<std::shared_ptr<Unit>>;// Псевдоним для списка элементов (методов)
    std::vector<Fields> m_fields;// Вектор векторов: методы сгруппированы по модификатору доступа
};

#endif // CLASSCPP_H
