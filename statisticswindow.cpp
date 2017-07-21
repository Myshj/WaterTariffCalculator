#include "statisticswindow.h"
#include "ui_statisticswindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries();
    series->append("Jane", 1);
    series->append("Joe", 2);
    series->append("Andy", 3);
    series->append("Barbara", 4);
    series->append("Axel", 5);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple piechart example");
    //chart->legend()->hide();

    QChartView *chartView = new QChartView(chart, this);
    ui->gridLayout->addWidget(chartView);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->show();
    QPieSlice* s = series->slices().at(0);
    s->setValue(5);
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}
