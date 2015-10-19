TEMPLATE = app
CONFIG += c++11
QT += qml quick widgets declarative svg
QTPLUGIN += qsvg
HEADERS += \
    piece.h \
    chessboard.h \
    knight.h \
    pawn.h \
    bishop.h \
    rook.h \
    queen.h \
    king.h \
    emptypiece.h \
    move.h

SOURCES += main.cpp \
    piece.cpp \
    chessboard.cpp \
    knight.cpp \
    pawn.cpp \
    bishop.cpp \
    rook.cpp \
    queen.cpp \
    king.cpp \
    emptypiece.cpp \
    move.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)


