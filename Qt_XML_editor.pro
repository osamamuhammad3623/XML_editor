QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI_Functions.cpp \
    common.cpp \
    consistency.cpp \
    format.cpp \
    main.cpp \
    mainwindow.cpp \
    minify.cpp \
    networkVisual.cpp

HEADERS += \
    GUI_Functions.h \
    common.h \
    consistency.h \
    format.h \
    mainwindow.h \
    minify.h \
    networkVisual.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
