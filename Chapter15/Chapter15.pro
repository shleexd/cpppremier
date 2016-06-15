TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    quote.cpp \
    bulk_quote.cpp

HEADERS += \
    quote.h \
    bulk_quote.h
