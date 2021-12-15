#include "GUI_Functions.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"


void ViewFileContent(Ui::MainWindow *ui , QWidget *thisWidget, QFile &file){
    if (file.open(QFile::ReadOnly | QFile::Text)){

        QTextStream data(&file);
        QString lines = data.readAll();
        ui->originalText->setText(lines);
    }else{
        QMessageBox::warning(thisWidget, "File Error", "Cannot open the file!");
    }
}
