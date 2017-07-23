#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include <QtDebug>
#include <QSharedPointer>
#include <QDoubleSpinBox>

#include <QJsonDocument>
#include <QFile>
#include <QString>
#include "jsonutilities.h"

#include "doublenumber.h"

#include "connectors/doublespinboxtonumberconnector.h"
#include "connectors/doublenumbertospinboxconnector.h"
#include "connectors/doublespinboxestoextendedmeterreadingconnector.h"
#include "connectors/extendedmeterreadingtodoublespinboxesconnector.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    statisticsWindow(this)
{
    ui->setupUi(this);
    loadDefaultSession();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::bindControlsToCurrentSession()
{
    auto inputSession = currentSession.data()->getInput();

    auto sessionChange = inputSession->getChange();

    auto newData = sessionChange->getNewData();
    DoubleSpinboxesToExtendedMeterReadingConnector::connect(
                *ui->currentLessThen40SpinBox,
                *ui->currentFrom40To44SpinBox,
                *ui->currentFrom45To49SpinBox,
                *ui->currentGreaterThen50SpinBox,
                *newData
    );

    auto oldData = sessionChange->getOldData();
    DoubleSpinboxesToExtendedMeterReadingConnector::connect(
                *ui->oldLessThen40SpinBox,
                *ui->oldFrom40To44SpinBox,
                *ui->oldFrom45To49SpinBox,
                *ui->oldGreaterThen50SpinBox,
                *oldData
    );

    auto consumedVolume = currentSession->getConsumed();
    ExtendedMeterReadingToDoubleSpinBoxesConnector::connect(
                *consumedVolume,
                *ui->lessThen40VolumeSpinBox,
                *ui->from40To44VolumeSpinBox,
                *ui->from45To49VolumeSpinBox,
                *ui->greaterThen50VolumeSpinBox
    );

    auto tariffs = inputSession->getTariffs();
    DoubleSpinBoxToNumberConnector::connect(*ui->heatedWaterTariffSpinBox, *tariffs->getHeated());
    DoubleSpinBoxToNumberConnector::connect(*ui->coldWaterTariffSpinBox, *tariffs->getCold());

    auto price = currentSession->getPrice();
    DoubleNumberToSpinBoxConnector::connect(*price, *ui->toPaySpinBox);

    auto correctedHeatedVolume = currentSession.data()->getCorrectedHeatedVolume();
    DoubleNumberToSpinBoxConnector::connect(*correctedHeatedVolume, *ui->giocSpinBox);
}

void MainWindow::saveCurrentSession(const QString& saveFileName)
{
    auto savedSession = JsonUtilities::saveSession(*currentSession);

    QFile saveFile(saveFileName);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonDocument saveDocument(savedSession);
    saveFile.write(saveDocument.toJson());
}

void MainWindow::loadSession(const QString& saveFileName)
{
    QFile saveFile(saveFileName);

    if (!saveFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonDocument saveDocument(QJsonDocument::fromJson(saveFile.readAll()));
    QJsonObject savedSession = saveDocument.object();

    currentSession = QSharedPointer<Session>(JsonUtilities::loadSession(savedSession));

    renderCurrentSession();
    bindControlsToCurrentSession();
}

void MainWindow::loadDefaultSession()
{
    currentSession = QSharedPointer<Session>::create();
    renderCurrentSession();
    bindControlsToCurrentSession();
}

void MainWindow::renderCurrentSession()
{
    auto inputSession = currentSession->getInput();

    auto sessionChange = inputSession->getChange();

    auto oldData = sessionChange->getOldData();
    ui->oldLessThen40SpinBox->setValue(oldData->getLessThen40()->getValue());
    ui->oldFrom40To44SpinBox->setValue(oldData->getFrom40To44()->getValue());
    ui->oldFrom45To49SpinBox->setValue(oldData->getFrom45To49()->getValue());
    ui->oldGreaterThen50SpinBox->setValue(oldData->getGreaterThen50()->getValue());

    auto newData = sessionChange->getNewData();
    ui->currentLessThen40SpinBox->setValue(newData->getLessThen40()->getValue());
    ui->currentFrom40To44SpinBox->setValue(newData->getFrom40To44()->getValue());
    ui->currentFrom45To49SpinBox->setValue(newData->getFrom45To49()->getValue());
    ui->currentGreaterThen50SpinBox->setValue(newData->getGreaterThen50()->getValue());

    auto consumed = currentSession->getConsumed();
    ui->lessThen40VolumeSpinBox->setValue(consumed->getLessThen40()->getValue());
    ui->from40To44VolumeSpinBox->setValue(consumed->getFrom40To44()->getValue());
    ui->from45To49VolumeSpinBox->setValue(consumed->getFrom45To49()->getValue());
    ui->greaterThen50VolumeSpinBox->setValue(consumed->getGreaterThen50()->getValue());

    auto tariffs = inputSession->getTariffs();
    ui->heatedWaterTariffSpinBox->setValue(tariffs->getHeated()->getValue());
    ui->coldWaterTariffSpinBox->setValue(tariffs->getCold()->getValue());

    auto price = currentSession->getPrice();
    ui->toPaySpinBox->setValue(price->getValue());

    auto correctedHeatedVolume = currentSession->getCorrectedHeatedVolume();
    ui->giocSpinBox->setValue(correctedHeatedVolume->getValue());
}

void MainWindow::on_quit_triggered()
{
    qDebug() << "quit requested";
    close();
}

void MainWindow::on_open_triggered()
{
    auto saveFileName = QFileDialog::getOpenFileName(
                this,
                tr("Открыть сессию"),
                "",
                tr("Сессии (*.json);; Все (*)")
    );
    if (!saveFileName.isNull())
    {
        loadSession(saveFileName);
    }
}

void MainWindow::on_save_triggered()
{
    auto saveFileName = QFileDialog::getSaveFileName(
                this,
                tr("Сохранить сессию"),
                "",
                tr("Сессии (*json);; Все (*)")
    );
    if (!saveFileName.isNull())
    {
        if (!saveFileName.endsWith(".json", Qt::CaseSensitivity::CaseInsensitive))
        {
            saveFileName.append(".json");
        }
        saveCurrentSession(saveFileName);
    }
}

void MainWindow::on_newSession_triggered()
{
    loadDefaultSession();
}

void MainWindow::on_oldLessThen40SpinBox_valueChanged(double arg1)
{
    ui->currentLessThen40SpinBox->setMinimum(arg1);
}

void MainWindow::on_oldFrom45To49SpinBox_valueChanged(double arg1)
{
    ui->currentFrom45To49SpinBox->setMinimum(arg1);
}

void MainWindow::on_oldFrom40To44SpinBox_valueChanged(double arg1)
{
    ui->currentFrom40To44SpinBox->setMinimum(arg1);
}

void MainWindow::on_oldGreaterThen50SpinBox_valueChanged(double arg1)
{
    ui->currentGreaterThen50SpinBox->setMinimum(arg1);
}

#include "statisticswindow.h"

void MainWindow::on_showStatistics_triggered(bool checked)
{
    qDebug() << "statistics requested";
    statisticsWindow.show();
}
