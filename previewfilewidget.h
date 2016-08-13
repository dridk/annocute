#ifndef PREVIEWFILEWIDGET_H
#define PREVIEWFILEWIDGET_H

#include <QtWidgets>
#include "previewfilemodel.h"


class PreviewFileWidget : public QTableView
{
    Q_OBJECT
public:
    explicit PreviewFileWidget(QWidget * parent = Q_NULLPTR);
    void setFilename(const QString& filename);


private:
   PreviewFileModel * mModel;



};

#endif // PREVIEWFILEWIDGET_H
