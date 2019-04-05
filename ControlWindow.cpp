#include "ControlWindow.h"
#include "ui_ControlWindow.h"
#include <QTimer>
#include "pendulumsystem.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "DisplayWindow.h"

ControlWindow::ControlWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);
}

ControlWindow::~ControlWindow()
{
    delete ui;
}

void ControlWindow::on_pushButton_clicked()
{
    if (fStatus == kIdle) {
        ui->pushButton->setStyleSheet("background-color:green");
        ui->pushButton->setText("Stop");

        bool button;
        int number = ui ->spinBox->value();
        double mangle = ui ->doubleSpinBox_2->value();
        double gravity = ui-> doubleSpinBox->value();
        double mlength = ui->doubleSpinBox_3 ->value();
        double damping = ui->lineEdit->text().toDouble();

        //Declare all the variable which the user can set

        if (ui->checkBox->isChecked()){
            button = true;
        }else {
            button = false;
        }
        //check for damping


        PendulumSystem* system = new PendulumSystem(number,button,mangle,gravity,mlength,damping);
        fWin = new DisplayWindow((PendulumSystem*)system);
        fStatus = kRun;

        /*Generate a pendulum system with all the variables passed in by the user and pass it as the argument
          to a new display window */

    }else {
        ui->pushButton->setStyleSheet("background-color:red");
        ui->pushButton->setText("Run");




        fStatus = kIdle;
    }

}

void ControlWindow::on_spinBox_valueChanged(int arg1)
{

}

void ControlWindow::on_checkBox_clicked()
{

}

void ControlWindow::on_doubleSpinBox_2_editingFinished()
{

}

void ControlWindow::on_doubleSpinBox_editingFinished()
{

}

void ControlWindow::on_doubleSpinBox_3_editingFinished()
{

}
