#ifndef GUI_FUNCTIONS_H
#define GUI_FUNCTIONS_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QString"

/*
 * A function that displays text from file to QTextEdit
 * and return QString contains that text.
*/
QString ViewFileContent(Ui::MainWindow *ui , QWidget *thisWidget, QFile &file);


#endif // GUI_FUNCTIONS_H
