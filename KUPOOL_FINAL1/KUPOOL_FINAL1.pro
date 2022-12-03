QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    gui.cpp \
    homepage.cpp \
    information.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    admin.h \
    gui.h \
    homepage.h \
    information.h \
    mainwindow.h

FORMS += \
    admin.ui \
    gui.ui \
    homepage.ui \
    information.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
