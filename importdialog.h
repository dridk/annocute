#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QtWidgets>
#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QDialogButtonBox>
#include <QTableView>
#include "previewfilewidget.h"
#include "mapfilewidget.h"
#include "pathlineedit.h"

class ImportDialog : public QDialog
{
    Q_OBJECT
public:
    ImportDialog(QWidget * parent = Q_NULLPTR);

    void setFilename(const QString& source);







protected Q_SLOTS:
    void columnChanged(const QModelIndex &current, const QModelIndex &previous);
    bool createDatabase();

    bool createTables();
    bool importDatas();

private:
QDialogButtonBox * mButtonBox;

PreviewFileWidget * mPreviewWidget;

PathLineEdit * mSourceEdit;
PathLineEdit * mOutputEdit;


QLineEdit * mDbNameEdit;
QPlainTextEdit * mDescriptionEdit;
QComboBox * mReferenceCombo;
QComboBox * mDelimiterCombo;
QTabWidget * mTabWidget;

QString mFilename;




};

#endif // IMPORTDIALOG_H
