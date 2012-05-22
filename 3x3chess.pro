#-------------------------------------------------
#
# Project created by QtCreator 2012-05-10T22:47:34
#
#-------------------------------------------------

QT       += core gui

TARGET = 3x3chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chesspiece.cpp \
    player.cpp \
    bishop.cpp \
    pawn.cpp \
    king.cpp \
    global.cpp \
    game.cpp \
    dragablelabel.cpp \
    pawnlabel.cpp \
    bishoplabel.cpp \
    kinglabel.cpp \
    node.cpp \
    ai.cpp \
    boardstate.cpp

HEADERS  += mainwindow.h \
    chesspiece.h \
    player.h \
    bishop.h \
    pawn.h \
    king.h \
    global.h \
    game.h \
    dragablelabel.h \
    pawnlabel.h \
    bishoplabel.h \
    kinglabel.h \
    node.h \
    ai.h \
    boardstate.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    qresource.qrc
