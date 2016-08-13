#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QtWidgets>
#include <QDialog>
#include <QDialogButtonBox>
#include <QTableView>
#include "mapfilemodel.h"
#include "previewfilemodel.h"

class ImportDialog : public QDialog
{
    Q_OBJECT
public:
    ImportDialog(QWidget * parent = Q_NULLPTR);

private:
QDialogButtonBox * mButtonBox;
QTableView * mMapView;
QTableView * mPreviewView;

MapFileModel * mMapModel;
PreviewFileModel * mPreviewModel;


};

#endif // IMPORTDIALOG_H
