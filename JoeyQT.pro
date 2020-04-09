TEMPLATE = app
TARGET = JoeyQT
DEPENDPATH += .
INCLUDEPATH += .


win32 {
    QMAKE_LFLAGS += -static
    QT += network widgets winextras
}

unix {
    QT += network widgets
}

RESOURCES += qdarkstyle/style.qrc

# Input
HEADERS += \
           include/libusb-1.0/libusb.h \
           src/Console.h \
           src/Device.h \
           src/const.h \
           src/Gui.h \
           src/Settings.h \
           src/icon.xpm
SOURCES += \
           src/Device.cpp \
           src/JoeyQT.cpp \
           src/Gui.cpp \
           src/Settings.cpp
RC_FILE = src/res.rc

DISTFILES += \
    src/icon.xpm

win32: LIBS += -LD:\OneDrive\Dokumenter\GitHub\JoeyQT\LIBS/ -llibusb-1.0
