#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QDir>
#include <QtGui>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QApplication>
#include <QProcess>
#include "gagraphicsview.h"
#include "projectmanager.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // Variable de proyecto de tipo JSON
    json project;
    // Variable de subproyecto de tipo JSON
    json subproject;
    // Objeto ProjectManager
    ProjectManager _pm;
    // Variable de nombre de archivo de tipo String
    QString filename = "";
    // Metodo para deseleccionar polilinias
    void unSelectPoliline();
    // Metodo para abrir un proyecto
    void openProject();
    // Metodo para abrir una imagen
    void openImage(QString image_name);
    // Metodo para guardar un archivo
    void saveFile();
    // Metodo para crear un Subproyecto
    void createSubproject(QString image);
    // Metodo para guardar un Subproyecto
    void saveSubproject();
private slots:
    void on_actionLoad_Project_triggered();

    void on_actionAdd_Image_triggered();

    void on_Btn_Edit_clicked(bool checked);

    void on_Btn_Zoom_In_clicked();

    void on_Btn_Zoom_Out_clicked();

    void on_Btn_Del_Point_clicked();

    void on_Btn_Add_Point_clicked();

    void on_actionMiniMap_triggered(bool tiggered);

    void on_Group0_clicked(bool checked);

    void on_Group1_clicked(bool checked);

    void on_Group2_clicked(bool checked);

    void on_Group3_clicked(bool checked);

    void on_Group4_clicked(bool checked);

    void on_Group5_clicked(bool checked);

    void on_Group6_clicked(bool checked);

    void on_Group7_clicked(bool checked);

    void on_Visibility0_clicked(bool checked);

    void on_Visibility1_clicked(bool checked);

    void on_Visibility2_clicked(bool checked);

    void on_Visibility3_clicked(bool checked);

    void on_Visibility4_clicked(bool checked);

    void on_Visibility5_clicked(bool checked);

    void on_Visibility6_clicked(bool checked);

    void on_Visibility7_clicked(bool checked);

    void on_Btn_Undo_pressed();

    void on_Btn_Do_clicked();

    void on_Btn_Move_clicked();

    void on_showPolilines_clicked(bool checked);

    void on_actionDelete_Poliline_triggered();

    void on_polilines_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_actionSave_Project_triggered();

    void on_actionNewProject_triggered();

    void on_actionNext_Image_triggered();

    void on_actionPrevious_Image_triggered();

    void on_actionAdd_Matrix_triggered();

    void on_actionAdd_Calibration_triggered();


    void on_actionAdd_Point_Cloud_triggered();

    void on_actionClose_Project_triggered();

private:
    Ui::MainWindow *ui;
    int currentSubproject=0;
    void ZoomOut(double h, double w);
    void ZoomIn(double h, double w);
    CustomGraphicsView* edit;
    QGraphicsView* minimap;
    QPixmap pix;
    QPixmap minipix;
    QGraphicsScene *scene;
    QGraphicsScene *miniscene;
    QGraphicsScene *editscene;
    QGraphicsScene* stereoScene;
    QImage _img;
    bool deledit;
    bool delmini;
    bool image;
    QGraphicsProxyWidget *proxyedit;
    QGraphicsProxyWidget *proxymini;
    pcl::PointCloud<pcl::PointXYZ>::Ptr PointCloud;

};
class Dialog : public QWidget
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    void criticalMessage();
    void informationMessage();
    bool questionMessage(const char* _message);
    bool warningMessage();
    void errorMessage();

private:
    QLabel *integerLabel;
    QLabel *doubleLabel;
    QLabel *itemLabel;
    QLabel *textLabel;
    QLabel *multiLineTextLabel;
    QLabel *colorLabel;
    QLabel *fontLabel;
    QLabel *directoryLabel;
    QLabel *openFileNameLabel;
    QLabel *openFileNamesLabel;
    QLabel *saveFileNameLabel;
    QLabel *criticalLabel;
    QLabel *informationLabel;
    QLabel *questionLabel;
    QLabel *warningLabel;
    QLabel *errorLabel;
    QString openFilesPath;

};

#endif // MAINWINDOW_H
