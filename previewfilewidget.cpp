#include "previewfilewidget.h"



PreviewFileWidget::PreviewFileWidget(QWidget *parent)
    :QTableView(parent)
{


    mModel = new PreviewFileModel;
    setModel(mModel);

    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectColumns);
    verticalHeader()->hide();



}

void PreviewFileWidget::setFilename(const QString &filename)
{
    mModel->setFilename(filename);

}

