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
     int width = leWidth->text().toInt();
     int height = leHeight->text().toInt();
     QString svg = "<svg width=\""+QString::number(width)+"\" height=\""+QString::number(height)+"\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:svg=\"http://www.w3.org/2000/svg\">";

       svg += "<rect style=\"fill:#FFF;stroke:#FFF;stroke-width:0.1;stroke-opacity:1\" x=\"0\" y=\"0\" width=\""+QString::number(width)+"\" height=\""+QString::number(height)+"\" />";

     // Create a bin to pack to, use the bin size from command line.
     MaxRectsBinPack bin;

     bin.Init(width, height);

     svg += "</svg>";

     return svg;
 }

 void MainWindow::on_leWidth_textChanged()
 {
     QString svg = process();
     svgWidget->load(svg.toLocal8Bit());
 }

 void MainWindow::on_leHeight_textChanged()
 {
     svgWidget->load(process().toLocal8Bit());
 }

 void MainWindow::on_pbAddTrou_clicked(bool)
 {
    TrouWidget *tw = new TrouWidget(this);
    connect(tw, SIGNAL(deleted(TrouWidget *)), this, SLOT(trouDeleted(TrouWidget *)));

    dynamic_cast<QVBoxLayout *>(scrollTrous->widget()->layout())->insertWidget(trous.count(), tw);
    trous.append(tw);

    process();
 }

 void MainWindow::on_pbAddPave_clicked(bool)
 {
    PaveWidget *pw = new PaveWidget(this);
    connect(pw, SIGNAL(deleted(PaveWidget *)), this, SLOT(paveDeleted(PaveWidget *)));

    dynamic_cast<QVBoxLayout *>(scrollPaves->widget()->layout())->insertWidget(paves.count(), pw);
    paves.append(pw);

    process();
 }

 void MainWindow::trouDeleted(TrouWidget *item)
 {
    dynamic_cast<QVBoxLayout *>(scrollTrous->widget()->layout())->removeWidget(item);
    trous.removeOne(item);

    delete item;
 }

 void MainWindow::paveDeleted(PaveWidget *item)
 {
    dynamic_cast<QVBoxLayout *>(scrollPaves->widget()->layout())->removeWidget(item);
    paves.removeOne(item);

    delete item;
 }
