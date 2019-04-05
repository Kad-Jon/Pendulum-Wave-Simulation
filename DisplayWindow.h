#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <vector>

#include "pendulumsystem.h"

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    DisplayWindow();
    explicit DisplayWindow(PendulumSystem* system,QWidget *parent = 0); //Link to the simulation

    ~DisplayWindow();

private slots:
    void paintEvent (QPaintEvent*);
    void Run (); //Slots for QTimer

private:
    Ui::DisplayWindow *ui;
    PendulumSystem* fSystem;

};

#endif // DISPLAYWINDOW_H
