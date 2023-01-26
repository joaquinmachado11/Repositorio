QT -= gui
QT += gui widgets
LIBS += -lOpenGL32
CONFIG += c++11 console qt
CONFIG -= app_bundle

#TEMPLATE = app
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        algoritmopintor.cpp \
        archivo.cpp \
        archivoaic.cpp \
        archivopnm.cpp \
        editor.cpp \
        espaciodetrabajo.cpp \
        filtro.cpp \
        gestordearchivos.cpp \
        graficador.cpp \
        histograma.cpp \
        imagen.cpp \
        interfaz.cpp \
        lut.cpp \
        main.cpp \
        mediana.cpp \
        pixel.cpp \
        procesadorestadistico.cpp \
        realcedebordes.cpp \
        suavizado.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    algoritmopintor.h \
    archivo.h \
    archivoaic.h \
    archivopnm.h \
    editor.h \
    espaciodetrabajo.h \
    filtro.h \
    gestordearchivos.h \
    graficador.h \
    histograma.h \
    imagen.h \
    interfaz.h \
    lut.h \
    mediana.h \
    pixel.h \
    procesadorestadistico.h \
    realcedebordes.h \
    suavizado.h
