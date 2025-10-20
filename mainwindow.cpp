#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MaxRectsBinPack.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    svgWidget = new QSvgWidget(this);
    svgWidget->load(QString("<svg width=\"150\" height=\"250\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:svg=\"http://www.w3.org/2000/svg\"><rect x='10' y='10' width='100' height='100' /></svg>").toLocal8Bit());
    // svgWidget->load(QString("/home/corentin/dev/RectangleBinPack/test.svg"));

    QVBoxLayout * verticalLayout = new QVBoxLayout(centralWidget()); // make a layout to put the svgwidget it so it scales with the window
    verticalLayout->setContentsMargins(0, 0, 0, 0); // no borders
    verticalLayout->addWidget(svgWidget);// the widget to it
    centralWidget()->setLayout(verticalLayout);
}

MainWindow::~MainWindow()
{
    delete svgWidget;
}

