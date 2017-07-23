#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>

#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    auto f = a.font();
//    f.setPixelSize(16);
//    a.setFont(f);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return a.exec();
}
