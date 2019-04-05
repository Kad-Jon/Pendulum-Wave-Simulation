#include "DisplayWindow.h"
#include "ui_DisplayWindow.h"
#include "pendulumsystem.h"

#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QTimer>
#include <vector>

DisplayWindow::DisplayWindow(PendulumSystem*system,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWindow),fSystem(system)
{
    ui->setupUi(this);
    setStyleSheet("background-color:black");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(paintEvent(QPaintEvent*)));
    timer->start(10); //Paints event every 10 millisecons

    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(Run()));
    timer2->start(10); //Calls run which calls simulate every 10 milliseconds

    show(); //Opens

    setAttribute(Qt::WA_OpaquePaintEvent);
}

DisplayWindow::~DisplayWindow()
{

    delete ui;
}

void DisplayWindow::paintEvent(QPaintEvent*){

    //paint Event defintion

    QPainter painter (this);

    painter.fillRect(QRect(0,0, width() -1, height() - 1), QBrush(Qt::black));

    double scale = fSystem -> GetScale(); //scale aquired and determined by length of the longest pendulum

    for(int i = 0;i < fSystem->GetNumber();i++){

    double X = (fSystem->GetPendulum(i).CartconvertX());
    double Y = (fSystem->GetPendulum(i).CartconvertY());
    //retreives cartesian co ordinates from each pendulum angle and length for painter to use

    painter.setPen(palette().light().color());
    QColor green("#00ff50");
    Qt::BrushStyle style = Qt::SolidPattern;
    QBrush brush(green, style);
    painter.setBrush(brush);
    painter.drawEllipse((X/scale) + width()/2,Y/scale + height()/4, 4, 4);
    this->update();
    }
}

void DisplayWindow::Run(){
    fSystem->Simulate();
} //Calss pendulum system simulate which calls simulate for the pendula




