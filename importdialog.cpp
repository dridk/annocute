#include "importdialog.h"

ImportDialog::ImportDialog(QWidget *parent)
    :QDialog(parent)
{

    QVBoxLayout * mainLayout = new QVBoxLayout;

    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    mMapView = new QTableView;
    mPreviewView = new QTableView;
     mMapModel = new MapFileModel;
     mPreviewModel = new PreviewFileModel;

     mMapView->setModel(mMapModel);
     mPreviewView->setModel(mPreviewModel);

     mMapView->setSelectionBehavior(QAbstractItemView::SelectRows);
     mPreviewView->setSelectionBehavior(QAbstractItemView::SelectColumns);

     mMapView->setSelectionMode(QAbstractItemView::SingleSelection);
     mPreviewView->setSelectionMode(QAbstractItemView::SingleSelection);

     mMapView->horizontalHeader()->setStretchLastSection(true);
     mPreviewView->horizontalHeader()->setStretchLastSection(true);

    mPreviewModel->setFilename("/home/sacha/testdb/refGene.txt");
    mMapModel->setColumnCount(6);


    QVBoxLayout * viewLayout = new QVBoxLayout;
    viewLayout->addWidget(mMapView);
    viewLayout->addWidget(mPreviewView);
    QGroupBox * mapBox = new QGroupBox("edit");
    mapBox->setLayout(viewLayout);

    mainLayout->addWidget(mapBox);
    mainLayout->addWidget(mButtonBox);



    setLayout(mainLayout);
    resize(800,600);

}
