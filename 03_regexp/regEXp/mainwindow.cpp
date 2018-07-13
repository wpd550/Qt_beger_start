#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegExp>
#include <QMessageBox>
#include <qdebug.h>

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

    QString str = "offsets: 1.23 .50 71.00 6.00";
    QRegExp rx("\\d*\\.\\d+");    // primitive floating point matching
    int count = 0;
    int pos = 0;
    int pos_2 = 0;
    //indexIn 返回匹配到的坐标位置 ，pos 表示从pos 位置开始匹配   如果没有匹配上则返回 -1
    while ((pos = rx.indexIn(str, pos)) != -1) {
        ++count;
        //返回匹配字符串的长度
        pos_2 = rx.matchedLength();
        qDebug()<<"str"<< str.mid(pos,pos_2);
        qDebug()<<"capture == "<<rx.capturedTexts();  //capturedTexts() 返回值有列表
        qDebug()<<"cap == "<<rx.cap();  //cap 返回值 通过参数返回第几个
        qDebug()<<"captureCoubt" <<rx.captureCount();
        pos += rx.matchedLength();
    }


    QRegExp rg("(\\d+)(\\s*)(cm|inch(es)?)");
    int pos_3 = rg.indexIn("Length: 36 inches");
    QStringList list = rg.capturedTexts();
    qDebug()<<list;


    if(mattch)
    {
        QMessageBox::information(this,"titie","Successfully");

    }
    else
    {
       QMessageBox::warning(this,"titie","failed create email");

    }
}

void MainWindow::test()
{
}
