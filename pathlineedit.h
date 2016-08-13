#ifndef PATHLINEEDIT_H
#define PATHLINEEDIT_H

#include <QtWidgets>
#include <QLineEdit>
#include <QPushButton>
class PathLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit PathLineEdit(QWidget *parent = 0);

    QLineEdit *lineEdit();

signals:

public slots:

private:
    QLineEdit * mLineEdit;
    QPushButton * mButton;
};

#endif // PATHLINEEDIT_H
