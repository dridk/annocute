#include "pathlineedit.h"

PathLineEdit::PathLineEdit(QWidget *parent) : QWidget(parent)
{
    mLineEdit = new QLineEdit;
    mButton   = new QPushButton("Browse ...");

    QHBoxLayout * ll = new QHBoxLayout;
    ll->addWidget(mLineEdit);
    ll->addWidget(mButton);
    ll->setContentsMargins(0,0,0,0);

    setLayout(ll);



}

QLineEdit *PathLineEdit::lineEdit()
{
    return mLineEdit;
}
