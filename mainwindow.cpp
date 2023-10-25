#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "Star.h"
#include <QPainter>
#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setStyleSheet("background-color: №000;");

    QVBoxLayout *vlay = new QVBoxLayout();

    Star *star = new Star();
    vlay->addWidget(star);

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
    timer->start(10);

    ui->centralwidget->setLayout(vlay);
}

MainWindow::~MainWindow()
{
    delete ui;
}
