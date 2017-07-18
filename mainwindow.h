#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>

#include "extendedmeterreadinginputsession.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void calculateAll();

private:

    Ui::MainWindow *ui;

    QPointer<ExtendedMeterReadingInputSession> inputSession;
};

#endif // MAINWINDOW_H
