#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QSharedPointer>
#include <QDoubleSpinBox>

#include "doublenumber.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentSession(new Session())
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}
