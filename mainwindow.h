#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

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

    void on_loadButton_clicked();

private:
    void renderCurrentSession();
    void bindControlsToCurrentSession();

    void saveCurrentSession();
    void loadSession();

    Ui::MainWindow *ui;

    QSharedPointer<Session> currentSession;
};

#endif // MAINWINDOW_H
