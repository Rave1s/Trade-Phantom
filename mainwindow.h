// mainwindow.h
#pragma once
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include "portfolio.h"

#include "StockMarket.h"  // Your backend class

QT_USE_NAMESPACE

    class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    void updateChart();

private slots:
    void onBuyClicked();
    void onSellClicked();
    void onNextDayClicked();

private:
    StockMarket market{"XYZ", 100.0};
    Portfolio portfolio{1000.0};
    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;
};
