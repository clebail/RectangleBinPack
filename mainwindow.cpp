#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    svgWidget = new QSvgWidget(this);
    svgWidget->load(QString("<?xml version='1.0'?><svg xmlns='http://www.w3.org/2000/svg'  version='1.2' baseProfile='tiny' width='120' height='120'><rect x='10' y='10' wudth='100' height='100' /></svg").toLocal8Bit());
    svgWidget->show();

    QVBoxLayout * verticalLayout = new QVBoxLayout(centralWidget()); // make a layout to put the svgwidget it so it scales with the window
    verticalLayout->setContentsMargins(0, 0, 0, 0); // no borders
    verticalLayout->addWidget(svgWidget);// the widget to it
    centralWidget()->setLayout(verticalLayout);
}

MainWindow::~MainWindow()
{
    delete svgWidget;
}

