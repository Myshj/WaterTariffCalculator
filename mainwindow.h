#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

#include "session.h"
#include "statisticswindow.h"

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

    void on_quit_triggered();

    void on_open_triggered();

    void on_save_triggered();

    void on_newSession_triggered();

    void on_oldLessThen40SpinBox_valueChanged(double arg1);

    void on_oldFrom45To49SpinBox_valueChanged(double arg1);

    void on_oldFrom40To44SpinBox_valueChanged(double arg1);

    void on_oldGreaterThen50SpinBox_valueChanged(double arg1);

    void on_showStatistics_triggered(bool checked);

private:
    void renderCurrentSession();
    void bindControlsToCurrentSession();

    void saveCurrentSession(const QString& saveFileName);
    void loadSession(const QString& saveFileName);

    void loadDefaultSession();

    Ui::MainWindow *ui;
    StatisticsWindow statisticsWindow;

    QSharedPointer<Session> currentSession;
};

#endif // MAINWINDOW_H
