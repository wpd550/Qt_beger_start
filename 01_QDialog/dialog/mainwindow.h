#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QAction;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void open();
    void setMessageBox();

private:
    Ui::MainWindow *ui;

    QAction *openACtion;
};

#endif // MAINWINDOW_H
