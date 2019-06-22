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
    QAction *actionMiniMap;
    QAction *actionDelete_Poliline;
    QAction *actionNext_Image;
    QAction *actionPrevious_Image;
    QAction *actionAdd_Calibration;
    QAction *actionAdd_GeoData;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayoutButton;
    QPushButton *Btn_Zoom_In;
    QPushButton *Btn_Zoom_Out;
    QPushButton *Btn_Edit;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *Btn_Add_Point;
    QPushButton *Btn_Del_Point;
    QPushButton *Btn_Move;
    QPushButton *Btn_Undo;
    QPushButton *Btn_Do;
    QGraphicsView *graphicsView_2;
    QLabel *label;
    QHBoxLayout *horLayout_3;
    QVBoxLayout *verLayout_2;
    QPushButton *showPolilines;
    QLabel *labelPolilines;
    QListWidget *polilines;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *Cat0Layout;
    QRadioButton *Group0;
    QPushButton *Visibility0;
    QHBoxLayout *Cat1Layout;
    QRadioButton *Group1;
    QPushButton *Visibility1;
    QHBoxLayout *Cat2Layout;
    QRadioButton *Group2;
    QPushButton *Visibility2;
    QHBoxLayout *Cat3Layout;
    QRadioButton *Group3;
    QPushButton *Visibility3;
    QHBoxLayout *Cat4Layout;
    QRadioButton *Group4;
    QPushButton *Visibility4;
    QHBoxLayout *Cat5Layout;
    QRadioButton *Group5;
    QPushButton *Visibility5;
    QHBoxLayout *Cat6Layout;
    QRadioButton *Group6;
    QPushButton *Visibility6;
    QHBoxLayout *Cat7Layout;
    QRadioButton *Group7;
    QPushButton *Visibility7;
    QMenuBar *menuBar;
    QMenu *GAT;
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
        MainWindow->resize(440, 707);
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
        actionNewProject->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/file-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewProject->setIcon(icon);
        actionLoad_Project = new QAction(MainWindow);
        actionLoad_Project->setObjectName(QString::fromUtf8("actionLoad_Project"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/assets/file-upload-alt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Project->setIcon(icon1);
        actionSave_Project = new QAction(MainWindow);
        actionSave_Project->setObjectName(QString::fromUtf8("actionSave_Project"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/assets/file-download-alt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Project->setIcon(icon2);
        actionClose_Project = new QAction(MainWindow);
        actionClose_Project->setObjectName(QString::fromUtf8("actionClose_Project"));
        actionAdd_Image = new QAction(MainWindow);
        actionAdd_Image->setObjectName(QString::fromUtf8("actionAdd_Image"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/assets/image-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Image->setIcon(icon3);
        actionAdd_Point_Cloud = new QAction(MainWindow);
        actionAdd_Point_Cloud->setObjectName(QString::fromUtf8("actionAdd_Point_Cloud"));
        actionAdd_Matrix = new QAction(MainWindow);
        actionAdd_Matrix->setObjectName(QString::fromUtf8("actionAdd_Matrix"));
        actionMiniMap = new QAction(MainWindow);
        actionMiniMap->setObjectName(QString::fromUtf8("actionMiniMap"));
        actionMiniMap->setCheckable(true);
        actionMiniMap->setChecked(false);
        actionDelete_Poliline = new QAction(MainWindow);
        actionDelete_Poliline->setObjectName(QString::fromUtf8("actionDelete_Poliline"));
        actionNext_Image = new QAction(MainWindow);
        actionNext_Image->setObjectName(QString::fromUtf8("actionNext_Image"));
        actionPrevious_Image = new QAction(MainWindow);
        actionPrevious_Image->setObjectName(QString::fromUtf8("actionPrevious_Image"));
        actionAdd_Calibration = new QAction(MainWindow);
        actionAdd_Calibration->setObjectName(QString::fromUtf8("actionAdd_Calibration"));
        actionAdd_GeoData = new QAction(MainWindow);
        actionAdd_GeoData->setObjectName(QString::fromUtf8("actionAdd_GeoData"));
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
        horizontalLayoutButton = new QHBoxLayout();
        horizontalLayoutButton->setSpacing(6);
        horizontalLayoutButton->setObjectName(QString::fromUtf8("horizontalLayoutButton"));
        horizontalLayoutButton->setSizeConstraint(QLayout::SetMinimumSize);
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/assets/search-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Zoom_In->setIcon(icon4);
        Btn_Zoom_In->setAutoDefault(false);

        horizontalLayoutButton->addWidget(Btn_Zoom_In);

        Btn_Zoom_Out = new QPushButton(centralWidget);
        Btn_Zoom_Out->setObjectName(QString::fromUtf8("Btn_Zoom_Out"));
        sizePolicy1.setHeightForWidth(Btn_Zoom_Out->sizePolicy().hasHeightForWidth());
        Btn_Zoom_Out->setSizePolicy(sizePolicy1);
        Btn_Zoom_Out->setMouseTracking(true);
        Btn_Zoom_Out->setTabletTracking(true);
        Btn_Zoom_Out->setToolTipDuration(200000);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/assets/search-minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Zoom_Out->setIcon(icon5);
        Btn_Zoom_Out->setAutoDefault(false);

        horizontalLayoutButton->addWidget(Btn_Zoom_Out);

        Btn_Edit = new QPushButton(centralWidget);
        Btn_Edit->setObjectName(QString::fromUtf8("Btn_Edit"));
        sizePolicy1.setHeightForWidth(Btn_Edit->sizePolicy().hasHeightForWidth());
        Btn_Edit->setSizePolicy(sizePolicy1);
        Btn_Edit->setMouseTracking(true);
        Btn_Edit->setTabletTracking(true);
        Btn_Edit->setToolTipDuration(200000);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/assets/edit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Edit->setIcon(icon6);
        Btn_Edit->setCheckable(true);
        Btn_Edit->setAutoDefault(false);

        horizontalLayoutButton->addWidget(Btn_Edit);


        verticalLayout_3->addLayout(horizontalLayoutButton);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setSpacing(6);
        horizontalLayoutButtons->setObjectName(QString::fromUtf8("horizontalLayoutButtons"));
        horizontalLayoutButtons->setSizeConstraint(QLayout::SetMinimumSize);
        Btn_Add_Point = new QPushButton(centralWidget);
        Btn_Add_Point->setObjectName(QString::fromUtf8("Btn_Add_Point"));
        sizePolicy.setHeightForWidth(Btn_Add_Point->sizePolicy().hasHeightForWidth());
        Btn_Add_Point->setSizePolicy(sizePolicy);
        Btn_Add_Point->setMouseTracking(true);
        Btn_Add_Point->setTabletTracking(true);
        Btn_Add_Point->setToolTipDuration(200000);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/assets/plus-circle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Add_Point->setIcon(icon7);
        Btn_Add_Point->setCheckable(true);
        Btn_Add_Point->setAutoDefault(false);
        Btn_Add_Point->setFlat(false);

        horizontalLayoutButtons->addWidget(Btn_Add_Point);

        Btn_Del_Point = new QPushButton(centralWidget);
        Btn_Del_Point->setObjectName(QString::fromUtf8("Btn_Del_Point"));
        sizePolicy.setHeightForWidth(Btn_Del_Point->sizePolicy().hasHeightForWidth());
        Btn_Del_Point->setSizePolicy(sizePolicy);
        Btn_Del_Point->setMouseTracking(true);
        Btn_Del_Point->setTabletTracking(true);
        Btn_Del_Point->setToolTipDuration(200000);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/assets/minus-circle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Del_Point->setIcon(icon8);
        Btn_Del_Point->setCheckable(true);
        Btn_Del_Point->setAutoDefault(false);
        Btn_Del_Point->setFlat(false);

        horizontalLayoutButtons->addWidget(Btn_Del_Point);

        Btn_Move = new QPushButton(centralWidget);
        Btn_Move->setObjectName(QString::fromUtf8("Btn_Move"));
        sizePolicy.setHeightForWidth(Btn_Move->sizePolicy().hasHeightForWidth());
        Btn_Move->setSizePolicy(sizePolicy);
        Btn_Move->setMouseTracking(true);
        Btn_Move->setTabletTracking(true);
        Btn_Move->setToolTipDuration(200000);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/assets/expand-arrows.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Move->setIcon(icon9);
        Btn_Move->setCheckable(true);
        Btn_Move->setAutoDefault(false);
        Btn_Move->setFlat(false);

        horizontalLayoutButtons->addWidget(Btn_Move);

        Btn_Undo = new QPushButton(centralWidget);
        Btn_Undo->setObjectName(QString::fromUtf8("Btn_Undo"));
        sizePolicy.setHeightForWidth(Btn_Undo->sizePolicy().hasHeightForWidth());
        Btn_Undo->setSizePolicy(sizePolicy);
        Btn_Undo->setMouseTracking(true);
        Btn_Undo->setTabletTracking(true);
        Btn_Undo->setToolTipDuration(200000);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/assets/undo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Undo->setIcon(icon10);
        Btn_Undo->setCheckable(false);
        Btn_Undo->setAutoDefault(false);
        Btn_Undo->setFlat(false);

        horizontalLayoutButtons->addWidget(Btn_Undo);

        Btn_Do = new QPushButton(centralWidget);
        Btn_Do->setObjectName(QString::fromUtf8("Btn_Do"));
        sizePolicy.setHeightForWidth(Btn_Do->sizePolicy().hasHeightForWidth());
        Btn_Do->setSizePolicy(sizePolicy);
        Btn_Do->setMouseTracking(true);
        Btn_Do->setTabletTracking(true);
        Btn_Do->setToolTipDuration(-3);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/assets/redo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Do->setIcon(icon11);
        Btn_Do->setCheckable(false);
        Btn_Do->setAutoDefault(false);
        Btn_Do->setFlat(false);

        horizontalLayoutButtons->addWidget(Btn_Do);


        verticalLayout_3->addLayout(horizontalLayoutButtons);


        verticalLayout->addLayout(verticalLayout_3);

        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        sizePolicy.setHeightForWidth(graphicsView_2->sizePolicy().hasHeightForWidth());
        graphicsView_2->setSizePolicy(sizePolicy);
        graphicsView_2->setMaximumSize(QSize(270, 270));

        verticalLayout->addWidget(graphicsView_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(label);

        horLayout_3 = new QHBoxLayout();
        horLayout_3->setSpacing(6);
        horLayout_3->setObjectName(QString::fromUtf8("horLayout_3"));
        verLayout_2 = new QVBoxLayout();
        verLayout_2->setSpacing(6);
        verLayout_2->setObjectName(QString::fromUtf8("verLayout_2"));
        showPolilines = new QPushButton(centralWidget);
        showPolilines->setObjectName(QString::fromUtf8("showPolilines"));
        sizePolicy.setHeightForWidth(showPolilines->sizePolicy().hasHeightForWidth());
        showPolilines->setSizePolicy(sizePolicy);
        showPolilines->setCheckable(true);

        verLayout_2->addWidget(showPolilines);

        labelPolilines = new QLabel(centralWidget);
        labelPolilines->setObjectName(QString::fromUtf8("labelPolilines"));

        verLayout_2->addWidget(labelPolilines);

        polilines = new QListWidget(centralWidget);
        polilines->setObjectName(QString::fromUtf8("polilines"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(polilines->sizePolicy().hasHeightForWidth());
        polilines->setSizePolicy(sizePolicy2);
        polilines->setMinimumSize(QSize(200, 100));
        polilines->setMaximumSize(QSize(60, 400));
        polilines->setBaseSize(QSize(50, 200));
        polilines->setMouseTracking(true);
        polilines->setFocusPolicy(Qt::StrongFocus);
        polilines->setAcceptDrops(true);
        polilines->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        polilines->setSelectionMode(QAbstractItemView::SingleSelection);
        polilines->setSelectionBehavior(QAbstractItemView::SelectItems);
        polilines->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        polilines->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        polilines->setProperty("isWrapping", QVariant(false));
        polilines->setViewMode(QListView::IconMode);
        polilines->setUniformItemSizes(true);
        polilines->setBatchSize(100);
        polilines->setItemAlignment(Qt::AlignCenter);

        verLayout_2->addWidget(polilines);


        horLayout_3->addLayout(verLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        Cat0Layout = new QHBoxLayout();
        Cat0Layout->setSpacing(6);
        Cat0Layout->setObjectName(QString::fromUtf8("Cat0Layout"));
        Cat0Layout->setSizeConstraint(QLayout::SetMinimumSize);
        Cat0Layout->setProperty("horizontalSpacing", QVariant(0));
        Cat0Layout->setProperty("verticalSpacing", QVariant(0));
        Group0 = new QRadioButton(centralWidget);
        Group0->setObjectName(QString::fromUtf8("Group0"));
        sizePolicy.setHeightForWidth(Group0->sizePolicy().hasHeightForWidth());
        Group0->setSizePolicy(sizePolicy);
        Group0->setAutoFillBackground(false);
        Group0->setStyleSheet(QString::fromUtf8("color: rgb(228,26,28);\n"
"background-color: rgb(228,26,28);"));
        Group0->setChecked(true);

        Cat0Layout->addWidget(Group0);

        Visibility0 = new QPushButton(centralWidget);
        Visibility0->setObjectName(QString::fromUtf8("Visibility0"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Visibility0->sizePolicy().hasHeightForWidth());
        Visibility0->setSizePolicy(sizePolicy3);
        Visibility0->setMaximumSize(QSize(36, 25));
        Visibility0->setToolTipDuration(5);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/assets/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon12.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Active, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Selected, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/assets/eye.svg"), QSize(), QIcon::Selected, QIcon::On);
        Visibility0->setIcon(icon12);
        Visibility0->setCheckable(true);
        Visibility0->setChecked(true);

        Cat0Layout->addWidget(Visibility0);


        verticalLayout_2->addLayout(Cat0Layout);

        Cat1Layout = new QHBoxLayout();
        Cat1Layout->setSpacing(6);
        Cat1Layout->setObjectName(QString::fromUtf8("Cat1Layout"));
        Group1 = new QRadioButton(centralWidget);
        Group1->setObjectName(QString::fromUtf8("Group1"));
        sizePolicy.setHeightForWidth(Group1->sizePolicy().hasHeightForWidth());
        Group1->setSizePolicy(sizePolicy);
        Group1->setAutoFillBackground(false);
        Group1->setStyleSheet(QString::fromUtf8("background-color: rgb(55,126,184);\n"
"color: rgb(55,126,184);"));

        Cat1Layout->addWidget(Group1);

        Visibility1 = new QPushButton(centralWidget);
        Visibility1->setObjectName(QString::fromUtf8("Visibility1"));
        sizePolicy3.setHeightForWidth(Visibility1->sizePolicy().hasHeightForWidth());
        Visibility1->setSizePolicy(sizePolicy3);
        Visibility1->setMaximumSize(QSize(36, 25));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon13.addFile(QString::fromUtf8(":/assets/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        Visibility1->setIcon(icon13);
        Visibility1->setCheckable(true);
        Visibility1->setChecked(true);

        Cat1Layout->addWidget(Visibility1);


        verticalLayout_2->addLayout(Cat1Layout);

        Cat2Layout = new QHBoxLayout();
        Cat2Layout->setSpacing(6);
        Cat2Layout->setObjectName(QString::fromUtf8("Cat2Layout"));
        Group2 = new QRadioButton(centralWidget);
        Group2->setObjectName(QString::fromUtf8("Group2"));
        sizePolicy.setHeightForWidth(Group2->sizePolicy().hasHeightForWidth());
        Group2->setSizePolicy(sizePolicy);
        Group2->setAutoFillBackground(false);
        Group2->setStyleSheet(QString::fromUtf8("background-color: rgb(77,175,74);"));

        Cat2Layout->addWidget(Group2);

        Visibility2 = new QPushButton(centralWidget);
        Visibility2->setObjectName(QString::fromUtf8("Visibility2"));
        sizePolicy3.setHeightForWidth(Visibility2->sizePolicy().hasHeightForWidth());
        Visibility2->setSizePolicy(sizePolicy3);
        Visibility2->setMaximumSize(QSize(36, 25));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon14.addFile(QString::fromUtf8(":/assets/eye.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon14.addFile(QString::fromUtf8(":/assets/eye-slash.svg"), QSize(), QIcon::Disabled, QIcon::Off);
        Visibility2->setIcon(icon14);
        Visibility2->setCheckable(true);
        Visibility2->setChecked(true);

        Cat2Layout->addWidget(Visibility2);


        verticalLayout_2->addLayout(Cat2Layout);

        Cat3Layout = new QHBoxLayout();
        Cat3Layout->setSpacing(6);
        Cat3Layout->setObjectName(QString::fromUtf8("Cat3Layout"));
        Group3 = new QRadioButton(centralWidget);
        Group3->setObjectName(QString::fromUtf8("Group3"));
        sizePolicy.setHeightForWidth(Group3->sizePolicy().hasHeightForWidth());
        Group3->setSizePolicy(sizePolicy);
        Group3->setAutoFillBackground(false);
        Group3->setStyleSheet(QString::fromUtf8("background-color: rgb(152,78,163);"));

        Cat3Layout->addWidget(Group3);

        Visibility3 = new QPushButton(centralWidget);
        Visibility3->setObjectName(QString::fromUtf8("Visibility3"));
        sizePolicy3.setHeightForWidth(Visibility3->sizePolicy().hasHeightForWidth());
        Visibility3->setSizePolicy(sizePolicy3);
        Visibility3->setMaximumSize(QSize(36, 25));
        Visibility3->setIcon(icon13);
        Visibility3->setCheckable(true);
        Visibility3->setChecked(true);

        Cat3Layout->addWidget(Visibility3);


        verticalLayout_2->addLayout(Cat3Layout);

        Cat4Layout = new QHBoxLayout();
        Cat4Layout->setSpacing(6);
        Cat4Layout->setObjectName(QString::fromUtf8("Cat4Layout"));
        Group4 = new QRadioButton(centralWidget);
        Group4->setObjectName(QString::fromUtf8("Group4"));
        sizePolicy.setHeightForWidth(Group4->sizePolicy().hasHeightForWidth());
        Group4->setSizePolicy(sizePolicy);
        Group4->setAutoFillBackground(false);
        Group4->setStyleSheet(QString::fromUtf8("background-color: rgb(255,127,0);"));

        Cat4Layout->addWidget(Group4);

        Visibility4 = new QPushButton(centralWidget);
        Visibility4->setObjectName(QString::fromUtf8("Visibility4"));
        sizePolicy3.setHeightForWidth(Visibility4->sizePolicy().hasHeightForWidth());
        Visibility4->setSizePolicy(sizePolicy3);
        Visibility4->setMaximumSize(QSize(36, 25));
        Visibility4->setIcon(icon13);
        Visibility4->setCheckable(true);
        Visibility4->setChecked(true);

        Cat4Layout->addWidget(Visibility4);


        verticalLayout_2->addLayout(Cat4Layout);

        Cat5Layout = new QHBoxLayout();
        Cat5Layout->setSpacing(6);
        Cat5Layout->setObjectName(QString::fromUtf8("Cat5Layout"));
        Group5 = new QRadioButton(centralWidget);
        Group5->setObjectName(QString::fromUtf8("Group5"));
        sizePolicy.setHeightForWidth(Group5->sizePolicy().hasHeightForWidth());
        Group5->setSizePolicy(sizePolicy);
        Group5->setAutoFillBackground(false);
        Group5->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,51);"));

        Cat5Layout->addWidget(Group5);

        Visibility5 = new QPushButton(centralWidget);
        Visibility5->setObjectName(QString::fromUtf8("Visibility5"));
        sizePolicy3.setHeightForWidth(Visibility5->sizePolicy().hasHeightForWidth());
        Visibility5->setSizePolicy(sizePolicy3);
        Visibility5->setMaximumSize(QSize(36, 25));
        Visibility5->setIcon(icon13);
        Visibility5->setCheckable(true);
        Visibility5->setChecked(true);

        Cat5Layout->addWidget(Visibility5);


        verticalLayout_2->addLayout(Cat5Layout);

        Cat6Layout = new QHBoxLayout();
        Cat6Layout->setSpacing(6);
        Cat6Layout->setObjectName(QString::fromUtf8("Cat6Layout"));
        Group6 = new QRadioButton(centralWidget);
        Group6->setObjectName(QString::fromUtf8("Group6"));
        sizePolicy.setHeightForWidth(Group6->sizePolicy().hasHeightForWidth());
        Group6->setSizePolicy(sizePolicy);
        Group6->setAutoFillBackground(false);
        Group6->setStyleSheet(QString::fromUtf8("background-color: rgb(166,86,40);"));

        Cat6Layout->addWidget(Group6);

        Visibility6 = new QPushButton(centralWidget);
        Visibility6->setObjectName(QString::fromUtf8("Visibility6"));
        sizePolicy3.setHeightForWidth(Visibility6->sizePolicy().hasHeightForWidth());
        Visibility6->setSizePolicy(sizePolicy3);
        Visibility6->setMaximumSize(QSize(36, 25));
        Visibility6->setIcon(icon13);
        Visibility6->setCheckable(true);
        Visibility6->setChecked(true);

        Cat6Layout->addWidget(Visibility6);


        verticalLayout_2->addLayout(Cat6Layout);

        Cat7Layout = new QHBoxLayout();
        Cat7Layout->setSpacing(6);
        Cat7Layout->setObjectName(QString::fromUtf8("Cat7Layout"));
        Group7 = new QRadioButton(centralWidget);
        Group7->setObjectName(QString::fromUtf8("Group7"));
        sizePolicy.setHeightForWidth(Group7->sizePolicy().hasHeightForWidth());
        Group7->setSizePolicy(sizePolicy);
        Group7->setLayoutDirection(Qt::LeftToRight);
        Group7->setAutoFillBackground(false);
        Group7->setStyleSheet(QString::fromUtf8("background-color: rgb(247,129,191);"));

        Cat7Layout->addWidget(Group7);

        Visibility7 = new QPushButton(centralWidget);
        Visibility7->setObjectName(QString::fromUtf8("Visibility7"));
        sizePolicy3.setHeightForWidth(Visibility7->sizePolicy().hasHeightForWidth());
        Visibility7->setSizePolicy(sizePolicy3);
        Visibility7->setMaximumSize(QSize(36, 25));
        Visibility7->setIcon(icon13);
        Visibility7->setCheckable(true);
        Visibility7->setChecked(true);

        Cat7Layout->addWidget(Visibility7);


        verticalLayout_2->addLayout(Cat7Layout);


        horLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horLayout_3);


        horizontalLayout_9->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 440, 22));
        GAT = new QMenu(menuBar);
        GAT->setObjectName(QString::fromUtf8("GAT"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(GAT->menuAction());
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
        menuEdit->addAction(actionAdd_GeoData);
        menuEdit->addAction(actionAdd_Calibration);
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addAction(actionDelete_Poliline);
        menuView->addAction(actionMiniMap);
        menuView->addAction(actionNext_Image);
        menuView->addAction(actionPrevious_Image);
        mainToolBar->addAction(actionNewProject);
        mainToolBar->addAction(actionLoad_Project);
        mainToolBar->addAction(actionSave_Project);
        mainToolBar->addAction(actionAdd_Image);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Geological Analysis Tool", nullptr));
        actionNewProject->setText(QApplication::translate("MainWindow", "New Project", nullptr));
        actionLoad_Project->setText(QApplication::translate("MainWindow", "Load Project", nullptr));
        actionSave_Project->setText(QApplication::translate("MainWindow", "Save Project", nullptr));
        actionClose_Project->setText(QApplication::translate("MainWindow", "Close Project", nullptr));
        actionAdd_Image->setText(QApplication::translate("MainWindow", "Add Image", nullptr));
        actionAdd_Point_Cloud->setText(QApplication::translate("MainWindow", "Add Point Cloud", nullptr));
        actionAdd_Matrix->setText(QApplication::translate("MainWindow", "Add Matrix", nullptr));
        actionMiniMap->setText(QApplication::translate("MainWindow", "MiniMap", nullptr));
        actionDelete_Poliline->setText(QApplication::translate("MainWindow", "Delete Poliline", nullptr));
        actionNext_Image->setText(QApplication::translate("MainWindow", "Next Image", nullptr));
        actionPrevious_Image->setText(QApplication::translate("MainWindow", "Previous Image", nullptr));
        actionAdd_Calibration->setText(QApplication::translate("MainWindow", "Add Calibration", nullptr));
        actionAdd_GeoData->setText(QApplication::translate("MainWindow", "Add GeoData", nullptr));
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
        showPolilines->setText(QApplication::translate("MainWindow", "...", nullptr));
        labelPolilines->setText(QApplication::translate("MainWindow", "Polilines List", nullptr));
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
        GAT->setTitle(QApplication::translate("MainWindow", "Geologilcal Analysis Tool", nullptr));
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
