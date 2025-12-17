QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Person.cpp \
    Student.cpp \
    Seller.cpp \
    studentdialog.cpp \
    sellerdialog.cpp \
    studentlistdialog.cpp \
    sellerlistdialog.cpp

HEADERS += \
    mainwindow.h \
    Person.h \
    Student.h \
    Seller.h \
    studentdialog.h \
    sellerdialog.h \
    studentlistdialog.h \
    sellerlistdialog.h

FORMS += \
    mainwindow.ui \
    studentdialog.ui \
    sellerdialog.ui \
    studentlistdialog.ui \
    sellerlistdialog.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
