QT += gui core

CONFIG += c++11

TARGET = ProjectedTexture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    projtex.cpp \
    teapot.cpp    

HEADERS += \
    projtex.h \
    teapotdata.h \
    teapot.h    
	
OTHER_FILES += \
    fshader.txt \
    vshader.txt

RESOURCES += \
    shaders.qrc

DISTFILES += \
    fshader.txt \
    vshader.txt
