#include "common.h"
#include "consistency.h"
#include "format.h"
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
string stdStringLines="";
vector<string> xmlVector;


void setStdStringAndVector(QString &originalXML){
    stdStringLines = originalXML.toStdString(); /* convert from string to QString */
    xmlVector = xmlStringToVector(stdStringLines);
}


/*
 * A function that checks if file path is valid
 * if the file is valid, open it & display its content
*/
void MainWindow::on_loadFile_clicked()
{
    QString filePath = ui->filePath->text();
    QFile file(filePath);
    if (file.exists()){
        QString linesInOriginalXML = ViewFileContent(ui, this, file);
        setStdStringAndVector(linesInOriginalXML);
    }else{
        QMessageBox::warning(this, "File Path", "No such File!");
    }
}


/*
 * Check balanced tags process
*/
void MainWindow::on_checkTagsConsistency_clicked()
{
    if (stdStringLines == ""){
        QMessageBox::information(this, "File Error", "Choose a file first!");
    }

    bool balanced = checkBalancedTags(xmlVector);
    if (balanced){
        QMessageBox::information(this, "Tags Consistency", "Tags are balanced");
    }else{
        QMessageBox::information(this, "Tags Consistency", "Tags are NOT balanced");
    }
}


/*
 * Formatting XML process
*/
#error "Format function gives shifted levels"
void MainWindow::on_format_clicked()
{
    if (stdStringLines == ""){
        QMessageBox::information(this, "File Error", "Choose a file first!");
    }

    ui->formattedText->setText(format(xmlVector));
}

