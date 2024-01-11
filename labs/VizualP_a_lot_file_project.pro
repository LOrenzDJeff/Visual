QT       += core gui widgets datavisualization 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    Bresenham.cpp \
    colors.cpp \
    main.cpp \
    mainwindow.cpp \
    map_heat.cpp \
    material.cpp \
    math.cpp

HEADERS += \
    Bresenham.h \
    colors.h \
    mainwindow.h \
    map_heat.h \
    material.h \
    math.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
