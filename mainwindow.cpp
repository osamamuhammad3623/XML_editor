#include "common.h"
#include "consistency.h"
#include "format.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GUI_Functions.h"
#include "QMessageBox"
#include "QTextStream"
#include "QFileDialog"
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
bool balanced=false; /* tags in xml */

void MainWindow::on_loadFile_clicked()
{
    ui->formattedText->setText(""); /* clear text area */
    QString filePath = QFileDialog::getOpenFileName(this, "Choose XML file");
    QFile file(filePath);

    ui->filePath->setText("\"" + filePath + "\"");
    /* updating global variables to prepare them for processing */
    xmlLines = ViewFileContent(ui, this, file);
    xmlVector = xmlStringToVector(xmlLines);

    file.close();
}


void MainWindow::on_checkTagsConsistency_clicked()
{
    if (xmlLines == ""){
        QMessageBox::warning(this, "File Error", "Choose a file first!");
        return;
    }

    balanced = checkBalancedTags(xmlVector);
    if (balanced){
        consistencyChecked = true;
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
}


void MainWindow::on_saveNew_clicked()
{
        QString text = ui->formattedText->toPlainText();
        if (!text.isEmpty()){

            QFile file("newXML.xml");
            if (file.open(QFile::WriteOnly | QFile::Text)){
                QTextStream stream(&file);
                stream << text << endl;
                file.close();
                QMessageBox::information(this, "Save file", " newXML.xml is saved!");
            }else{
                QMessageBox::warning(this, "Save File", "Couldn't save XML into a new file!");
            }

        }else{
            QMessageBox::warning(this, "Save File", "XML is not formatted!");
        }
}


void MainWindow::on_minify_clicked()
{
    QString minified = "";
    QChar c;

    for (int i =0; i< xmlLines.size(); i++){
        c = xmlLines[i];

        /* remove all newline and tabs chars */
        if (c == '\n' || c == '\t'){
            continue;
        }

        /* remove all spaces between a closing tag and the next opening tag */
        else if (c == '>'){
            minified += '>';
            i++;

            while (xmlLines[i] == ' ' || xmlLines[i] == '\n' || xmlLines[i] == '\t'){
                i++;
            }
            continue;
        }

        minified += c;
    }

    ui->formattedText->setText(minified);
}

