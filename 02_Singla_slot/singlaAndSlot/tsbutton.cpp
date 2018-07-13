#include "tsbutton.h"
#include <QDebug>
TSButton::TSButton(QWidget *parent):QPushButton(parent)
{

}

void TSButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug()<<"left Clicked";
    }
}
