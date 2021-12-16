﻿#include "common.h"
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
QString xmlLines="";
vector<QString> xmlVector;
bool tagsChecked = false;
bool balanced=false; /* tags in xml */

void MainWindow::on_loadFile_clicked()
{
    QString filePath = ui->filePath->text();
    QFile file(filePath);
    if (file.exists()){
        /* updating global variables to prepare them for processing */
        xmlLines = ViewFileContent(ui, this, file);
        xmlVector = xmlStringToVector(xmlLines);
    }else{
        QMessageBox::warning(this, "File Path", "No such File!");
    }
}


void MainWindow::on_checkTagsConsistency_clicked()
{
    if (xmlLines == ""){
        QMessageBox::warning(this, "File Error", "Choose a file first!");
        return;
    }

    balanced = checkBalancedTags(xmlVector);
    tagsChecked = true;
    if (balanced){
        QMessageBox::information(this, "Tags Consistency", "Tags are balanced");
    }else{
        QMessageBox::information(this, "Tags Consistency", "Tags are NOT balanced");
    }
}


#error "Format function gives shifted levels"
void MainWindow::on_format_clicked()
{
    if (xmlLines == ""){
        QMessageBox::warning(this, "File Error", "Choose a file first!");
        return;
    }else if (!tagsChecked){
        /* I shouldn't format if tags are not even balanced */
        QMessageBox::warning(this, "Formatting", "You should check if tags are balanced or not first!");
        return;
    }else if (!balanced){
        QMessageBox::warning(this, "Tags Consistency", "Tags are NOT balanced to format!");
        return;
    }

    ui->formattedText->setText(format(xmlVector));
}

