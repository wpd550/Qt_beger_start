#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpaple.h"
#include "reader.h"

//对于重载过的信号函数，需要使用定义一个函数指针指向正确的函数地址，编译器才能正确的识别出函数地址
void (NewPaple::*newPaperNameDate)(const QString &name, const QDate &data) = &NewPaple::newsPaper;
void (NewPaple::*newPaperName)(const QString &name) = &NewPaple::newsPaper;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);

     NewPaple newspale("it's happy day!!");
     Reader reader;
     newspale.send();

     /********************************
     //对于糙函数，可以使用lambda表达式
     connect(&newspale,newPaperName,[=](const Qstring &name){
         qDebug()<<"name";
     });
     *********************************/




     /********************************
     //使用static_cast 转化函数

     connect(&newspale,static_cast<void (NewPaple::*) (const QString &name)>(&NewPaple::newsPaper),
             &reader,&Reader::receiveNewspaper);


     *********************************/
     connect(&newspale,newPaperNameDate,&reader,&Reader::receiveNewspaper);



     newspale.send();

}




MainWindow::~MainWindow()
{
    delete ui;
}
