QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../C7_SmartCalc_v1.0-1/src/smart_calc_controller.c \
    ../C7_SmartCalc_v1.0-1/src/modules/calculate.c \
    ../C7_SmartCalc_v1.0-1/src/modules/deposit_calc.c \
    ../C7_SmartCalc_v1.0-1/src/modules/input_validation.c \
    ../C7_SmartCalc_v1.0-1/src/modules/loan_calc.c \
    ../C7_SmartCalc_v1.0-1/src/modules/shunting_yard.c \
    ../C7_SmartCalc_v1.0-1/src/modules/stack.c \
    ../C7_SmartCalc_v1.0-1/src/modules/tokens_devider.c \
    credit.cpp \
    deposit.cpp \
    main.cpp \
    mainwindow.cpp \
    plot.cpp \
    qcustomplot.cpp \
    rpn.cpp

HEADERS += \
    ../C7_SmartCalc_v1.0-1/src/smart_calc_controller.h \
    ../C7_SmartCalc_v1.0-1/src/modules/headers/calculate.h \
    ../C7_SmartCalc_v1.0-1/src/modules/headers/deposit_calc.h \
    ../C7_SmartCalc_v1.0-1/src/modules/headers/input_validation.h \
    ../C7_SmartCalc_v1.0-1/src/modules/headers/loan_calc.h \
    ../C7_SmartCalc_v1.0-1/src/modules/headers/shunting_yard.h \
    ../C7_SmartCalc_v1.0-1/src/modules/headers/stack.h \
    ../C7_SmartCalc_v1.0-1/src/modules/headers/tokens_devider.h \
    credit.h \
    deposit.h \
    mainwindow.h \
    plot.h \
    qcustomplot.h \
    rpn.h

FORMS += \
    credit.ui \
    deposit.ui \
    mainwindow.ui \
    plot.ui \
    rpn.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    fonts.qrc \
    resourses.qrc

DISTFILES +=
