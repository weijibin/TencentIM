#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QDebug>

#include "hhim.h"

//   uid:508766
//   uid:1173


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

//    QString str = "12222333";

//    std::string str1 = QStringToCString(str);

//    char * ch = QStringToChar(str);
//    char *ch = nullptr;
//    QByteArray ba = str.toLatin1();
//    ch = ba.data();

//    QString st2(ch);
//    qDebug()<<QString(ch);
//    qDebug()<<"end";
    QString sig = "eJx1kE9PgzAYh*98iobrjLblj52JB9xYNrM5ZLDMU0NoIc0ia0uHwOJ3VzGLXHyvz5M8v7wXCwBgJ*vdbZbnp3NlqOkkt8EDsH2M7Js-LKVgNDPU0WzAyIXfhzF2RhZvpdCcZoXherCwN8UQjgzBeGVEIa783oG05-pEEa3rkVezIx2a-8dqUQ5wE6azVaB7dW69u66aOk8zXHb7MC3j9IXsEpRETTR5XTBtqm4R80CEATlE4XrjwVzpJn*bKJ-sY9I-t8c5my8PjUp9qZLgY2uK1eMoacT773OQ57qQuD*DrE-rC3DHWco_";
//    HHIM::getInstance()->login(1400002223,"2730_zero_1_ss",621,sig);

    ui->sig->setText(sig);
    ui->accountType->setText(QString::number(621));
    ui->appid->setText(QString::number(1400002223));
    ui->identifier->setText("2730_zero_1_ss");

    connect(HHIM::getInstance(),SIGNAL(sigRecMsg(QString)),this,SLOT(sltCallBack(QString)));
    connect(HHIM::getInstance(),SIGNAL(sigErrorCode(QString)),this,SLOT(sltCallBack(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sltCallBack(QString str)
{
    ui->textEdit->append(str);
}

void Widget::on_loginBtn_clicked()
{
    int appid = ui->appid->text().toInt();
    QString identifer = ui->identifier->text();
    int type = ui->accountType->text().toInt();
    QString sig = ui->sig->text();
    HHIM::getInstance()->login(appid,identifer,type,sig);
}

void Widget::on_joinBtn_clicked()
{
     HHIM::getInstance()->joinGroup("12333");
}
