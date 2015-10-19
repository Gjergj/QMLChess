//#include "piece.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QStandardPaths>
#include <QQmlContext>
#include <QQmlEngine>
#include <QtQml>
#include <QtWidgets/QApplication>
#include <QQuickView>
#include "chessboard.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ChessBoard board;
    board.Initialise();
    QQmlApplicationEngine engine;

    QUrl appPath(QString("%1").arg(app.applicationDirPath()));
    engine.rootContext()->setContextProperty("appPath", appPath);
    engine.rootContext()->setContextProperty("chessModel", &board);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
