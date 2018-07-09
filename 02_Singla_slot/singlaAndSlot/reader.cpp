#include "reader.h"
#include <iostream>
#include <QDebug>
Reader::Reader(QObject *parent) : QObject(parent)
{

}


void Reader::receiveNewspaper(const QString &name)
{
    qDebug()<<"content:"<<name;
}
