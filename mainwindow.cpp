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
QString xmlLines="";
vector<QString> xmlVector;
bool consistencyChecked = false;
bool fileFormatted = false;
bool balanced=false; /* tags in xml */

void MainWindow::on_loadFile_clicked()
{
    ui->formattedText->setText(""); /* clear text area */
    QString filePath = ui->filePath->text();
    QFile file(filePath);
    if (file.exists()){
        /* updating global variables to prepare them for processing */
        xmlLines = ViewFileContent(ui, this, file);
        xmlVector = xmlStringToVector(xmlLines);
    }else{
        QMessageBox::warning(this, "File Path", "No such File!");
    }

    file.close();
}


void MainWindow::on_checkTagsConsistency_clicked()
{
    if (xmlLines == ""){
        QMessageBox::warning(this, "File Error", "Choose a file first!");
        return;
    }

    balanced = (checkBalancedTags(xmlVector) && checkDataPosition(xmlVector));
    consistencyChecked = true;
    if (balanced){
        QMessageBox::information(this, "Tags Consistency", "Tags are balanced");
    }else{
        QMessageBox::information(this, "Tags Consistency", "Tags are NOT balanced");
    }
}


void MainWindow::on_format_clicked()
{
    if (xmlLines == ""){
        QMessageBox::warning(this, "File Error", "Choose a file first!");
        return;
    }else if (!consistencyChecked){
        /* I shouldn't format if tags are not even balanced */
        QMessageBox::warning(this, "Formatting", "You should check if tags are balanced or not first!");
        return;
    }else if (!balanced){
        QMessageBox::warning(this, "Tags Consistency", "Tags are NOT balanced to format!");
        return;
    }

    ui->formattedText->setText(format(xmlVector));
    fileFormatted=true;
}


void MainWindow::on_saveNew_clicked()
{
    if(fileFormatted){
        QString formattedXML = ui->formattedText->toPlainText();
        QFile file("Formatted XML.xml");
        if (file.open(QFile::WriteOnly | QFile::Text)){
            //file.write(formattedXML);
        }else{
            QMessageBox::warning(this, "Save File", "Couldn't save formatted XML into a new file!");
        }

    }else{
        QMessageBox::warning(this, "Save File", "XML is not formatted!");
    }
}

