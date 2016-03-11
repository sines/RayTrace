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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RayMainWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RayMainWindow)
    {
        if (RayMainWindow->objectName().isEmpty())
            RayMainWindow->setObjectName(QStringLiteral("RayMainWindow"));
        RayMainWindow->resize(400, 300);
        menuBar = new QMenuBar(RayMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RayMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RayMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RayMainWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(RayMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
