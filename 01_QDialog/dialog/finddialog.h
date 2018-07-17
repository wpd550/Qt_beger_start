#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QObject>
#include <QDialog>
class QPushButton;
class QLabel;
class QLineEdit;
class QCheckBox;

class FindDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FindDialog(QWidget *parent = nullptr);

signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);
public slots:
    void findClick();
    void enableFindButton(const QString &text);

private:
    QPushButton *m_find_btn;
    QPushButton *m_close_btn;
    QLabel      *m_find_label;
    QLineEdit   *m_fileName_lineEdit;
    QCheckBox   *m_caseCheckbox;
    QCheckBox   *m_backwardbox;

};

#endif // FINDDIALOG_H
