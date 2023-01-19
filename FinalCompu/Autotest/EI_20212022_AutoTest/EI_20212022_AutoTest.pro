QT += testlib
QT -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    ../../ProcesamientoDigital/archivo.cpp \
    ../../ProcesamientoDigital/archivoaic.cpp \
    ../../ProcesamientoDigital/archivopnm.cpp \
    ../../ProcesamientoDigital/editorimagen.cpp \
    ../../ProcesamientoDigital/filtro.cpp \
    ../../ProcesamientoDigital/filtromediana.cpp \
    ../../ProcesamientoDigital/filtrosuavizado.cpp \
    ../../ProcesamientoDigital/gestordearchivos.cpp \
    ../../ProcesamientoDigital/imagen.cpp \
    ../../ProcesamientoDigital/lut.cpp \
    ../../ProcesamientoDigital/pixel.cpp \
    ../../ProcesamientoDigital/procesadorestadistico.cpp
HEADERS += \
    ../../ProcesamientoDigital/archivo.h \
    ../../ProcesamientoDigital/archivoaic.h \
    ../../ProcesamientoDigital/archivopnm.h \
    ../../ProcesamientoDigital/editorimagen.h \
    ../../ProcesamientoDigital/filtro.h \
    ../../ProcesamientoDigital/filtromediana.h \
    ../../ProcesamientoDigital/filtrosuavizado.h \
    ../../ProcesamientoDigital/gestordearchivos.h \
    ../../ProcesamientoDigital/imagen.h \
    ../../ProcesamientoDigital/lut.h \
    ../../ProcesamientoDigital/pixel.h \
    ../../ProcesamientoDigital/procesadorestadistico.h
