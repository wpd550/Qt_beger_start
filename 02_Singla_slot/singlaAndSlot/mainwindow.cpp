#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpaple.h"
#include "reader.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);

     NewPaple newspale("it's happy day!!");
     Reader reader;
     newspale.send();
     connect(&newspale,&NewPaple::newsPaper,&reader,&Reader::receiveNewspaper);
     newspale.send();

}




MainWindow::~MainWindow()
{
    delete ui;
}
