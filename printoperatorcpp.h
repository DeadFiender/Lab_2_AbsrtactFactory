#ifndef PRINTOPERATORCPP_H
#define PRINTOPERATORCPP_H

#include "Unit.h"

class PrintOperatorCpp : public Unit// Класс, представляющий оператор печати в C++
{
public:
    PrintOperatorCpp(const std::string &text);// Конструктор принимает текст для печати
    std::string compile(unsigned int level = 0) const override;// Метод компиляции оператора в текст
private:
    std::string m_text;// Текст, который нужно напечатать
};

#endif // PRINTOPERATORCPP_H
