#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegExp>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //构建正则表达式对象
    QRegExp reg("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+[\.][a-zA-Z0-9_-]+$");
    //执行正则匹配，匹配到返回true 否则返回false
    bool mattch = reg.exactMatch(ui->m_email->text());
    if(mattch)
    {
        QMessageBox::information(this,"titie","Successfully");

    }
    else
    {
       QMessageBox::warning(this,"titie","failed create email");

    }
}
