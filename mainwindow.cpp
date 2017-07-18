#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QSharedPointer>

#include "doublenumber.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    inputSession(new ExtendedMeterReadingInputSession())
{
    ui->setupUi(this);

//    connect(ui->currentWaterSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
//    connect(ui->currentHeatedSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));

    auto sessionChange = inputSession.data()->getChange().data();

    auto newData = sessionChange->getNewData().data();
    connect(ui->currentLessThen40SpinBox, SIGNAL(valueChanged(const double)), newData->getLessThen40().data(), SLOT(setValue(const double)));
    connect(ui->currentFrom40To44SpinBox, SIGNAL(valueChanged(const double)), newData->getFrom40To44().data(), SLOT(setValue(const double)));
    connect(ui->currentFrom45To49SpinBox, SIGNAL(valueChanged(const double)), newData->getFrom45To49().data(), SLOT(setValue(const double)));
    connect(ui->currentGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), newData->getGreaterThen50().data(), SLOT(setValue(const double)));

    connect(newData->getLessThen40().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
    connect(newData->getFrom40To44().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
    connect(newData->getFrom45To49().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
    connect(newData->getGreaterThen50().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);

//    connect(ui->oldWaterSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
//    connect(ui->oldHeatedSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));

    auto oldData = sessionChange->getOldData().data();
    connect(ui->oldLessThen40SpinBox, SIGNAL(valueChanged(const double)), oldData->getLessThen40().data(), SLOT(setValue(const double)));
    connect(ui->oldFrom40To44SpinBox, SIGNAL(valueChanged(const double)), oldData->getFrom40To44().data(), SLOT(setValue(const double)));
    connect(ui->oldFrom45To49SpinBox, SIGNAL(valueChanged(const double)), oldData->getFrom45To49().data(), SLOT(setValue(const double)));
    connect(ui->oldGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), oldData->getGreaterThen50().data(), SLOT(setValue(const double)));

    connect(oldData->getLessThen40().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
    connect(oldData->getFrom40To44().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
    connect(oldData->getFrom45To49().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
    connect(oldData->getGreaterThen50().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);

    auto tariffs = inputSession.data()->getTariffs().data();
    connect(ui->heatedWaterTariffSpinBox, SIGNAL(valueChanged(const double)), tariffs->getHeated().data(), SLOT(setValue(const double)));
    connect(ui->coldWaterTariffSpinBox, SIGNAL(valueChanged(const double)), tariffs->getCold().data(), SLOT(setValue(const double)));

    connect(tariffs->getCold().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
    connect(tariffs->getHeated().data(), &DoubleNumber::valueChanged, this, &MainWindow::calculateAll);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateAll()
{
    auto tariffs = inputSession.data()->getTariffs().data();
    const double coldWaterTariff = tariffs->getCold().data()->getValue();
    const double heatedWaterTariff = tariffs->getHeated().data()->getValue();

    auto sessionChange = inputSession.data()->getChange().data();

    auto newData = sessionChange->getNewData().data();
    const double currentLessThen40 = newData->getLessThen40().data()->getValue();
    const double currentFrom40To44 = newData->getFrom40To44().data()->getValue();
    const double currentFrom45To49 = newData->getFrom45To49().data()->getValue();
    const double currentGreaterThen50 = newData->getGreaterThen50().data()->getValue();

    auto oldData = sessionChange->getOldData().data();
    const double oldLessThen40 = oldData->getLessThen40().data()->getValue();
    const double oldFrom40To44 = oldData->getFrom40To44().data()->getValue();
    const double oldFrom45To49 = oldData->getFrom45To49().data()->getValue();
    const double oldGreaterThen50 = oldData->getGreaterThen50().data()->getValue();

    qDebug() << "Recalculation requested";
    const double toPay = (currentLessThen40 - oldLessThen40) * coldWaterTariff +
            (currentFrom40To44 - oldFrom40To44) * heatedWaterTariff * 0.7 +
            (currentFrom45To49 - oldFrom45To49) * heatedWaterTariff * 0.9 +
            (currentGreaterThen50 - oldGreaterThen50) * heatedWaterTariff;
    ui->toPaySpinBox->setValue(toPay);
    ui->giocSpinBox->setValue(toPay / heatedWaterTariff);
}
