/********************************************************************************
** Form generated from reading UI file 'raytracewindows.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RayTraceWindowsClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionStart;
    QAction *actionPause;
    QAction *actionResume;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *renderImage;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBarFile;
    QMenu *menuFile;
    QMenu *menuRender;
    QMenu *menuView;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RayTraceWindowsClass)
    {
        if (RayTraceWindowsClass->objectName().isEmpty())
            RayTraceWindowsClass->setObjectName(QStringLiteral("RayTraceWindowsClass"));
        RayTraceWindowsClass->setWindowModality(Qt::WindowModal);
        RayTraceWindowsClass->setEnabled(true);
        RayTraceWindowsClass->resize(551, 488);
        RayTraceWindowsClass->setMaximumSize(QSize(613, 16777215));
        RayTraceWindowsClass->setContextMenuPolicy(Qt::DefaultContextMenu);
        RayTraceWindowsClass->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/RayTraceWindows/images/th.png"), QSize(), QIcon::Normal, QIcon::Off);
        RayTraceWindowsClass->setWindowIcon(icon);
        actionNew = new QAction(RayTraceWindowsClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(RayTraceWindowsClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionAbout = new QAction(RayTraceWindowsClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSave = new QAction(RayTraceWindowsClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionStart = new QAction(RayTraceWindowsClass);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionPause = new QAction(RayTraceWindowsClass);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionResume = new QAction(RayTraceWindowsClass);
        actionResume->setObjectName(QStringLiteral("actionResume"));
        centralWidget = new QWidget(RayTraceWindowsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        renderImage = new QLabel(centralWidget);
        renderImage->setObjectName(QStringLiteral("renderImage"));
        renderImage->setMaximumSize(QSize(999999, 999999));
        QFont font;
        font.setFamily(QStringLiteral("System"));
        font.setPointSize(32);
        renderImage->setFont(font);

        gridLayout_2->addWidget(renderImage, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        RayTraceWindowsClass->setCentralWidget(centralWidget);
        menuBarFile = new QMenuBar(RayTraceWindowsClass);
        menuBarFile->setObjectName(QStringLiteral("menuBarFile"));
        menuBarFile->setGeometry(QRect(0, 0, 551, 20));
        menuFile = new QMenu(menuBarFile);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRender = new QMenu(menuBarFile);
        menuRender->setObjectName(QStringLiteral("menuRender"));
        menuView = new QMenu(menuBarFile);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menuBarFile);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        RayTraceWindowsClass->setMenuBar(menuBarFile);
        statusBar = new QStatusBar(RayTraceWindowsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setContextMenuPolicy(Qt::ActionsContextMenu);
        statusBar->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        statusBar->setSizeGripEnabled(true);
        RayTraceWindowsClass->setStatusBar(statusBar);

        menuBarFile->addAction(menuFile->menuAction());
        menuBarFile->addAction(menuRender->menuAction());
        menuBarFile->addAction(menuView->menuAction());
        menuBarFile->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuRender->addAction(actionStart);
        menuRender->addAction(actionPause);
        menuRender->addAction(actionResume);
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
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("RayTraceWindowsClass", "\346\211\223\345\274\200", 0));
#endif // QT_NO_STATUSTIP
        actionOpen->setShortcut(QApplication::translate("RayTraceWindowsClass", "Ctrl+O", 0));
        actionAbout->setText(QApplication::translate("RayTraceWindowsClass", "\345\205\263\344\272\216", 0));
        actionSave->setText(QApplication::translate("RayTraceWindowsClass", "\344\277\235\345\255\230", 0));
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("RayTraceWindowsClass", "\344\277\235\345\255\230", 0));
#endif // QT_NO_STATUSTIP
        actionSave->setShortcut(QApplication::translate("RayTraceWindowsClass", "Ctrl+S", 0));
        actionStart->setText(QApplication::translate("RayTraceWindowsClass", "\345\274\200\345\247\213", 0));
#ifndef QT_NO_STATUSTIP
        actionStart->setStatusTip(QApplication::translate("RayTraceWindowsClass", "\345\274\200\345\247\213", 0));
#endif // QT_NO_STATUSTIP
        actionStart->setShortcut(QApplication::translate("RayTraceWindowsClass", "Ctrl+R", 0));
        actionPause->setText(QApplication::translate("RayTraceWindowsClass", "\346\232\202\345\201\234", 0));
#ifndef QT_NO_STATUSTIP
        actionPause->setStatusTip(QApplication::translate("RayTraceWindowsClass", "\346\232\202\345\201\234", 0));
#endif // QT_NO_STATUSTIP
        actionPause->setShortcut(QApplication::translate("RayTraceWindowsClass", "Ctrl+P", 0));
        actionResume->setText(QApplication::translate("RayTraceWindowsClass", "\346\201\242\345\244\215", 0));
#ifndef QT_NO_STATUSTIP
        actionResume->setStatusTip(QApplication::translate("RayTraceWindowsClass", "\346\201\242\345\244\215", 0));
#endif // QT_NO_STATUSTIP
        actionResume->setShortcut(QApplication::translate("RayTraceWindowsClass", "Ctrl+E", 0));
        renderImage->setText(QApplication::translate("RayTraceWindowsClass", "\346\270\262\346\237\223\345\233\276\347\211\207", 0));
        menuFile->setTitle(QApplication::translate("RayTraceWindowsClass", "\346\226\207\344\273\266", 0));
        menuRender->setTitle(QApplication::translate("RayTraceWindowsClass", "\346\270\262\346\237\223", 0));
        menuView->setTitle(QApplication::translate("RayTraceWindowsClass", "\350\247\206\345\233\276", 0));
        menuAbout->setTitle(QApplication::translate("RayTraceWindowsClass", "\345\205\263\344\272\216", 0));
    } // retranslateUi

};

namespace Ui {
    class RayTraceWindowsClass: public Ui_RayTraceWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYTRACEWINDOWS_H
