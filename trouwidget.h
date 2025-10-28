#ifndef TROUWIDGET_H
#define TROUWIDGET_H

#include <QWidget>
#include "ui_trouwidget.h"

class TrouWidget : public QWidget, private Ui::TrouWidget
{
    Q_OBJECT
public:
    TrouWidget(QWidget *parent);
signals:
    void deleted(TrouWidget *item);
private slots:
    void on_pbDelete_clicked(bool checked = false);
};

#endif // TROUWIDGET_H
