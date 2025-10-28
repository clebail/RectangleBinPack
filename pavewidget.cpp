#include "pavewidget.h"

PaveWidget::PaveWidget(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

void PaveWidget::on_pbDelete_clicked(bool)
{
    emit(deleted(this));
}
