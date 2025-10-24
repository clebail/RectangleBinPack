#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSvg>
#include "ui_mainwindow.h"
#include "itemwidget.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSvgWidget *svgWidget;
    QList<ItemWidget *>trous;
    QList<ItemWidget *>paves;

    QString process(void);
private slots:
    void on_txtLargeur_textChanged();
    void on_txtHauteur_textChanged();
    void on_pbAddTrou_clicked(bool checked = false);
    void on_pbAddPave_clicked(bool checked = false);
};

#endif // MAINWINDOW_H
