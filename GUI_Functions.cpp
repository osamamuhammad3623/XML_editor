#include "mainwindow.h"
#include "GUI_Functions.h"
#include "ui_mainwindow.h"
#include "QTextStream"
#include "QMessageBox"
using namespace std;


void ViewFileContent(Ui::MainWindow *ui , QWidget *thisWidget, QFile &file){
    QString lines="";
    if (file.open(QFile::ReadOnly | QFile::Text)){

        QTextStream data(&file);
        lines = data.readAll();
        ui->originalText->setText(lines);

        GUI_enableButtons(ui);
    }else{
        QMessageBox::warning(thisWidget, "File Error", "Cannot open the file!");
    }

}

void GUI_enableButtons(Ui::MainWindow *ui){
    ui->checkTagsConsistency->setEnabled(true);
    ui->format->setEnabled(true);
    ui->saveNew->setEnabled(true);
    ui->minify->setEnabled(true);
    ui->visualize->setEnabled(true);
}

QString readOriginalText(Ui::MainWindow *ui , QWidget *thisWidget){
    QString text = ui->originalText->toPlainText();
    if (text.isEmpty()){
        QMessageBox::warning(thisWidget, "XML data", "Textbox is empty!");
        return "\0";
    }
    return text;
}
