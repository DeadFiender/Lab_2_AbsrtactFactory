QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        classcpp.cpp \
        classcsharp.cpp \
        classjava.cpp \
        main.cpp \
        methodcpp.cpp \
        methodcsharp.cpp \
        methodjava.cpp \
        printoperatorcpp.cpp \
        printoperatorcsharp.cpp \
        printoperatorjava.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CodeFactoryCSharp.h \
    CodeFactoryCpp.h \
    CodeFactoryJava.h \
    ICodefactory.h \
    Unit.h \
    classcpp.h \
    classcsharp.h \
    classjava.h \
    methodcpp.h \
    methodcsharp.h \
    methodjava.h \
    printoperatorcpp.h \
    printoperatorcsharp.h \
    printoperatorjava.h
