#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSvg>
#include "ui_mainwindow.h"
#include "pavewidget.h"
#include "trouwidget.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSvgWidget *svgWidget;
    QList<TrouWidget *>trous;
    QList<PaveWidget *>paves;

    QString process(void);
private slots:
    void on_leWidth_textChanged();
    void on_leHeight_textChanged();
    void on_pbAddTrou_clicked(bool checked = false);
    void on_pbAddPave_clicked(bool checked = false);
    void trouDeleted(TrouWidget *item);
    void paveDeleted(PaveWidget *item);
};

#endif // MAINWINDOW_H
