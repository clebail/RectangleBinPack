#ifndef PAVEWIDGET_H
#define PAVEWIDGET_H

#include <QWidget>
#include "ui_pavewidget.h"

class PaveWidget : public QWidget, private Ui::PaveWidget
{
    Q_OBJECT
public:
    PaveWidget(QWidget *parent);
signals:
    void deleted(PaveWidget *item);
private slots:
    void on_pbDelete_clicked(bool checked = false);
};

#endif // PAVEWIDGET_H
