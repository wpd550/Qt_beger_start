#ifndef READER_H
#define READER_H

#include <QObject>

class Reader : public QObject
{
    Q_OBJECT
public:
    explicit Reader(QObject *parent = nullptr);

signals:

public slots:
    void receiveNewspaper(const QString &name);
private:
    QString m_content;

};

#endif // READER_H
