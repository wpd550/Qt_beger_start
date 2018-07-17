#include "mainwindow.h"
#include <QApplication>
#include "finddialog.h"
#include "gotocelldialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    FindDialog m_Dialog;
//    m_Dialog.show();
    GoToCellDialog dialog ;
    dialog.show();

    return a.exec();
}
