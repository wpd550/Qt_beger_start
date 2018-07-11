#ifndef NEWPAPLE_H
#define NEWPAPLE_H

#include <QObject>

class QDate;
class QString;

class NewPaple : public QObject
{
    Q_OBJECT
public:
    explicit NewPaple(QObject *parent = nullptr);
    explicit NewPaple(const QString &name);

    ~NewPaple() = default;
    void send();
signals:
    void newsPaper(const QString &name);
    void newsPaper(const QString &name,const QDate &date);
public slots:
private:
    QString m_content;
};

#endif // NEWPAPLE_H
