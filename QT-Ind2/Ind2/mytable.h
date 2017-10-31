#ifndef MYTABLE_H
#define MYTABLE_H

#include <QAbstractTableModel>
#include <QTextStream>

struct Student
{
    QString  name;
    uint     course;
    uint     group;

    Student()
    {
        name=" ";
        course=0;
        group=0;
    }

    Student(QString n, uint c, uint g)
    {
        name=n;
        course=c;
        group=g;
    }
};

QDataStream& operator <<(QDataStream &os, const Student &out);
QDataStream& operator >>(QDataStream &is, Student &in);

class mytable : public QAbstractTableModel
{
    Q_OBJECT

public:
    mytable(QObject *parent=0);
    mytable(QList<Student> students, QObject *parent=0);
    mytable(QDataStream& in, QObject *parent=0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
    QList<Student> getList();

private:
    QList<Student> listOfStudents;
};

#endif // MYTABLE_H
