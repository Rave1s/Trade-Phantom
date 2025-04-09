// mainwindow.cpp
#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QtCharts/QXYSeries>  // For count() method
#include <QtCharts/QChartView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Set up chart
    series = new QLineSeries();
    for (double price : market.getPriceHistory())
        series->append(series->count(), price);

    chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Stock Price History");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Buttons
    QPushButton *buyButton = new QPushButton("Buy 1 Share");
    QPushButton *sellButton = new QPushButton("Sell 1 Share");
    QPushButton *nextDayButton = new QPushButton("Next Day");

    connect(buyButton, &QPushButton::clicked, this, &MainWindow::onBuyClicked);
    connect(sellButton, &QPushButton::clicked, this, &MainWindow::onSellClicked);
    connect(nextDayButton, &QPushButton::clicked, this, &MainWindow::onNextDayClicked);

    // Layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(chartView);
    layout->addWidget(buyButton);
    layout->addWidget(sellButton);
    layout->addWidget(nextDayButton);
    setCentralWidget(centralWidget);
}

void MainWindow::onBuyClicked() {
    portfolio.buy("XYZ", market.getPrice(), 1);
    updateChart();
}

void MainWindow::onSellClicked() {
    portfolio.sell("XYZ", market.getPrice(), 1);
    updateChart();
}

void MainWindow::onNextDayClicked() {
    market.updatePrice();
    updateChart();
}

void MainWindow::updateChart() {
    series->clear();
    int day = 0;
    for (double price : market.getPriceHistory())
        series->append(day++, price);

    // Get axes once and reuse
    QList<QAbstractAxis*> axes = chart->axes();
    if (!axes.isEmpty()) {
        axes[0]->setRange(0, day);  // X axis
        axes[1]->setRange(*std::min_element(market.getPriceHistory().begin(),
                                            market.getPriceHistory().end()) * 0.9,
                          *std::max_element(market.getPriceHistory().begin(),
                                            market.getPriceHistory().end()) * 1.1);
    }
}
