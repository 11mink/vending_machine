#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>

namespace Ui {
class VendingMachine;
}

class VendingMachine : public QMainWindow
{
    Q_OBJECT

public:
    explicit VendingMachine(QWidget *parent = nullptr);
    ~VendingMachine();
    int money;

private slots:
    void on_change_clicked();

    void on_won10_clicked();

    void on_won50_clicked();

    void on_won100_clicked();

    void on_won500_clicked();

    void on_coffee_clicked();

    void on_tea_clicked();

    void on_cola_clicked();

    void disable_buttons();

signals:
    void moneyChanged();

private:
    Ui::VendingMachine *ui;

};

#endif // VENDINGMACHINE_H
