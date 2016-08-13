#include "mapfilewidget.h"
#include <QDebug>
MapFileWidget::MapFileWidget(QWidget *parent) :
    QTableView(parent)
{


    mModel = new MapFileModel;
    setModel(mModel);

    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);

    horizontalHeader()->setStretchLastSection(true);

    mModel->setColumnCount(5);

}

void MapFileWidget::setColumnCount(int count)
{
    mModel->setColumnCount(count);
}

const QList<MapItem> &MapFileWidget::items() const
{
 return mModel->items();
}

