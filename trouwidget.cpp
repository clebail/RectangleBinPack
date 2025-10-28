#include "trouwidget.h"

TrouWidget::TrouWidget(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

void TrouWidget::on_pbDelete_clicked(bool)
{
    emit(deleted(this));
}
