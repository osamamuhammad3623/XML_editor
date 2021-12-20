#ifndef GUI_FUNCTIONS_H
#define GUI_FUNCTIONS_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QString"

/*
 * A function that displays text from file to QTextEdit
*/
void ViewFileContent(Ui::MainWindow *ui , QWidget *thisWidget, QFile &file);


/*
 * Enable GUI buttons that were disabled at start-up
*/
void GUI_enableButtons(Ui::MainWindow *ui);


/*
 * Read original text from ui->originalText and return it.
*/
QString readOriginalText(Ui::MainWindow *ui, QWidget *thisWidget);

#endif // GUI_FUNCTIONS_H
