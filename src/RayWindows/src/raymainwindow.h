#ifndef RAYMAINWINDOW_H
#define RAYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class RayMainWindow;
}

class RayMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RayMainWindow(QWidget *parent = 0);
    ~RayMainWindow();

private:
    Ui::RayMainWindow *ui;
};

#endif // RAYMAINWINDOW_H
