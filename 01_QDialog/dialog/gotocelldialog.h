#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QWidget>

namespace Ui {
class GoToCellDialog;
}

class GoToCellDialog : public QWidget
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = 0);
    ~GoToCellDialog();

private:
    Ui::GoToCellDialog *ui;
};

#endif // GOTOCELLDIALOG_H
