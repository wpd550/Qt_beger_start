#include "newpaple.h"

NewPaple::NewPaple(QObject *parent) : QObject(parent)
{

}


NewPaple::NewPaple(const QString &name):m_content(name)
{

}
void NewPaple::send()
{
    emit newsPaper(m_content);
}
