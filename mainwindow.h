#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSvg>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSvgWidget *svgWidget;

    QString process(void);
private slots:
    void on_txtLargeur_textChanged();
    void on_txtHauteur_textChanged();
};

#endif // MAINWINDOW_H
