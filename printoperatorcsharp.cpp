#include "PrintOperatorCSharp.h"

PrintOperatorCSharp::PrintOperatorCSharp(const std::string& text)
    : m_text(text)
{}

std::string PrintOperatorCSharp::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
}

