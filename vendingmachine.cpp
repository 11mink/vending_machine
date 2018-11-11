#include "vendingmachine.h"
#include "ui_vendingmachine.h"

VendingMachine::VendingMachine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VendingMachine)
{
    ui->setupUi(this);
    ui->cola->setEnabled(false);
    ui->tea->setEnabled(false);
    ui->coffee->setEnabled(false);
    this->money = 0;
    connect(this, SIGNAL(moneyChanged()), this, SLOT(disable_buttons()));
}

VendingMachine::~VendingMachine()
{
    delete ui;
}


void VendingMachine::on_change_clicked()
{
    int num_10 = 0, num_50 = 0, num_100 = 0, num_500 = 0;
    num_500 = money/500;
    num_100 = (money - 500*num_500)/100;
    num_50 = (money - 500*num_500 - 100*num_100)/50;
    num_10 = (money - 500*num_500 - 100*num_100 - 50*num_50)/10;
    QString qstr = QString("500 : %1, 100 : %2, 50 : %3, 10 : %4").arg(num_500).arg(num_100).arg(num_50).arg(num_10);
    QMessageBox::information(this,"change",qstr,"OK");
    money = 0;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::on_won10_clicked()
{
    money += 10;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::on_won50_clicked()
{
    money += 50;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::on_won100_clicked()
{
    money += 100;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::on_won500_clicked()
{
    money += 500;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::on_coffee_clicked()
{
    money -= 100;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::on_tea_clicked()
{
    money -= 150;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::on_cola_clicked()
{
    money -= 200;
    ui->lcdNumber->display(money);
    emit moneyChanged();
}

void VendingMachine::disable_buttons()
{
    if(money<200) ui->cola->setEnabled(false);
    else ui->cola->setEnabled(true);

    if(money<150) ui->tea->setEnabled(false);
    else ui->tea->setEnabled(true);

    if (money < 100) ui->coffee->setEnabled(false);
    else ui->coffee->setEnabled(true);
}
