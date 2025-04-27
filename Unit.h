#ifndef UNIT_H
#define UNIT_H

#include <memory>// Для shared_ptr
#include <string>

class Unit {// Базовый абстрактный класс, представляющий элемент кода
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATEPROTECTED,
        FILE,
        INTERNAL,
        PROTECTEDINTERNAL
    };
    enum Modifier {
        STATIC = 1,
        VIRTUAL = 1 << 1,
        CONST = 1 << 2,
        ABSTRACT = 1 << 3,
        FINAL = 1 << 4
    };
public:
    using Flags = unsigned int;// Тип для хранения флагов модификаторов
public:
    virtual ~Unit() = default;// Виртуальный деструктор для корректного удаления потомков
    // Виртуальный метод добавления вложенного элемента
    // По умолчанию выбрасывает исключение — не все элементы могут содержать вложенные элементы
    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile( unsigned int level = 0 ) const = 0;// Чисто виртуальный метод компиляции элемента в текст
protected:
    virtual std::string generateShift( unsigned int level ) const
      // Вспомогательная функция генерации отступов в зависимости от уровня вложенности
    {
        static const auto DEFAULT_SHIFT = " ";// Базовый отступ — 1 пробел
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;// Добавляем пробелы столько раз, каков уровень вложенности
        }
        return result;// Возвращаем итоговую строку отступов
    }
};
#endif // UNIT_H
