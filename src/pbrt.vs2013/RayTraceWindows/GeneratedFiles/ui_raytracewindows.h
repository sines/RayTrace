/********************************************************************************
** Form generated from reading UI file 'raytracewindows.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAYTRACEWINDOWS_H
#define UI_RAYTRACEWINDOWS_H

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

class Ui_RayTraceWindowsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RayTraceWindowsClass)
    {
        if (RayTraceWindowsClass->objectName().isEmpty())
            RayTraceWindowsClass->setObjectName(QStringLiteral("RayTraceWindowsClass"));
        RayTraceWindowsClass->resize(600, 400);
        menuBar = new QMenuBar(RayTraceWindowsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RayTraceWindowsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RayTraceWindowsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RayTraceWindowsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RayTraceWindowsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RayTraceWindowsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RayTraceWindowsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RayTraceWindowsClass->setStatusBar(statusBar);

        retranslateUi(RayTraceWindowsClass);

        QMetaObject::connectSlotsByName(RayTraceWindowsClass);
    } // setupUi

    void retranslateUi(QMainWindow *RayTraceWindowsClass)
    {
        RayTraceWindowsClass->setWindowTitle(QApplication::translate("RayTraceWindowsClass", "RayTraceWindows", 0));
    } // retranslateUi

};

namespace Ui {
    class RayTraceWindowsClass: public Ui_RayTraceWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYTRACEWINDOWS_H
