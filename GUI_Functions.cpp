#include "GUI_Functions.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QString"


QString ViewFileContent(Ui::MainWindow *ui , QWidget *thisWidget, QFile &file){
    QString lines="";
    if (file.open(QFile::ReadOnly | QFile::Text)){

        QTextStream data(&file);
        lines = data.readAll();
        ui->originalText->setText(lines);
    }else{
        QMessageBox::warning(thisWidget, "File Error", "Cannot open the file!");
    }

    return lines;
}
