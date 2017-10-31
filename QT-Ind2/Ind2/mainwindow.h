#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include <mytable.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionNew_File_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDel_clicked();

private:
    Ui::MainWindow *ui;    
};

#endif // MAINWINDOW_H
