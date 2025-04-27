#include "printoperatorcpp.h"

PrintOperatorCpp::PrintOperatorCpp(const std::string &text)// Конструктор инициализирует текст для печати
    : m_text(text)
{}

std::string PrintOperatorCpp::compile(unsigned int level) const// Метод компиляции оператора в текст
{
    return generateShift(level) + "printf(\"" + m_text + "\");\n";// Генерация отступа и команды printf с текстом
}
