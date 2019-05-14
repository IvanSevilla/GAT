/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewProject;
    QAction *actionLoad_Project;
    QAction *actionSave_Project;
    QAction *actionClose_Project;
    QAction *actionAdd_Image;
    QAction *actionAdd_Point_Cloud;
    QAction *actionAdd_Matrix;
    QAction *actionDelete_Image;
    QAction *actionDelete_Matrix;
    QAction *actionDelete_Matrix_2;
    QAction *actionMiniMap;
    QAction *actionDelete_Poliline;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Btn_Zoom_In;
    QPushButton *Btn_Zoom_Out;
    QPushButton *Btn_Edit;
    QVBoxLayout *verticalLayout_4;
    QPushButton *Btn_Add_Point;
    QPushButton *Btn_Del_Point;
    QPushButton *Btn_Move;
    QPushButton *Btn_Undo;
    QPushButton *Btn_Do;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QRadioButton *Group0;
    QPushButton *Visibility0;
    QRadioButton *Group1;
    QPushButton *Visibility1;
    QRadioButton *Group2;
    QPushButton *Visibility2;
    QRadioButton *Group3;
    QPushButton *Visibility3;
    QRadioButton *Group4;
    QPushButton *Visibility4;
    QRadioButton *Group5;
    QPushButton *Visibility5;
    QRadioButton *Group6;
    QPushButton *Visibility6;
    QRadioButton *Group7;
    QPushButton *Visibility7;
    QPushButton *showPolilines;
    QLabel *labelPolilines;
    QListWidget *polilines;
    QMenuBar *menuBar;
    QMenu *menuGEOApp;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(806, 1039);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionNewProject = new QAction(MainWindow);
        actionNewProject->setObjectName(QString::fromUtf8("actionNewProject"));
        actionLoad_Project = new QAction(MainWindow);
        actionLoad_Project->setObjectName(QString::fromUtf8("actionLoad_Project"));
        actionSave_Project = new QAction(MainWindow);
        actionSave_Project->setObjectName(QString::fromUtf8("actionSave_Project"));
        actionClose_Project = new QAction(MainWindow);
        actionClose_Project->setObjectName(QString::fromUtf8("actionClose_Project"));
        actionAdd_Image = new QAction(MainWindow);
        actionAdd_Image->setObjectName(QString::fromUtf8("actionAdd_Image"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/image-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Image->setIcon(icon);
        actionAdd_Point_Cloud = new QAction(MainWindow);
        actionAdd_Point_Cloud->setObjectName(QString::fromUtf8("actionAdd_Point_Cloud"));
        actionAdd_Matrix = new QAction(MainWindow);
        actionAdd_Matrix->setObjectName(QString::fromUtf8("actionAdd_Matrix"));
        actionDelete_Image = new QAction(MainWindow);
        actionDelete_Image->setObjectName(QString::fromUtf8("actionDelete_Image"));
        actionDelete_Matrix = new QAction(MainWindow);
        actionDelete_Matrix->setObjectName(QString::fromUtf8("actionDelete_Matrix"));
        actionDelete_Matrix_2 = new QAction(MainWindow);
        actionDelete_Matrix_2->setObjectName(QString::fromUtf8("actionDelete_Matrix_2"));
        actionMiniMap = new QAction(MainWindow);
        actionMiniMap->setObjectName(QString::fromUtf8("actionMiniMap"));
        actionMiniMap->setCheckable(true);
        actionMiniMap->setChecked(false);
        actionDelete_Poliline = new QAction(MainWindow);
        actionDelete_Poliline->setObjectName(QString::fromUtf8("actionDelete_Poliline"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_9 = new QHBoxLayout(centralWidget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setInteractive(true);
        graphicsView->setAlignment(Qt::AlignCenter);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        horizontalLayout_7->addWidget(graphicsView);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        Btn_Zoom_In = new QPushButton(centralWidget);
        Btn_Zoom_In->setObjectName(QString::fromUtf8("Btn_Zoom_In"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Btn_Zoom_In->sizePolicy().hasHeightForWidth());
        Btn_Zoom_In->setSizePolicy(sizePolicy1);
        Btn_Zoom_In->setCursor(QCursor(Qt::ArrowCursor));
        Btn_Zoom_In->setMouseTracking(true);
        Btn_Zoom_In->setTabletTracking(true);
        Btn_Zoom_In->setToolTipDuration(200000);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/assets/search-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Zoom_In->setIcon(icon1);
        Btn_Zoom_In->setAutoDefault(false);

        verticalLayout_3->addWidget(Btn_Zoom_In);

        Btn_Zoom_Out = new QPushButton(centralWidget);
        Btn_Zoom_Out->setObjectName(QString::fromUtf8("Btn_Zoom_Out"));
        sizePolicy1.setHeightForWidth(Btn_Zoom_Out->sizePolicy().hasHeightForWidth());
        Btn_Zoom_Out->setSizePolicy(sizePolicy1);
        Btn_Zoom_Out->setMouseTracking(true);
        Btn_Zoom_Out->setTabletTracking(true);
        Btn_Zoom_Out->setToolTipDuration(200000);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/assets/search-minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Zoom_Out->setIcon(icon2);
        Btn_Zoom_Out->setAutoDefault(false);

        verticalLayout_3->addWidget(Btn_Zoom_Out);

        Btn_Edit = new QPushButton(centralWidget);
        Btn_Edit->setObjectName(QString::fromUtf8("Btn_Edit"));
        sizePolicy1.setHeightForWidth(Btn_Edit->sizePolicy().hasHeightForWidth());
        Btn_Edit->setSizePolicy(sizePolicy1);
        Btn_Edit->setMouseTracking(true);
        Btn_Edit->setTabletTracking(true);
        Btn_Edit->setToolTipDuration(200000);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/assets/edit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Edit->setIcon(icon3);
        Btn_Edit->setCheckable(true);
        Btn_Edit->setAutoDefault(false);

        verticalLayout_3->addWidget(Btn_Edit);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        Btn_Add_Point = new QPushButton(centralWidget);
        Btn_Add_Point->setObjectName(QString::fromUtf8("Btn_Add_Point"));
        sizePolicy.setHeightForWidth(Btn_Add_Point->sizePolicy().hasHeightForWidth());
        Btn_Add_Point->setSizePolicy(sizePolicy);
        Btn_Add_Point->setMouseTracking(true);
        Btn_Add_Point->setTabletTracking(true);
        Btn_Add_Point->setToolTipDuration(200000);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/assets/plus-circle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Add_Point->setIcon(icon4);
        Btn_Add_Point->setCheckable(true);
        Btn_Add_Point->setAutoDefault(false);
        Btn_Add_Point->setFlat(false);

        verticalLayout_4->addWidget(Btn_Add_Point);

        Btn_Del_Point = new QPushButton(centralWidget);
        Btn_Del_Point->setObjectName(QString::fromUtf8("Btn_Del_Point"));
        sizePolicy.setHeightForWidth(Btn_Del_Point->sizePolicy().hasHeightForWidth());
        Btn_Del_Point->setSizePolicy(sizePolicy);
        Btn_Del_Point->setMouseTracking(true);
        Btn_Del_Point->setTabletTracking(true);
        Btn_Del_Point->setToolTipDuration(200000);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/assets/minus-circle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Del_Point->setIcon(icon5);
        Btn_Del_Point->setCheckable(true);
        Btn_Del_Point->setAutoDefault(false);
        Btn_Del_Point->setFlat(false);

        verticalLayout_4->addWidget(Btn_Del_Point);

        Btn_Move = new QPushButton(centralWidget);
        Btn_Move->setObjectName(QString::fromUtf8("Btn_Move"));
        sizePolicy.setHeightForWidth(Btn_Move->sizePolicy().hasHeightForWidth());
        Btn_Move->setSizePolicy(sizePolicy);
        Btn_Move->setMouseTracking(true);
        Btn_Move->setTabletTracking(true);
        Btn_Move->setToolTipDuration(200000);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/assets/expand-arrows.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Move->setIcon(icon6);
        Btn_Move->setCheckable(true);
        Btn_Move->setAutoDefault(false);
        Btn_Move->setFlat(false);

        verticalLayout_4->addWidget(Btn_Move);

        Btn_Undo = new QPushButton(centralWidget);
        Btn_Undo->setObjectName(QString::fromUtf8("Btn_Undo"));
        sizePolicy.setHeightForWidth(Btn_Undo->sizePolicy().hasHeightForWidth());
        Btn_Undo->setSizePolicy(sizePolicy);
        Btn_Undo->setMouseTracking(true);
        Btn_Undo->setTabletTracking(true);
        Btn_Undo->setToolTipDuration(200000);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/assets/undo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Undo->setIcon(icon7);
        Btn_Undo->setCheckable(false);
        Btn_Undo->setAutoDefault(false);
        Btn_Undo->setFlat(false);

        verticalLayout_4->addWidget(Btn_Undo);

        Btn_Do = new QPushButton(centralWidget);
        Btn_Do->setObjectName(QString::fromUtf8("Btn_Do"));
        sizePolicy.setHeightForWidth(Btn_Do->sizePolicy().hasHeightForWidth());
        Btn_Do->setSizePolicy(sizePolicy);
        Btn_Do->setMouseTracking(true);
        Btn_Do->setTabletTracking(true);
        Btn_Do->setToolTipDuration(-3);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/assets/redo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Do->setIcon(icon8);
        Btn_Do->setCheckable(false);
        Btn_Do->setAutoDefault(false);
        Btn_Do->setFlat(false);

        verticalLayout_4->addWidget(Btn_Do);


        verticalLayout_3->addLayout(verticalLayout_4);


        verticalLayout->addLayout(verticalLayout_3);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignJustify|Qt::AlignTop);
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        Group0 = new QRadioButton(centralWidget);
        Group0->setObjectName(QString::fromUtf8("Group0"));
        sizePolicy.setHeightForWidth(Group0->sizePolicy().hasHeightForWidth());
        Group0->setSizePolicy(sizePolicy);
        Group0->setAutoFillBackground(false);
        Group0->setStyleSheet(QString::fromUtf8("color: rgb(228,26,28);\n"
"background-color: rgb(228,26,28);"));
        Group0->setChecked(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, Group0);

        Visibility0 = new QPushButton(centralWidget);
        Visibility0->setObjectName(QString::fromUtf8("Visibility0"));
        sizePolicy.setHeightForWidth(Visibility0->sizePolicy().hasHeightForWidth());
        Visibility0->setSizePolicy(sizePolicy);
        Visibility0->setMaximumSize(QSize(38, 38));
        Visibility0->setToolTipDuration(5);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/assets/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon9.addFile(QString::fromUtf8("assets/eye-slash.svg"), QSize(), QIcon::Active, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Selected, QIcon::Off);
        icon9.addFile(QString::fromUtf8("assets/eye.svg"), QSize(), QIcon::Selected, QIcon::On);
        Visibility0->setIcon(icon9);
        Visibility0->setCheckable(true);
        Visibility0->setChecked(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, Visibility0);

        Group1 = new QRadioButton(centralWidget);
        Group1->setObjectName(QString::fromUtf8("Group1"));
        sizePolicy.setHeightForWidth(Group1->sizePolicy().hasHeightForWidth());
        Group1->setSizePolicy(sizePolicy);
        Group1->setAutoFillBackground(false);
        Group1->setStyleSheet(QString::fromUtf8("background-color: rgb(55,126,184);\n"
"color: rgb(55,126,184);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Group1);

        Visibility1 = new QPushButton(centralWidget);
        Visibility1->setObjectName(QString::fromUtf8("Visibility1"));
        sizePolicy.setHeightForWidth(Visibility1->sizePolicy().hasHeightForWidth());
        Visibility1->setSizePolicy(sizePolicy);
        Visibility1->setMaximumSize(QSize(38, 38));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/assets/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        Visibility1->setIcon(icon10);
        Visibility1->setCheckable(true);
        Visibility1->setChecked(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, Visibility1);

        Group2 = new QRadioButton(centralWidget);
        Group2->setObjectName(QString::fromUtf8("Group2"));
        sizePolicy.setHeightForWidth(Group2->sizePolicy().hasHeightForWidth());
        Group2->setSizePolicy(sizePolicy);
        Group2->setAutoFillBackground(false);
        Group2->setStyleSheet(QString::fromUtf8("background-color: rgb(77,175,74);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Group2);

        Visibility2 = new QPushButton(centralWidget);
        Visibility2->setObjectName(QString::fromUtf8("Visibility2"));
        sizePolicy.setHeightForWidth(Visibility2->sizePolicy().hasHeightForWidth());
        Visibility2->setSizePolicy(sizePolicy);
        Visibility2->setMaximumSize(QSize(38, 38));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/assets/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon11.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Disabled, QIcon::Off);
        Visibility2->setIcon(icon11);
        Visibility2->setCheckable(true);
        Visibility2->setChecked(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, Visibility2);

        Group3 = new QRadioButton(centralWidget);
        Group3->setObjectName(QString::fromUtf8("Group3"));
        sizePolicy.setHeightForWidth(Group3->sizePolicy().hasHeightForWidth());
        Group3->setSizePolicy(sizePolicy);
        Group3->setAutoFillBackground(false);
        Group3->setStyleSheet(QString::fromUtf8("background-color: rgb(152,78,163);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Group3);

        Visibility3 = new QPushButton(centralWidget);
        Visibility3->setObjectName(QString::fromUtf8("Visibility3"));
        sizePolicy.setHeightForWidth(Visibility3->sizePolicy().hasHeightForWidth());
        Visibility3->setSizePolicy(sizePolicy);
        Visibility3->setMaximumSize(QSize(38, 38));
        Visibility3->setIcon(icon10);
        Visibility3->setCheckable(true);
        Visibility3->setChecked(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, Visibility3);

        Group4 = new QRadioButton(centralWidget);
        Group4->setObjectName(QString::fromUtf8("Group4"));
        sizePolicy.setHeightForWidth(Group4->sizePolicy().hasHeightForWidth());
        Group4->setSizePolicy(sizePolicy);
        Group4->setAutoFillBackground(false);
        Group4->setStyleSheet(QString::fromUtf8("background-color: rgb(255,127,0);"));

        formLayout->setWidget(5, QFormLayout::LabelRole, Group4);

        Visibility4 = new QPushButton(centralWidget);
        Visibility4->setObjectName(QString::fromUtf8("Visibility4"));
        sizePolicy.setHeightForWidth(Visibility4->sizePolicy().hasHeightForWidth());
        Visibility4->setSizePolicy(sizePolicy);
        Visibility4->setMaximumSize(QSize(38, 38));
        Visibility4->setIcon(icon10);
        Visibility4->setCheckable(true);
        Visibility4->setChecked(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, Visibility4);

        Group5 = new QRadioButton(centralWidget);
        Group5->setObjectName(QString::fromUtf8("Group5"));
        sizePolicy.setHeightForWidth(Group5->sizePolicy().hasHeightForWidth());
        Group5->setSizePolicy(sizePolicy);
        Group5->setAutoFillBackground(false);
        Group5->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,51);"));

        formLayout->setWidget(6, QFormLayout::LabelRole, Group5);

        Visibility5 = new QPushButton(centralWidget);
        Visibility5->setObjectName(QString::fromUtf8("Visibility5"));
        sizePolicy.setHeightForWidth(Visibility5->sizePolicy().hasHeightForWidth());
        Visibility5->setSizePolicy(sizePolicy);
        Visibility5->setMaximumSize(QSize(38, 38));
        Visibility5->setIcon(icon10);
        Visibility5->setCheckable(true);
        Visibility5->setChecked(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, Visibility5);

        Group6 = new QRadioButton(centralWidget);
        Group6->setObjectName(QString::fromUtf8("Group6"));
        sizePolicy.setHeightForWidth(Group6->sizePolicy().hasHeightForWidth());
        Group6->setSizePolicy(sizePolicy);
        Group6->setAutoFillBackground(false);
        Group6->setStyleSheet(QString::fromUtf8("background-color: rgb(166,86,40);"));

        formLayout->setWidget(7, QFormLayout::LabelRole, Group6);

        Visibility6 = new QPushButton(centralWidget);
        Visibility6->setObjectName(QString::fromUtf8("Visibility6"));
        sizePolicy.setHeightForWidth(Visibility6->sizePolicy().hasHeightForWidth());
        Visibility6->setSizePolicy(sizePolicy);
        Visibility6->setMaximumSize(QSize(38, 38));
        Visibility6->setIcon(icon10);
        Visibility6->setCheckable(true);
        Visibility6->setChecked(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, Visibility6);

        Group7 = new QRadioButton(centralWidget);
        Group7->setObjectName(QString::fromUtf8("Group7"));
        sizePolicy.setHeightForWidth(Group7->sizePolicy().hasHeightForWidth());
        Group7->setSizePolicy(sizePolicy);
        Group7->setLayoutDirection(Qt::LeftToRight);
        Group7->setAutoFillBackground(false);
        Group7->setStyleSheet(QString::fromUtf8("background-color: rgb(247,129,191);"));

        formLayout->setWidget(8, QFormLayout::LabelRole, Group7);

        Visibility7 = new QPushButton(centralWidget);
        Visibility7->setObjectName(QString::fromUtf8("Visibility7"));
        sizePolicy.setHeightForWidth(Visibility7->sizePolicy().hasHeightForWidth());
        Visibility7->setSizePolicy(sizePolicy);
        Visibility7->setMaximumSize(QSize(38, 38));
        Visibility7->setIcon(icon10);
        Visibility7->setCheckable(true);
        Visibility7->setChecked(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, Visibility7);

        showPolilines = new QPushButton(centralWidget);
        showPolilines->setObjectName(QString::fromUtf8("showPolilines"));
        sizePolicy.setHeightForWidth(showPolilines->sizePolicy().hasHeightForWidth());
        showPolilines->setSizePolicy(sizePolicy);
        showPolilines->setCheckable(true);

        formLayout->setWidget(9, QFormLayout::LabelRole, showPolilines);


        verticalLayout_2->addLayout(formLayout);

        labelPolilines = new QLabel(centralWidget);
        labelPolilines->setObjectName(QString::fromUtf8("labelPolilines"));

        verticalLayout_2->addWidget(labelPolilines);

        polilines = new QListWidget(centralWidget);
        polilines->setObjectName(QString::fromUtf8("polilines"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(polilines->sizePolicy().hasHeightForWidth());
        polilines->setSizePolicy(sizePolicy2);
        polilines->setMinimumSize(QSize(60, 200));
        polilines->setMaximumSize(QSize(60, 400));
        polilines->setBaseSize(QSize(50, 200));
        polilines->setBatchSize(100);
        polilines->setItemAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(polilines);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout_9->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 806, 22));
        menuGEOApp = new QMenu(menuBar);
        menuGEOApp->setObjectName(QString::fromUtf8("menuGEOApp"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGEOApp->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(actionNewProject);
        menuFile->addAction(actionLoad_Project);
        menuFile->addAction(actionSave_Project);
        menuFile->addAction(actionClose_Project);
        menuEdit->addAction(actionAdd_Image);
        menuEdit->addAction(actionAdd_Point_Cloud);
        menuEdit->addAction(actionAdd_Matrix);
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addAction(actionDelete_Image);
        menuEdit->addAction(actionDelete_Matrix);
        menuEdit->addAction(actionDelete_Matrix_2);
        menuEdit->addSeparator();
        menuEdit->addAction(actionDelete_Poliline);
        menuView->addAction(actionMiniMap);
        mainToolBar->addAction(actionAdd_Image);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GEOApp", nullptr));
        actionNewProject->setText(QApplication::translate("MainWindow", "New Project", nullptr));
        actionLoad_Project->setText(QApplication::translate("MainWindow", "Load Project", nullptr));
        actionSave_Project->setText(QApplication::translate("MainWindow", "Save Project", nullptr));
        actionClose_Project->setText(QApplication::translate("MainWindow", "Close Project", nullptr));
        actionAdd_Image->setText(QApplication::translate("MainWindow", "Add Image", nullptr));
        actionAdd_Point_Cloud->setText(QApplication::translate("MainWindow", "Add Point Cloud", nullptr));
        actionAdd_Matrix->setText(QApplication::translate("MainWindow", "Add Matrix", nullptr));
        actionDelete_Image->setText(QApplication::translate("MainWindow", "Delete Image", nullptr));
        actionDelete_Matrix->setText(QApplication::translate("MainWindow", "Delete Point Cloud", nullptr));
        actionDelete_Matrix_2->setText(QApplication::translate("MainWindow", "Delete Matrix", nullptr));
        actionMiniMap->setText(QApplication::translate("MainWindow", "MiniMap", nullptr));
        actionDelete_Poliline->setText(QApplication::translate("MainWindow", "Delete Poliline", nullptr));
#ifndef QT_NO_TOOLTIP
        Btn_Zoom_In->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Btn_Zoom_In->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Zoom_In->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Zoom_In->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_Zoom_Out->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Btn_Zoom_Out->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Zoom_Out->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Zoom_Out->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_Edit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Btn_Edit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Edit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Edit->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_Add_Point->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Btn_Add_Point->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Add_Point->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Add_Point->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_Del_Point->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Btn_Del_Point->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Del_Point->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Del_Point->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_Move->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Btn_Move->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Move->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Move->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_Undo->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Undo->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Undo->setText(QString());
#ifndef QT_NO_TOOLTIP
        Btn_Do->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        Btn_Do->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Btn_Do->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Categories", nullptr));
        Group0->setText(QString());
        Visibility0->setText(QString());
        Group1->setText(QString());
        Visibility1->setText(QString());
        Group2->setText(QString());
        Visibility2->setText(QString());
        Group3->setText(QString());
        Visibility3->setText(QString());
        Group4->setText(QString());
        Visibility4->setText(QString());
        Group5->setText(QString());
        Visibility5->setText(QString());
        Group6->setText(QString());
        Visibility6->setText(QString());
        Group7->setText(QString());
        Visibility7->setText(QString());
        showPolilines->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelPolilines->setText(QApplication::translate("MainWindow", "Polilines List", nullptr));
        menuGEOApp->setTitle(QApplication::translate("MainWindow", "GEOApp", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
