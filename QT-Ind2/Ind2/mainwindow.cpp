#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mytable *myModel = new mytable();
    ui->tableView->setModel(myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_File_triggered()
{
    QList<Student> ls;
    Student s;
    ls.push_back(s);
    ls.push_back(s);
    ls.push_back(s);
    mytable *myModel = new mytable(ls);
    ui->tableView->setModel(myModel);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QDataStream in(&file);
        mytable *myModel = new mytable(in);
        ui->tableView->setModel(myModel);
        file.close();
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            // error message
        }
        else
        {
            QDataStream stream(&file);
            Student s;
            QModelIndex index;
            for(int i=0; i < ui->tableView->model()->rowCount(); i++)
            {
                index = ui->tableView->model()->index(i,0);
                s.name = ui->tableView->model()->data(index,Qt::DisplayRole).toString();
                index = ui->tableView->model()->index(i,1);
                s.course = ui->tableView->model()->data(index,Qt::DisplayRole).toUInt();
                index = ui->tableView->model()->index(i,2);
                s.group = ui->tableView->model()->data(index,Qt::DisplayRole).toUInt();
                stream << s;
            }
            file.close();
        }
    }
}
void MainWindow::on_pushButtonAdd_clicked()
{
    ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
}

void MainWindow::on_pushButtonDel_clicked()
{
    int count = ui->tableView->selectionModel()->selectedRows().count();
    int row = ui->tableView->selectionModel()->selectedRows().at(0).row();
    for( int i = 0; i < count; i++)
        ui->tableView->model()->removeRow(row);
}
