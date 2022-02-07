#include "common.h"
#include "consistency.h"
#include "format.h"
#include "minify.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GUI_Functions.h"
#include "networkVisual.h"
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
bool consistencyChecked = false;
bool balanced=false; /* tags in xml */


void MainWindow::on_loadFile_clicked()
{
    ui->resultText->setText(""); /* clear text area */
    QString filePath = QFileDialog::getOpenFileName(this, "Choose XML file");
    QFile file(filePath);

    ui->filePath->setText("\"" + filePath + "\"");
    /* updating global variables to prepare them for processing */
    ViewFileContent(ui, this, file);

    file.close();
}


void MainWindow::on_checkTagsConsistency_clicked()
{
    QString text = readOriginalText(ui, this);
    if (text == "\0"){
        return;
    }

    vector<QString> vec = xmlStringToVector(text);

    vector<QString> wrongWrittenTags;
    bool correctTags = checkTags(wrongWrittenTags, vec);

    if (!correctTags){
        QString msg = "The following tag/s is/are incorrectly written,\ncorrect them first\n";
        for (QString s : wrongWrittenTags){
            msg += s + "\n";
        }
        ui->resultText->setText(msg);
        return;
    }

    balanced = checkBalancedTags(vec);
    if (balanced){
        ui->resultText->setText(""); /* clear results widget */

        consistencyChecked = true;
        QMessageBox::information(this, "Tags Consistency", "Tags are balanced");
    }else{
        QMessageBox::information(this, "Tags Consistency", "Tags are NOT balanced");
    }
}


void MainWindow::on_format_clicked()
{
    QString text = readOriginalText(ui,this);
    if (text == "\0"){
        return;
    }else if (!consistencyChecked){
        /* I shouldn't format if tags are not even balanced */
        QMessageBox::warning(this, "Formatting", "You should check if tags are balanced or not first!");
        return;
    }else if (!balanced){
        QMessageBox::warning(this, "Tags Consistency", "Tags are NOT balanced to format!");
        return;
    }

    vector<QString> vec = xmlStringToVector(text);
    ui->resultText->setText(format(vec));
}


void MainWindow::on_saveNew_clicked()
{
        QString text = ui->resultText->toPlainText();
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
    QString text = readOriginalText(ui,this);
    if (text == "\0"){
        return;
    }else if (!consistencyChecked){
        /* I shouldn't minify if tags are not even balanced */
        QMessageBox::warning(this, "Minifying", "You should check if tags are balanced or not first!");
        return;
    }else if (!balanced){
        QMessageBox::warning(this, "Tags Consistency", "Tags are NOT balanced to format!");
        return;
    }

    QString minified = minify(text);

    ui->resultText->setText(minified);
}


void MainWindow::on_originalText_textChanged()
{
    /* reset global variables */
    consistencyChecked = false;
    balanced=false;
}

void MainWindow::on_visualize_clicked()
{
    QString text = readOriginalText(ui, this);
    if (text == "\0"){
        return;
    }

    vector<QString> vec = xmlStringToVector(text);

    vector<vector<QString>> adList = extractNetwork(vec);
    storeAdjacencyList(adList);
    visualize();
}

