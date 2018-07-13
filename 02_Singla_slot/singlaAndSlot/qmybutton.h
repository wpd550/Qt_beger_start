#ifndef QMYBUTTON_H
#define QMYBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class qMybutton :public QPushButton
{

public:
    qMybutton(QWidget *parent = 0);

 protected:

    void mousePressEvent(QMouseEvent *e);
};

#endif // QMYBUTTON_H
