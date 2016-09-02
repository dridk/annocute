#ifndef PATHLINEEDIT_H
#define PATHLINEEDIT_H

#include <QtWidgets>
#include <QLineEdit>
#include <QPushButton>
class PathLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit PathLineEdit(bool saveMode = false,QWidget *parent = 0);
    QLineEdit *lineEdit();
protected slots:
void openFileDialog();

private:
    QLineEdit * mLineEdit;
    QPushButton * mButton;
    bool mSaveMode ;
};

#endif // PATHLINEEDIT_H
