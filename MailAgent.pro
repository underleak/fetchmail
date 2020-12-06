QT       += core gui
QT += charts
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    database.cpp \
    main.cpp \
    login.cpp \
    messages.cpp \
    registration.cpp \
    statistics.cpp

HEADERS += \
    admin.h \
    database.h \
    login.h \
    messages.h \
    registration.h \
    statistics.h

FORMS += \
    admin.ui \
    login.ui \
    messages.ui \
    registration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
