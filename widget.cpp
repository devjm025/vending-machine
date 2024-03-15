#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
// " " <>: start to find header form system d

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); // This fuction generatets UI related variables. (ex. lcdNumber)s
    alterEnable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui ->lcdNumber->display(money);

    alterEnable();
}

void Widget::alterEnable(){
    // the value of if condition returns, and setEnable func required are same format(boolean)
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbTang->setEnabled(money >= 300);
    ui->pbReset->setEnabled(money>0);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100); // deactivate initail (when money >100 it activated)
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    // using messageBox : QMessageBox Class
    QMessageBox mb;
    QString message;

    int coin500 = money/500;
    int coin100 = money%500/100;
    int coin50 = money%500%100/50;
    int coin10 = money%500%100%50/10;

    message = "500: " + QString::number(coin500)+ "\n100: " + QString::number(coin100)+ "\n50: " + QString::number(coin50)+ "\n10: " + QString::number(coin10);

    changeMoney(-money);

    mb.information(nullptr, "Charge", message);
    // in C Null Pointer is nullptr
}

