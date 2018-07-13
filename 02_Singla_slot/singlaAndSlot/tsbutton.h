#ifndef TSBUTTON_H
#define TSBUTTON_H

#include<QPushButton>
#include<QMouseEvent>

class TSButton : public QPushButton
{

public:
    TSButton(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // TSBUTTON_H
