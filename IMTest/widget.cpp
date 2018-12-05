#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QDebug>

char * QStringToChar(const QString & str)
{
    char *ch = nullptr;
    QByteArray ba = str.toLatin1();
    ch = ba.data();
    return ch;
}

std::string QStringToCString(QString str)
{
    std::string ss = str.toStdString();
    return ss;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString str = "12222333";

//    std::string str1 = QStringToCString(str);

//    char * ch = QStringToChar(str);
    char *ch = nullptr;
    QByteArray ba = str.toLatin1();
    ch = ba.data();

    QString st2(ch);
    qDebug()<<QString(ch);
    qDebug()<<"end";
}

Widget::~Widget()
{
    delete ui;
}


