QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../21_check_if_ok.c \
    ../21_deep_parsers.c \
    ../21_helpers.c \
    ../21_lil.c \
    ../21_stack_num.c \
    ../21_stack_sym.c \
    ../21_str_parser.c \
    ../21_str_unparser.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp


HEADERS += \
    ../calc.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
