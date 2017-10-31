#include <QApplication>
#include <QFile> // Подключаем класс QFile
#include <QTextStream> // Подключаем класс QTextStream
#include <QDebug>
#include <limits>
#include <numeric>
#include <iostream>

#include "mytable.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile fileOut("table.txt");
    if(fileOut.open(QIODevice::WriteOnly))
    {
        QDataStream tableFile(&fileOut);
        Student s1("Joka",4,1);
        Student s2("Boka",2,2);
        Student s3("Pika",1,3);
        tableFile << s1 << s2 << s3;
        fileOut.close();
    }

    MainWindow w;
    w.show();

    return a.exec();
}
