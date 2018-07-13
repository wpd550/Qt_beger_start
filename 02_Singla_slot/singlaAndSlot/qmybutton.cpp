#include "qmybutton.h"


#include <QDebug>

qMybutton::qMybutton(QWidget *parent):QPushButton(parent)
{

}

void qMybutton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        qDebug()<<"leftbutton click";
    }
}
