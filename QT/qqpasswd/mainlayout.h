#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "webcard.h"

const int WIDTH = 100;

class MainLayout : public QDialog
{
    Q_OBJECT
public:
    explicit MainLayout(QWidget *parent = 0);
    virtual ~MainLayout();
    
private:
    QLineEdit *txtCode1, *txtCode2, *txtCode3;
    QLineEdit *ansCode1, *ansCode2, *ansCode3;
    QPushButton *btnOK, *btnClear, *btnCancel;
    WebCard *webcard;
private slots:
    void slotOK();
    void slotClear();
};

#endif // MAINLAYOUT_H
