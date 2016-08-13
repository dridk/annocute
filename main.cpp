#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "previewfilemodel.h"
#include "importfileeditor.h"
#include "mapfilemodel.h"
#include "importdialog.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

  ImportDialog dialog;
  dialog.show();


//    QTableView view;
//    PreviewFileModel * model = new PreviewFileModel;
//    view.setModel(model);

//    model->load("/home/sacha/testdb/refGene.txt");

//    view.show();

    return a.exec();
}
