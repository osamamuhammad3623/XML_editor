#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GUI_Functions.h"
#include "QMessageBox"

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


/*
 * A function that checks if file path is valid
 * if the file is valid, open it & display its content
*/
void MainWindow::on_loadFile_clicked()
{
    QString filePath = ui->filePath->text();
    QFile file(filePath);
    if (file.exists()){
        ViewFileContent(ui, this, file);
    }else{
        QMessageBox::warning(this, "File Path", "No such File!");
    }
}
