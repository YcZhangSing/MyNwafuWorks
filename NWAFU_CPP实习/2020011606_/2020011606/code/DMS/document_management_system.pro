QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addauthor.cpp \
    adddocumentspage.cpp \
    data.cpp \
    docnamepage.cpp \
    editauthorpage.cpp \
    editdocpage.cpp \
    main.cpp \
    mainwindow.cpp \
    managepage.cpp \
    objects.cpp \
    searchpage.cpp \
    showdocpage.cpp

HEADERS += \
    addauthor.h \
    adddocumentspage.h \
    data.h \
    docnamepage.h \
    editauthorpage.h \
    editdocpage.h \
    mainwindow.h \
    managepage.h \
    objects.h \
    searchpage.h \
    showdocpage.h

FORMS += \
    addauthor.ui \
    adddocumentspage.ui \
    docnamepage.ui \
    editauthorpage.ui \
    editdocpage.ui \
    mainwindow.ui \
    managepage.ui \
    searchpage.ui \
    showdocpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICO = log.ico

DISTFILES +=

RESOURCES += \
    icons.qrc \
    sound.qrc
