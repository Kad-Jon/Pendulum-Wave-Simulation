#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QItemSelection>
#include <QMainWindow>
#include <vector>
#include "pendulumsystem.h"
#include "DisplayWindow.h"

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = 0);
    ~ControlWindow();

private slots:

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_checkBox_clicked();

    void on_doubleSpinBox_2_editingFinished();

    void on_doubleSpinBox_editingFinished();

    void on_doubleSpinBox_3_editingFinished();

private:
    Ui::ControlWindow *ui;
    DisplayWindow* fWin;


    enum{
        kIdle,
        kRun
    };
    int fStatus = kIdle;
};

#endif // CONTROLWINDOW_H
