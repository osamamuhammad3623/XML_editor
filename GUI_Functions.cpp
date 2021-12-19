#include "mainwindow.h"
#include "GUI_Functions.h"
#include "ui_mainwindow.h"
#include "QTextStream"
#include "QMessageBox"
using namespace std;


QString ViewFileContent(Ui::MainWindow *ui , QWidget *thisWidget, QFile &file){
    QString lines="";
    if (file.open(QFile::ReadOnly | QFile::Text)){

        QTextStream data(&file);
        lines = data.readAll();
        ui->originalText->setText(lines);

        /* enable features for xml */
        ui->checkTagsConsistency->setEnabled(true);
        ui->analysis->setEnabled(true);
        ui->format->setEnabled(true);
        ui->saveNew->setEnabled(true);
        ui->minify->setEnabled(true);
    }else{
        QMessageBox::warning(thisWidget, "File Error", "Cannot open the file!");
    }

    return lines;
}
