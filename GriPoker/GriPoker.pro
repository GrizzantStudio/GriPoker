#-------------------------------------------------
#
# Project created by QtCreator 2015-03-21T10:48:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GriPoker
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    UpgradeProbaTableView.cpp \
    UpgradeProbaTableModel.cpp \
    Card.cpp \
    Deck.cpp \
    Hand.cpp \
    Game.cpp \
    Dealer.cpp

HEADERS  += MainWindow.h \
    UpgradeProbaTableView.h \
    UpgradeProbaTableModel.h \
    Card.h \
    Deck.h \
    Hand.h \
    Game.h \
    Dealer.h

FORMS    += MainWindow.ui
