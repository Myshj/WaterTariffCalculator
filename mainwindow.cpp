#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    currentSession(new Session())
{
    ui->setupUi(this);
    renderCurrentSession();
    bindControlsToCurrentSession();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveButton_clicked()
{
    saveCurrentSession();
}

void MainWindow::bindControlsToCurrentSession()
{
    auto inputSession = currentSession.data()->getInput();

    auto sessionChange = inputSession.data()->getChange().data();

    auto newData = sessionChange->getNewData().data();
    DoubleSpinboxesToExtendedMeterReadingConnector::connect(
                *ui->currentLessThen40SpinBox,
                *ui->currentFrom40To44SpinBox,
                *ui->currentFrom45To49SpinBox,
                *ui->currentGreaterThen50SpinBox,
                *newData
    );

    auto oldData = sessionChange->getOldData().data();
    DoubleSpinboxesToExtendedMeterReadingConnector::connect(
                *ui->oldLessThen40SpinBox,
                *ui->oldFrom40To44SpinBox,
                *ui->oldFrom45To49SpinBox,
                *ui->oldGreaterThen50SpinBox,
                *oldData
    );

    auto consumedVolume = currentSession->getConsumed().data();
    ExtendedMeterReadingToDoubleSpinBoxesConnector::connect(
                *consumedVolume,
                *ui->lessThen40VolumeSpinBox,
                *ui->from40To44VolumeSpinBox,
                *ui->from45To49VolumeSpinBox,
                *ui->greaterThen50VolumeSpinBox
    );

    auto tariffs = inputSession.data()->getTariffs().data();
    DoubleSpinBoxToNumberConnector::connect(*ui->heatedWaterTariffSpinBox, *tariffs->getHeated());
    DoubleSpinBoxToNumberConnector::connect(*ui->coldWaterTariffSpinBox, *tariffs->getCold());

    auto price = currentSession.data()->getPrice().data();
    DoubleNumberToSpinBoxConnector::connect(*price, *ui->toPaySpinBox);

    auto correctedHeatedVolume = currentSession.data()->getCorrectedHeatedVolume().data();
    DoubleNumberToSpinBoxConnector::connect(*correctedHeatedVolume, *ui->giocSpinBox);
}

void MainWindow::saveCurrentSession()
{
    auto savedSession = JsonUtilities::saveSession(*currentSession);

    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonDocument saveDocument(savedSession);
    saveFile.write(saveDocument.toJson());
}

void MainWindow::loadSession()
{
    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonDocument saveDocument(QJsonDocument::fromJson(saveFile.readAll()));
    QJsonObject savedSession = saveDocument.object();

    currentSession =JsonUtilities::loadSession(savedSession);

    renderCurrentSession();
    bindControlsToCurrentSession();
}

void MainWindow::on_loadButton_clicked()
{
    loadSession();
}

void MainWindow::renderCurrentSession()
{
    auto inputSession = currentSession->getInput().data();

    auto sessionChange = inputSession->getChange().data();

    auto newData = sessionChange->getNewData().data();
    ui->currentLessThen40SpinBox->setValue(newData->getLessThen40()->getValue());
    ui->currentFrom40To44SpinBox->setValue(newData->getFrom40To44()->getValue());
    ui->currentFrom45To49SpinBox->setValue(newData->getFrom45To49()->getValue());
    ui->currentGreaterThen50SpinBox->setValue(newData->getGreaterThen50()->getValue());

    auto oldData = sessionChange->getOldData().data();
    ui->oldLessThen40SpinBox->setValue(oldData->getLessThen40()->getValue());
    ui->oldFrom40To44SpinBox->setValue(oldData->getFrom40To44()->getValue());
    ui->oldFrom45To49SpinBox->setValue(oldData->getFrom45To49()->getValue());
    ui->oldGreaterThen50SpinBox->setValue(oldData->getGreaterThen50()->getValue());

    auto consumed = currentSession->getConsumed().data();
    ui->lessThen40VolumeSpinBox->setValue(consumed->getLessThen40()->getValue());
    ui->from40To44VolumeSpinBox->setValue(consumed->getFrom40To44()->getValue());
    ui->from45To49VolumeSpinBox->setValue(consumed->getFrom45To49()->getValue());
    ui->greaterThen50VolumeSpinBox->setValue(consumed->getGreaterThen50()->getValue());

    auto tariffs = inputSession->getTariffs().data();
    ui->heatedWaterTariffSpinBox->setValue(tariffs->getHeated()->getValue());
    ui->coldWaterTariffSpinBox->setValue(tariffs->getCold()->getValue());

    auto price = currentSession->getPrice().data();
    ui->toPaySpinBox->setValue(price->getValue());

    auto correctedHeatedVolume = currentSession->getCorrectedHeatedVolume().data();
    ui->giocSpinBox->setValue(correctedHeatedVolume->getValue());
}
