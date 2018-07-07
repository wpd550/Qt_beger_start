#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDialog>
#include <QMenu>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);

    setWindowTitle(tr("TenorShare"));

    openACtion = new QAction(tr("open"),this);



    connect(openACtion,&QAction::triggered,this,&MainWindow::open);
    QMenu *file = menuBar()->addMenu(tr("Open"));
    file->addAction(openACtion);

    QToolBar *toolBar =addToolBar(tr("File"));
    toolBar->addAction(openACtion);

}


void MainWindow::open()
{


#if 0
    QDialog dialog(this);  //注意 此处有this，弹窗在父类窗口中弹出 ；没有this指针的时候，作为顶级窗口弹出；
    dialog.setWindowTitle("Dialog");
    //    dialog.setAttribute(Qt::WA_DeleteOnClose);   //设置当close dialog 是自动销毁窗口，注意dialog的是在堆上分配的空间
    dialog.exec();
    //    dialog.open(); //窗口级别的某台
    //    dialog.show(); //非模态
    qDebug()<<">>>>>>>>>>dialog.result ===="<<dialog.result()<<endl;


    if(QMessageBox::Yes == QMessageBox::question(this,tr("Question"),tr("Are you Sure?"),QMessageBox::Yes ,QMessageBox::Yes))
        QMessageBox::information(this,tr("HUmmm........"),tr("I'm glat hear that!"));
    else
    {
        QMessageBox::information(this,tr("HUmmm........."),tr("oh,I'm srroy!"));
    }
#endif

    setMessageBox();





}

void MainWindow::setMessageBox()
{
       QMessageBox msgbox;
       msgbox.setText("The document has been modified");
       msgbox.setInformativeText(tr("Do you want to save your changers?"));
       msgbox.setDetailedText(tr("Defference here..."));
       msgbox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
       msgbox.setDefaultButton(QMessageBox::Save);
       int ret = msgbox.exec();
       switch (ret) {
       case QMessageBox::Save:
           qDebug("Save document!");
           break;
       case QMessageBox::Discard:
           qDebug("DisCard document!");
           break;
       case QMessageBox::Cancel:
           qDebug("Cancel document!");
           break;
       default:
           break;
       }
}


MainWindow::~MainWindow()
{
    delete openACtion;
    delete ui;
}
