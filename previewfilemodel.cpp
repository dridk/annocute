#include "previewfilemodel.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
PreviewFileModel::PreviewFileModel()
{

}

int PreviewFileModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mDatas.count();
}

int PreviewFileModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if (mDatas.isEmpty())
        return 0;

    return mDatas.first().count();
}

QVariant PreviewFileModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if ( role == Qt::DisplayRole)
    {
        return mDatas.value(index.row()).value(index.column());

    }

    return QVariant();
}

void PreviewFileModel::setSeparator(const QChar &separator)
{
    mSeparator = separator;
}

void PreviewFileModel::setMaxRow(int max)
{
    mMaxRow = max;
}


bool PreviewFileModel::setFilename(const QString &filename)
{
    mFilename = filename;
    QFile file(mFilename);
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        beginResetModel();
        mDatas.clear();
        QTextStream stream(&file);
        QString line;
        int count = 0;
        while (stream.readLineInto(&line) && count < mMaxRow )
        {
            QVariantList row;
            foreach ( QString value , line.split(mSeparator))
            {
                row.append(value);
            }

            mDatas.append(row);
            count++;
        }
        endResetModel();
        return true;
    }
    return false;
}

bool PreviewFileModel::reload()
{
    return setFilename(mFilename);
}
