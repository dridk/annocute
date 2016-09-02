#include "pathlineedit.h"

PathLineEdit::PathLineEdit(bool saveMode, QWidget *parent)
    :mSaveMode(saveMode),QWidget(parent)
{
    mLineEdit = new QLineEdit;
    mButton   = new QPushButton("Browse ...");

    QHBoxLayout * ll = new QHBoxLayout;
    ll->addWidget(mLineEdit);
    ll->addWidget(mButton);
    ll->setContentsMargins(0,0,0,0);

    setLayout(ll);

    connect(mButton,SIGNAL(clicked(bool)),this,SLOT(openFileDialog()));


}

QLineEdit *PathLineEdit::lineEdit()
{
    return mLineEdit;
}

void PathLineEdit::openFileDialog()
{
    QString path;
    if (mSaveMode)
    path = QFileDialog::getSaveFileName(this);
   else
    path = QFileDialog::getOpenFileName(this);

    if (!path.isEmpty())
        lineEdit()->setText(path);

}
