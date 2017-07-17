#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->currentWaterSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->currentHeatedSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->currentLessThen40SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->currentFrom40To44SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->currentFrom45To49SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->currentGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));

    connect(ui->oldWaterSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->oldHeatedSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->oldLessThen40SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->oldFrom40To44SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->oldFrom45To49SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->oldGreaterThen50SpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));

    connect(ui->heatedWaterTariffSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
    connect(ui->coldWaterTariffSpinBox, SIGNAL(valueChanged(const double)), this, SLOT(calculateAll()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateAll()
{
    double coldWaterTariff = ui->coldWaterTariffSpinBox->value();
    double heatedWaterTariff = ui->heatedWaterTariffSpinBox->value();

    double currentLessThen40 = ui->currentLessThen40SpinBox->value();
    double currentFrom40To44 = ui->currentFrom40To44SpinBox->value();
    double currentFrom45To49 = ui->currentFrom45To49SpinBox->value();
    double currentGreaterThen50 = ui->currentGreaterThen50SpinBox->value();

    double oldLessThen40 = ui->oldLessThen40SpinBox->value();
    double oldFrom40To44 = ui->oldFrom40To44SpinBox->value();
    double oldFrom45To49 = ui->oldFrom45To49SpinBox->value();
    double oldGreaterThen50 = ui->oldGreaterThen50SpinBox->value();

    qDebug() << "Recalculation requested";
    double toPay = (currentLessThen40 - oldLessThen40) * coldWaterTariff +
            (currentFrom40To44 - oldFrom40To44) * heatedWaterTariff * 0.7 +
            (currentFrom45To49 - oldFrom45To49) * heatedWaterTariff * 0.9 +
            (currentGreaterThen50 - oldGreaterThen50) * heatedWaterTariff;
    ui->toPaySpinBox->setValue(toPay);
    ui->giocSpinBox->setValue(toPay / heatedWaterTariff);
}
