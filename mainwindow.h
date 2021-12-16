#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /*
     * Desc: A function that checks if file path is valid
     * if the file is valid, open it & display its content
    */
    void on_loadFile_clicked();


    /*
     * Check balanced tags process
    */
    void on_checkTagsConsistency_clicked();


    /*
     * Formatting XML process
    */
    void on_format_clicked();


    /*
     * Save formatted XML into a new file process
    */
    void on_saveNew_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
