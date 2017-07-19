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
    qDebug() << "Save requested!";

    saveCurrentSession();

    //qDebug() << savedSession;
}

void MainWindow::bindControlsToCurrentSession()
{
    auto inputSession = currentSession.data()->getInput();

    auto sessionChange = inputSession.data()->getChange().data();

    auto newData = sessionChange->getNewData().data();
    connect(ui->currentLessThen40SpinBox, SIGNAL(valueChanged(const double)), newData->getLessThen40().data(), SLOT(setValue(const double)));
    connect(ui->currentFrom40To44SpinBox, SIGNAL(valueChanged(const double)), newData->getFrom40To44().data(), SLOT(setValue(const double)));
    connect(ui->currentFrom45To49SpinBox, SIGNAL(valueChanged(const double)), newData->getFrom45To49().data(), SLOT(setValue(const double)));
    connect(ui->currentGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), newData->getGreaterThen50().data(), SLOT(setValue(const double)));

    auto oldData = sessionChange->getOldData().data();
    connect(ui->oldLessThen40SpinBox, SIGNAL(valueChanged(const double)), oldData->getLessThen40().data(), SLOT(setValue(const double)));
    connect(ui->oldFrom40To44SpinBox, SIGNAL(valueChanged(const double)), oldData->getFrom40To44().data(), SLOT(setValue(const double)));
    connect(ui->oldFrom45To49SpinBox, SIGNAL(valueChanged(const double)), oldData->getFrom45To49().data(), SLOT(setValue(const double)));
    connect(ui->oldGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), oldData->getGreaterThen50().data(), SLOT(setValue(const double)));

    auto tariffs = inputSession.data()->getTariffs().data();
    connect(ui->heatedWaterTariffSpinBox, SIGNAL(valueChanged(const double)), tariffs->getHeated().data(), SLOT(setValue(const double)));
    connect(ui->coldWaterTariffSpinBox, SIGNAL(valueChanged(const double)), tariffs->getCold().data(), SLOT(setValue(const double)));

    auto price = currentSession.data()->getPrice().data();
    connect(price, &DoubleNumber::valueChanged, ui->toPaySpinBox, &QDoubleSpinBox::setValue);

    auto correctedHeatedVolume = currentSession.data()->getCorrectedHeatedVolume().data();
    connect(correctedHeatedVolume, &DoubleNumber::valueChanged, ui->giocSpinBox, &QDoubleSpinBox::setValue);
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

    //qDebug() << savedSession;

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

//    connect(ui->currentLessThen40SpinBox, SIGNAL(valueChanged(const double)), newData->getLessThen40().data(), SLOT(setValue(const double)));
//    connect(ui->currentFrom40To44SpinBox, SIGNAL(valueChanged(const double)), newData->getFrom40To44().data(), SLOT(setValue(const double)));
//    connect(ui->currentFrom45To49SpinBox, SIGNAL(valueChanged(const double)), newData->getFrom45To49().data(), SLOT(setValue(const double)));
//    connect(ui->currentGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), newData->getGreaterThen50().data(), SLOT(setValue(const double)));

    auto oldData = sessionChange->getOldData().data();
    ui->oldLessThen40SpinBox->setValue(oldData->getLessThen40()->getValue());
    ui->oldFrom40To44SpinBox->setValue(oldData->getFrom40To44()->getValue());
    ui->oldFrom45To49SpinBox->setValue(oldData->getFrom45To49()->getValue());
    ui->oldGreaterThen50SpinBox->setValue(oldData->getGreaterThen50()->getValue());

//    connect(ui->oldLessThen40SpinBox, SIGNAL(valueChanged(const double)), oldData->getLessThen40().data(), SLOT(setValue(const double)));
//    connect(ui->oldFrom40To44SpinBox, SIGNAL(valueChanged(const double)), oldData->getFrom40To44().data(), SLOT(setValue(const double)));
//    connect(ui->oldFrom45To49SpinBox, SIGNAL(valueChanged(const double)), oldData->getFrom45To49().data(), SLOT(setValue(const double)));
//    connect(ui->oldGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), oldData->getGreaterThen50().data(), SLOT(setValue(const double)));

    auto tariffs = inputSession->getTariffs().data();
    ui->heatedWaterTariffSpinBox->setValue(tariffs->getHeated()->getValue());
    ui->coldWaterTariffSpinBox->setValue(tariffs->getCold()->getValue());

//    connect(ui->heatedWaterTariffSpinBox, SIGNAL(valueChanged(const double)), tariffs->getHeated().data(), SLOT(setValue(const double)));
//    connect(ui->coldWaterTariffSpinBox, SIGNAL(valueChanged(const double)), tariffs->getCold().data(), SLOT(setValue(const double)));

    auto price = currentSession->getPrice().data();
    ui->toPaySpinBox->setValue(price->getValue());

    //connect(price, &DoubleNumber::valueChanged, ui->toPaySpinBox, &QDoubleSpinBox::setValue);

    auto correctedHeatedVolume = currentSession->getCorrectedHeatedVolume().data();
    ui->giocSpinBox->setValue(correctedHeatedVolume->getValue());
    //connect(correctedHeatedVolume, &DoubleNumber::valueChanged, ui->giocSpinBox, &QDoubleSpinBox::setValue);
}
