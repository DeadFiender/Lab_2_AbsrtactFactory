#include "ClassJava.h"

const std::vector<std::string> ClassJava::ACCESS_MODIFIERS = {
    "public", "protected", "private"
};

ClassJava::ClassJava(const std::string& name, Flags)
    : m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void ClassJava::add(const std::shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if (flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string ClassJava::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "public class " + m_name + " {\n";
    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        for (const auto& f : m_fields[i]) {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " ";
            std::string compiled = f->compile(level + 1);
            size_t spacePos = compiled.find_first_not_of(" \t");
            if (spacePos != std::string::npos)
                compiled = compiled.substr(spacePos);
            result += compiled;
        }
    }
    result += generateShift(level) + "}\n";
    return result;
}
