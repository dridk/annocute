#include "importdialog.h"

ImportDialog::ImportDialog(QWidget *parent)
    :QDialog(parent)
{

    QVBoxLayout * mainLayout = new QVBoxLayout;

    mTabWidget = new QTabWidget;
    QVBoxLayout * tab1Layout = new QVBoxLayout;
    QVBoxLayout * tab2Layout = new QVBoxLayout;

    mSourceEdit = new PathLineEdit;
    mOutputEdit = new PathLineEdit;
    mDbNameEdit = new QLineEdit;
    mDescriptionEdit = new QPlainTextEdit;
    mReferenceCombo = new QComboBox;
    mDelimiterCombo = new QComboBox;

    mPreviewWidget = new PreviewFileWidget;
    mMapWidget= new MapFileWidget;
    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);



    // ------------ First Group ---------------

    QGroupBox * ioGroup = new QGroupBox("Files to convert");
    QFormLayout * ioFormLayout = new QFormLayout;

    ioFormLayout->addRow("Input", mSourceEdit);
    ioFormLayout->addRow("Output", mOutputEdit);
    ioFormLayout->addRow("Delimiter", mDelimiterCombo);

    ioGroup->setLayout(ioFormLayout);


    tab1Layout->addWidget(ioGroup);

    // ------------ second Group ---------------

    QGroupBox * desGroup = new QGroupBox("Description");
    QFormLayout * desFormLayout = new QFormLayout;

    desFormLayout->addRow("Name", mDbNameEdit);
    desFormLayout->addRow("Reference", mReferenceCombo);
    desFormLayout->addRow("", mDescriptionEdit);

    desGroup->setLayout(desFormLayout);
    tab1Layout->addWidget(desGroup);

    // ------------ Last Group --------------

    QGroupBox * toolFrame = new QGroupBox("Option");
    QFormLayout * toolLayout = new QFormLayout;
    toolLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    toolLayout->setFormAlignment(Qt::AlignLeft);
    toolLayout->addRow("Delimiter",new QComboBox());
    toolLayout->addRow("Skip first line",new QCheckBox);

    toolFrame->setLayout(toolLayout);


    QSplitter * splitter = new QSplitter(Qt::Vertical);

    splitter->addWidget(mMapWidget);
    splitter->addWidget(mPreviewWidget);
    splitter->setHandleWidth(20);

    tab2Layout->addWidget(toolFrame);
    tab2Layout->addWidget(splitter);

    // ------------Box bar -------------------


    QWidget * tab1 = new QWidget;
    QWidget * tab2 = new QWidget;
    tab1->setLayout(tab1Layout);
    tab2->setLayout(tab2Layout);
    mTabWidget->addTab(tab1, "description");
    mTabWidget->addTab(tab2, "column mapping");


    mainLayout->addWidget(mTabWidget);
    mainLayout->addWidget(mButtonBox);

    // ------------Connection-------------------

    connect(mPreviewWidget->selectionModel(), SIGNAL(currentColumnChanged(QModelIndex,QModelIndex)),this, SLOT(columnChanged(QModelIndex,QModelIndex)));
    connect(mMapWidget->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this, SLOT(columnChanged(QModelIndex,QModelIndex)));
    connect(mButtonBox,SIGNAL(rejected()),this,SLOT(close()));
    connect(mButtonBox,SIGNAL(accepted()),this,SLOT(createDatabase()));


    setLayout(mainLayout);
    resize(800,600);

    setFilename("/home/sacha/testdb/refGene.txt");


}

void ImportDialog::setFilename(const QString &filename)
{
    mPreviewWidget->setFilename(filename);
    mMapWidget->setColumnCount(mPreviewWidget->model()->columnCount());
    mFilename = filename;

}

const QString &ImportDialog::output() const
{
    return mOutputEdit->lineEdit()->text();
}

const QString &ImportDialog::dbName() const
{
    return mDbNameEdit->text();
}

const QString& ImportDialog::source() const
{
    return mSourceEdit->lineEdit()->text();
}

void ImportDialog::columnChanged(const QModelIndex &current, const QModelIndex &previous)
{

    if ( sender() == mMapWidget->selectionModel())
    {

        mPreviewWidget->selectColumn(current.row());

    }


    if ( sender() == mPreviewWidget->selectionModel())
    {
        mMapWidget->selectRow(current.column());


    }



}

bool ImportDialog::createDatabase()
{

    createTables();

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("/home/sacha/test.DB");








//    if (db.open())
//    {

//        QFile file(mFilename);
//        if (file.open(QIODevice::ReadOnly|QIODevice::Text))
//        {
//            QTextStream stream(&file);
//            QString line;
//            int count = 0;
//            while (stream.readLineInto(&line))
//            {
//                QVariantList row;
//                foreach ( QString value , line.split(mSeparator))
//                {
//                    row.append(value);
//                }

//                mDatas.append(row);
//                count++;
//            }

//        }

//    }


    return false;

}

bool ImportDialog::createTables()
{





}

bool ImportDialog::importDatas()
{

}
