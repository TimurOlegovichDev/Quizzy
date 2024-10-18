QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += window/ \
               controller/ \
               enum/ \
               model/

SOURCES += \
    app.cpp \
    controller/maincontroller.cpp \
    model/windowrequest.cpp \
    window/mainwindow.cpp \
    window/redactwindow.cpp

HEADERS += \
    controller/maincontroller.h \
    enum/Statement.h \
    model/windowrequest.h \
    window/mainwindow.h \
    window/redactwindow.h

FORMS += \
    window/mainwindow.ui \
    window/redactwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
        resourses.qrc
