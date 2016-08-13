#ifndef MAPFILEWIDGET_H
#define MAPFILEWIDGET_H

#include <QtWidgets>
#include "mapfilemodel.h"
class MapFileWidget : public QTableView
{
    Q_OBJECT
public:
    explicit MapFileWidget(QWidget *parent = Q_NULLPTR);
    void setColumnCount(int count);
    const QList<MapItem>& items() const;


private:
    MapFileModel * mModel;
};

#endif // MAPFILEWIDGET_H
