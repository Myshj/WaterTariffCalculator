#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>

#include "session.h"

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
    void on_saveButton_clicked();

private:

    Ui::MainWindow *ui;

    QPointer<Session> currentSession;
};

#endif // MAINWINDOW_H
