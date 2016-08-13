#ifndef MAPFILEMODEL_H
#define MAPFILEMODEL_H
#include <QAbstractListModel>
#include "mapitem.h"

class MapFileModel;
class MapItem;


class MapFileModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MapItemType {
        Chromosom,
        Start,
        End,
        Integer,
        Real,
        Text
    };

Q_ENUM(MapItemType)

    MapFileModel(QObject* parent = Q_NULLPTR);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void setColumnCount(int count);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<MapItem> mDatas;
    QString mFilename;
    QStringList mHeaders;

};

class MapItem {
public:
    bool use;
    int column;
    QString name;
    QString comment;
    MapFileModel::MapItemType type;
};


#endif // MAPFILEMODEL_H
