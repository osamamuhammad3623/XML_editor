#include "common.h"
#include "consistency.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GUI_Functions.h"
#include "QMessageBox"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* GLobal variables */
QString linesInOriginalXML = "";


/*
 * A function that checks if file path is valid
 * if the file is valid, open it & display its content
*/
void MainWindow::on_loadFile_clicked()
{
    QString filePath = ui->filePath->text();
    QFile file(filePath);
    if (file.exists()){
        linesInOriginalXML = ViewFileContent(ui, this, file);
    }else{
        QMessageBox::warning(this, "File Path", "No such File!");
    }
}


void MainWindow::on_checkTagsConsistency_clicked()
{
    if (linesInOriginalXML == ""){
        QMessageBox::information(this, "File Error", "Choose a file first!");
    }

    string stdStringLines = linesInOriginalXML.toStdString(); /* convert from string to QString */
    vector<string> xmlVector = xmlStringToVector(stdStringLines);
    bool balanced = checkBalancedTags(xmlVector);
    if (balanced){
        QMessageBox::information(this, "Tags Consistency", "Tags are balanced");
    }else{
        QMessageBox::information(this, "Tags Consistency", "Tags are NOT balanced");
    }
}

