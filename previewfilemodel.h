#ifndef DATAFILEMODEL_H
#define DATAFILEMODEL_H

#include <QAbstractListModel>
#include <QChar>
class PreviewFileModel : public QAbstractListModel
{
public:
    explicit PreviewFileModel();
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;

    void setSeparator(const QChar& separator);
    void setMaxRow(int max);


public Q_SLOTS:
    bool setFilename(const QString& filename);
    bool reload();


private:
    QList< QVariantList> mDatas;
    QString mFilename;
    QChar mSeparator = QChar::Tabulation;
    int mMaxRow = 10;


};

#endif // DATAFILEMODEL_H
