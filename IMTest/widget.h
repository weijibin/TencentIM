#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

 public slots:
    void sltCallBack(QString str);
private slots:
    void on_loginBtn_clicked();

    void on_joinBtn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
