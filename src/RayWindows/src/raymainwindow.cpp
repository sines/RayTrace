#include "raymainwindow.h"
#include "ui_raymainwindow.h"

RayMainWindow::RayMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RayMainWindow)
{
    ui->setupUi(this);
}

RayMainWindow::~RayMainWindow()
{
    delete ui;
}
