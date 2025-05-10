#ifndef CLASSCSHARP_H
#define CLASSCSHARP_H

#include <vector>
#include "Unit.h"

class ClassCSharp : public Unit {// Класс для генерации кода классов на языке C#
public:
    enum AccessModifier { PUBLIC, PROTECTED, PRIVATE, INTERNAL, FILE,
                          PROTECTEDINTERNAL, PRIVATEPROTECTED };// Дополнительный модификатор, характерный для C#
    static const std::vector<std::string> ACCESS_MODIFIERS;// Статический вектор строк с текстовыми представлениями модификаторов

    ClassCSharp(const std::string& name, Flags flags = 0);// Конструктор принимает имя класса и флаги
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;// Метод добавления метода или поля в класс
    std::string compile(unsigned int level = 0) const override;// Метод компиляции класса в текстовый вид

private:
    std::string m_name;// Имя класса
    std::vector<std::vector<std::shared_ptr<Unit>>> m_fields;// Методы сгруппированы по модификатору
};

#endif // CLASSCSHARP_H

