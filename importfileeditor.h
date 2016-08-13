#ifndef IMPORTFILEEDITOR_H
#define IMPORTFILEEDITOR_H
#include <QWidget>
#include <QTableView>
#include <QtWidgets>
#include "previewfilemodel.h"
class ImportFileEditor : public QWidget
{
    Q_OBJECT
public:
    explicit ImportFileEditor(QWidget *parent = 0);

protected:


private:
    QTableView * mView;
    PreviewFileModel * mModel;
};

#endif // IMPORTFILEEDITOR_H
