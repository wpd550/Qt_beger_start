#ifndef EVENTLABEL_H
#define EVENTLABEL_H

#include <QLabel>
class QMouseEvent;

class EventLabel : public QLabel
{
     Q_OBJECT
public:
    EventLabel(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // EVENTLABEL_H
