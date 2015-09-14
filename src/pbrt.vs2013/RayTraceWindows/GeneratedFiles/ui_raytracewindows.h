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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RayTraceWindowsClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStatusBar *statusBar;
    QMenuBar *menuBarFile;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuAbout;

    void setupUi(QMainWindow *RayTraceWindowsClass)
    {
        if (RayTraceWindowsClass->objectName().isEmpty())
            RayTraceWindowsClass->setObjectName(QStringLiteral("RayTraceWindowsClass"));
        RayTraceWindowsClass->setWindowModality(Qt::WindowModal);
        RayTraceWindowsClass->setEnabled(true);
        RayTraceWindowsClass->resize(556, 431);
        RayTraceWindowsClass->setContextMenuPolicy(Qt::DefaultContextMenu);
        RayTraceWindowsClass->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/RayTraceWindows/images/th.png"), QSize(), QIcon::Normal, QIcon::Off);
        RayTraceWindowsClass->setWindowIcon(icon);
        RayTraceWindowsClass->setDocumentMode(false);
        actionNew = new QAction(RayTraceWindowsClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(RayTraceWindowsClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionAbout = new QAction(RayTraceWindowsClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(RayTraceWindowsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        RayTraceWindowsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RayTraceWindowsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RayTraceWindowsClass->setStatusBar(statusBar);
        menuBarFile = new QMenuBar(RayTraceWindowsClass);
        menuBarFile->setObjectName(QStringLiteral("menuBarFile"));
        menuBarFile->setGeometry(QRect(0, 0, 556, 17));
        menuFile = new QMenu(menuBarFile);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBarFile);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBarFile);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menuBarFile);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        RayTraceWindowsClass->setMenuBar(menuBarFile);

        menuBarFile->addAction(menuFile->menuAction());
        menuBarFile->addAction(menuEdit->menuAction());
        menuBarFile->addAction(menuView->menuAction());
        menuBarFile->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuAbout->addAction(actionAbout);

        retranslateUi(RayTraceWindowsClass);

        QMetaObject::connectSlotsByName(RayTraceWindowsClass);
    } // setupUi

    void retranslateUi(QMainWindow *RayTraceWindowsClass)
    {
        RayTraceWindowsClass->setWindowTitle(QApplication::translate("RayTraceWindowsClass", "RayWindow", 0));
        actionNew->setText(QApplication::translate("RayTraceWindowsClass", "\346\226\260\345\273\272", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("RayTraceWindowsClass", "\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNew->setStatusTip(QApplication::translate("RayTraceWindowsClass", "\346\226\260\345\273\272", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionNew->setWhatsThis(QApplication::translate("RayTraceWindowsClass", "\346\226\207\344\273\266", 0));
#endif // QT_NO_WHATSTHIS
        actionNew->setShortcut(QApplication::translate("RayTraceWindowsClass", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("RayTraceWindowsClass", "\346\211\223\345\274\200", 0));
        actionAbout->setText(QApplication::translate("RayTraceWindowsClass", "\345\205\263\344\272\216", 0));
        menuFile->setTitle(QApplication::translate("RayTraceWindowsClass", "\346\226\207\344\273\266", 0));
        menuEdit->setTitle(QApplication::translate("RayTraceWindowsClass", "\347\274\226\350\276\221", 0));
        menuView->setTitle(QApplication::translate("RayTraceWindowsClass", "\350\247\206\345\233\276", 0));
        menuAbout->setTitle(QApplication::translate("RayTraceWindowsClass", "\345\205\263\344\272\216", 0));
    } // retranslateUi

};

namespace Ui {
    class RayTraceWindowsClass: public Ui_RayTraceWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYTRACEWINDOWS_H
