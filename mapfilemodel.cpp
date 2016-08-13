#include "mapfilemodel.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
MapFileModel::MapFileModel(QObject* parent )
    :QAbstractListModel(parent)
{

    mHeaders << "Keep" <<"Type" << "Name" << "Comment";

}

int MapFileModel::rowCount(const QModelIndex &parent) const
{
    return mDatas.count();
}

int MapFileModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant MapFileModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {

       QMetaEnum metaEnum = metaObject()->enumerator(metaObject()->indexOfEnumerator("MapItemType"));

        if (index.column() == 0)
            return mDatas.at(index.row()).use;

        if (index.column() == 1)
            return metaEnum.valueToKey(mDatas.at(index.row()).type);

        if (index.column() == 2)
            return mDatas.at(index.row()).name;

        if (index.column() == 3)
            return mDatas.at(index.row()).comment;
    }

    if ( role == Qt::CheckStateRole)
    {
        if (index.column() == 0)
            return mDatas.at(index.row()).use;
    }

    return QVariant();
}

bool MapFileModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;



    if (role == Qt::EditRole)
    {
        QMetaEnum metaEnum = metaObject()->enumerator(metaObject()->indexOfEnumerator("MapItemType"));


        if (index.column() == 0)
            mDatas[index.row()].use = value.toBool();

        if (index.column() == 1)
            mDatas[index.row()].type = (MapItemType)(value.toInt());

        if (index.column() == 2)
            mDatas[index.row()].name = value.toString();

        if (index.column() == 3)
            mDatas[index.row()].comment = value.toString();

        return true;
    }


    if ( role == Qt::CheckStateRole)
    {

        if (index.column() == 0)
        {
            mDatas[index.row()].use = !mDatas[index.row()].use;
            return true;
        }
    }

    return false;
}

void MapFileModel::setColumnCount(int count)
{
    beginResetModel();
    mDatas.clear();
    for (int i=0; i<count; ++i)
    {

        MapItem item;
        item.use = true;
        item.column = i;
        item.name = QString("col_%1").arg(i);
        item.type = MapItemType::Text;
        item.comment = "";

        mDatas.append(item);

    }
    endResetModel();
}

QVariant MapFileModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if ( role == Qt::DisplayRole)
        {
            return mHeaders.value(section, QString::number(section));
        }
    }

    if (orientation == Qt::Vertical)
    {
        if (role == Qt::DisplayRole)
        return QString("col %1").arg(section);
    }

    return QVariant();
}

Qt::ItemFlags MapFileModel::flags(const QModelIndex &index) const
{

    if (index.column() == 0)
        return Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled;

    else
    return Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled;



}
