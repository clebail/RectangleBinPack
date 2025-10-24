#include <QVBoxLayout>
#include <QtDebug>
#include "mainwindow.h"
#include "MaxRectsBinPack.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    svgWidget = new QSvgWidget(this);

    QVBoxLayout * verticalLayout = new QVBoxLayout(gbResultat); // make a layout to put the svgwidget it so it scales with the window
    verticalLayout->setContentsMargins(0, 0, 0, 0); // no borders
    verticalLayout->addWidget(svgWidget);// the widget to it
    gbResultat->setLayout(verticalLayout);
}

MainWindow::~MainWindow()
{
    delete svgWidget;
}

 QString MainWindow::process(void)
 {
     using namespace rbp;
     int width = txtLargeur->toPlainText().toInt();
     int height = txtHauteur->toPlainText().toInt();
     QString svg = "<svg width=\""+QString::number(width)+"\" height=\""+QString::number(height)+"\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:svg=\"http://www.w3.org/2000/svg\">";

       svg += "<rect style=\"fill:#FFF;stroke:#FFF;stroke-width:0.1;stroke-opacity:1\" x=\"0\" y=\"0\" width=\""+QString::number(width)+"\" height=\""+QString::number(height)+"\" />";

     // Create a bin to pack to, use the bin size from command line.
     MaxRectsBinPack bin;

     bin.Init(width, height);

     svg += "</svg>";

     return svg;
 }

 void MainWindow::on_txtLargeur_textChanged()
 {
     QString svg = process();
     svgWidget->load(svg.toLocal8Bit());
     qDebug() << "test" << svg;
 }

 void MainWindow::on_txtHauteur_textChanged()
 {
     svgWidget->load(process().toLocal8Bit());
 }

 void MainWindow::on_pbAddTrou_clicked(bool)
 {
    ItemWidget *iw = new ItemWidget(this);

    trous.append(iw);

    widgetTrous->layout()->addWidget(iw);
 }

 void MainWindow::on_pbAddPave_clicked(bool)
 {
    ItemWidget *iw = new ItemWidget(this);

    paves.append(iw);

    widgetPaves->layout()->addWidget(iw);
 }
