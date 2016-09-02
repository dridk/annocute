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
    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);



    // ------------ First Group ---------------

    QGroupBox * ioGroup = new QGroupBox("Files to convert");
    QFormLayout * ioFormLayout = new QFormLayout;

    ioFormLayout->addRow("Input", mSourceEdit);
    ioFormLayout->addRow("Output", mOutputEdit);
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

    QSplitter * splitter = new QSplitter(Qt::Horizontal);
    QFrame * optionFrame = new QFrame;
    QVBoxLayout * toolLayout = new QVBoxLayout;
    toolLayout->addWidget(new QComboBox());
    toolLayout->addWidget(new QCheckBox("disable"));
    toolLayout->addWidget(new QLineEdit());
    toolLayout->addWidget(new QPlainTextEdit());
    optionFrame->setLayout(toolLayout);
    optionFrame->setContentsMargins(0,0,0,0);

    splitter->addWidget(optionFrame);
    splitter->addWidget(mPreviewWidget);


    tab2Layout->addWidget(splitter);

    // ------------Box bar -------------------


    QWidget * tab1 = new QWidget;
    QWidget * tab2 = new QWidget;
    tab1->setLayout(tab1Layout);
    tab2->setLayout(tab2Layout);
    mTabWidget->addTab(tab1, "description");
    mTabWidget->addTab(tab2, "column mapping");
    mTabWidget->setCurrentIndex(1);


    mainLayout->addWidget(mTabWidget);
    mainLayout->addWidget(mButtonBox);

    // ------------Connection-------------------

    connect(mPreviewWidget->selectionModel(), SIGNAL(currentColumnChanged(QModelIndex,QModelIndex)),this, SLOT(columnChanged(QModelIndex,QModelIndex)));
    connect(mButtonBox,SIGNAL(rejected()),this,SLOT(close()));
    connect(mButtonBox,SIGNAL(accepted()),this,SLOT(createDatabase()));


    setLayout(mainLayout);
    resize(800,600);

    setFilename("/home/schutz/refGene.txt");


}

void ImportDialog::setFilename(const QString &filename)
{
    mPreviewWidget->setFilename(filename);
    mFilename = filename;

}



void ImportDialog::columnChanged(const QModelIndex &current, const QModelIndex &previous)
{




}

bool ImportDialog::createDatabase()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QFile::remove("/home/sacha/test.DB");
    db.setDatabaseName("/home/sacha/test.DB");
    if (db.open())
    {

        createTables();
        importDatas();

        db.close();

    }


    return false;

}

bool ImportDialog::createTables()
{

//        qDebug()<<"create table";



//        QMetaEnum metaEnum = MapFileModel::staticMetaObject.enumerator(MapFileModel::staticMetaObject.indexOfEnumerator("MapItemType"));

//// Prepare query field
//        QStringList queryField;
////        queryField.append("ID INT PRIMARY KEY NOT NULL");

//        foreach (MapItem item, mMapWidget->items())
//        {
//            QString type = metaEnum.key(item.type);
//            if (type == "CHROMOSOM")
//                type = "Text";
//            if (type == "Start" || type == "End")
//                type = "Integer";

//           queryField.append(QString("%1 %2").arg(item.name).arg(type));

//        }

//        // Prepare query create


//        QString query = QString("CREATE TABLE %1 ( %2 );").arg("test").arg(queryField.join(","));

//        qDebug()<<query;

//        QSqlQuery sqlQuery;
//        sqlQuery.exec(query);

//        if (sqlQuery.exec() == false)
//            qDebug()<<sqlQuery.lastError().text();



}

bool ImportDialog::importDatas()
{

//    QFile file(mFilename);
//    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
//    {
//        QTextStream stream(&file);
//        QString line;
//        int count = 0;
//        QSqlQuery c;
//        c.exec("BEGIN");
//        while (stream.readLineInto(&line) )
//        {
//            QVariantList rows;
//            QStringList placeholders;
//            foreach ( QString value , line.split(QChar::Tabulation))
//            {
//                rows.append(value);
//                placeholders.append("?");
//            }

//         ;
//            count++;

//            // inject
//            QString q = QString("INSERT INTO test VALUES (%1)").arg(placeholders.join(","));
//            QSqlQuery query;
//            query.prepare(q);

//            for (int i=0; i < rows.count(); ++i)
//            {
//             query.bindValue(i, rows.at(i));

//            }

//            if (!query.exec())
//            {
//                qDebug()<<query.lastQuery();
//                qDebug()<<query.lastError().text();
//            }



//        }
//         c.exec("END");
//        qDebug()<<"END";

//        return true;
//    }
//    return false;









}
