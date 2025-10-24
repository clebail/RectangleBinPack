#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include "ui_itemwidget.h"

class ItemWidget : public QWidget, private Ui::ItemWidget
{
    Q_OBJECT
public:
    ItemWidget(QWidget *parent);
};

#endif // ITEMWIDGET_H
