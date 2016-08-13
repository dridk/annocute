#include "importfileeditor.h"

ImportFileEditor::ImportFileEditor(QWidget *parent) : QWidget(parent)
{
    mView  = new QTableView;
    mModel = new PreviewFileModel;

    mView->setModel(mModel);



    mModel->setFilename("/home/sacha/testdb/refGene.txt");







}

