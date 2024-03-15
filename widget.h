#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget // we make Widget class,it inherits Qwidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr); // Constructor
    ~Widget(); // Distructor
    int money{0}; // it is member variable of Widget class. It will be created when Widget object is created.
    // If not money variable will share will windows
    void changeMoney(int diff);
    void alterEnable();

private slots: // if someone clicks button, below func will activate
    void on_pbCoin10_clicked();

    void on_pbCoin50_clicked();

    void on_pbCoin100_clicked();

    void on_pbCoin500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbTang_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
