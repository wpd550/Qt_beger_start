#include "finddialog.h"
#include <QLabel>
#include<QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{
    m_find_label = new QLabel(tr("Find &what:"));
    m_fileName_lineEdit = new QLineEdit;
    //设置关联标签，点击标签 响应budy
    m_find_label->setBuddy(m_fileName_lineEdit);
    m_caseCheckbox =new QCheckBox(tr("Match &case"));
    m_backwardbox  = new QCheckBox(tr("Search &backward"));

    m_find_btn =new QPushButton(tr("&Find"));
    m_find_btn->setDefault(true); //设置第一响应者
    m_find_btn->setEnabled(false);

    m_close_btn = new QPushButton(tr("Close"));

    //
    //QT5 语法
    connect(m_fileName_lineEdit,&QLineEdit::textChanged,this,&FindDialog::enableFindButton);
    connect(m_find_btn,&QPushButton::clicked,this,&FindDialog::findClick);
    //添加布局
    //水平布局
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(m_find_label);
    topLeftLayout->addWidget(m_fileName_lineEdit);

    //垂直布局
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(m_caseCheckbox);
    leftLayout->addWidget(m_backwardbox);

    QVBoxLayout *rightLayout =new QVBoxLayout;
    rightLayout->addWidget(m_find_btn);
    rightLayout->addWidget(m_close_btn);
    //在尾部添加一个空拉缩空间，最小为0
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    //使用图层
    setLayout(mainLayout);

}

void FindDialog::findClick()
{
    QString text = m_fileName_lineEdit->text();
    //大小写是否忽略
    Qt::CaseSensitivity cs = m_caseCheckbox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive;
    if(m_backwardbox->isChecked())
    {
        qDebug()<<"搜索下一个"<<"\n";
        emit findNext(text,cs);
    }
    else
    {
        qDebug()<<"搜索上一个"<<"\n";
        emit findPrevious(text,cs);
    }


}

void FindDialog::enableFindButton(const QString &text)
{
    m_find_btn->setEnabled(!text.isEmpty());
}
