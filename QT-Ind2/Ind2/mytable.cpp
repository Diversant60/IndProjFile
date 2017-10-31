#include "mytable.h"

QDataStream& operator <<(QDataStream &os, const Student &out)
{
    os << out.name;
    os << out.course;
    os << out.group;
    return os;
}

QDataStream& operator >>(QDataStream &is, Student &in)
{
    is >> in.name;
    is >> in.course;
    is >> in.group;
    return is;
}

mytable::mytable(QObject *parent)
    : QAbstractTableModel(parent)
{
}

mytable::mytable(QList<Student> students, QObject *parent)
    : QAbstractTableModel(parent)
{
    listOfStudents=students;
}

mytable::mytable(QDataStream& in, QObject *parent)
    : QAbstractTableModel(parent)
{
    listOfStudents.clear();
    while(!in.atEnd())
    {
        QString n;
        uint c;
        uint g;
        in >> n >> c >> g;
        Student s(n,c,g);
        listOfStudents.push_back(s);
    }
}

int mytable::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfStudents.size();
}

int mytable::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant mytable::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= listOfStudents.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        Student student = listOfStudents.at(index.row());

        if (index.column() == 0)
            return student.name;
        else if (index.column() == 1)
            return student.course;
        else if (index.column() == 2)
            return student.group;
    }
    return QVariant();
}

QVariant mytable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Name");

        case 1:
            return tr("Course");

        case 2:
            return tr("Group");

        default:
            return QVariant();
        }
    }
    return QVariant();
}

bool mytable::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; row++)
    {
        Student student;
        listOfStudents.insert(position, student);
    }

    endInsertRows();
    return true;
}

bool mytable::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; ++row) {
        listOfStudents.removeAt(position);
    }

    endRemoveRows();
    return true;
}

bool mytable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();

        Student p = listOfStudents.value(row);

        if (index.column() == 0)
            p.name = value.toString();
        else if (index.column() == 1)
            p.course = value.toUInt();
        else if (index.column() == 2)
            p.group = value.toUInt();
        else
            return false;

        listOfStudents.replace(row, p);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Qt::ItemFlags mytable::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList<Student> mytable::getList()
{
    return listOfStudents;
}
