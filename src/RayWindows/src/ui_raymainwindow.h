/********************************************************************************
** Form generated from reading UI file 'raymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAYMAINWINDOW_H
#define UI_RAYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RayMainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RayMainWindow)
    {
        if (RayMainWindow->objectName().isEmpty())
            RayMainWindow->setObjectName(QStringLiteral("RayMainWindow"));
        RayMainWindow->resize(623, 434);
        centralWidget = new QWidget(RayMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 601, 481));
        RayMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RayMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RayMainWindow->setStatusBar(statusBar);

        retranslateUi(RayMainWindow);

        QMetaObject::connectSlotsByName(RayMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RayMainWindow)
    {
        RayMainWindow->setWindowTitle(QApplication::translate("RayMainWindow", "RayMainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class RayMainWindow: public Ui_RayMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYMAINWINDOW_H
