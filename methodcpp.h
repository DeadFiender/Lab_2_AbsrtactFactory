#ifndef METHODCPP_H
#define METHODCPP_H

#include <vector>
#include "Unit.h"

class MethodCpp : public Unit// Класс, представляющий метод в классе C++
{
public:
    enum Modifier {
        STATIC = 1,// Статический метод
        CONST = 1 << 1,// Константный метод
        VIRTUAL = 1 << 2// Виртуальный метод
    };
public:
    MethodCpp(const std::string &name, const std::string& returnType, Flags flags = 0);// Конструктор метода
    void add(const std::shared_ptr<Unit> &unit, Flags) override;// Метод добавления операторов в тело метода
    std::string compile(unsigned int level = 0) const override;// Метод компиляции метода в текст
private:
    std::string m_name;// Имя метода
    std::string m_returnType;// Тип возвращаемого значения
    Flags m_flags;// Битовые флаги модификаторов
    std::vector<std::shared_ptr<Unit>> m_body;// Тело метода (список операторов)
};
#endif // METHODCPP_H
