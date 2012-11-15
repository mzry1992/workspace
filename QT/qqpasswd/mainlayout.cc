#include "mainlayout.h"
#include <QGridLayout>
#include <QFont>
#include <QRegExp>
#include <QRegExpValidator>

MainLayout::MainLayout(QWidget *parent) :
    QDialog(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    QFont font("Courier 10 pitch", 48);
    QRegExp regExp("[A-K][1-8]");
    QRegExpValidator *regExpValidator = new QRegExpValidator(regExp, this);

    webcard = new WebCard();
    txtCode1 = new QLineEdit();
    txtCode1->setFont(font);
    txtCode1->setValidator(regExpValidator);
    txtCode1->setFixedWidth(WIDTH);
    txtCode1->setAlignment(Qt::AlignCenter);
    txtCode2 = new QLineEdit();
    txtCode2->setFont(font);
    txtCode2->setValidator(regExpValidator);
    txtCode2->setFixedWidth(WIDTH);
    txtCode2->setAlignment(Qt::AlignCenter);
    txtCode3 = new QLineEdit();
    txtCode3->setFont(font);
    txtCode3->setValidator(regExpValidator);
    txtCode3->setFixedWidth(WIDTH);
    txtCode3->setAlignment(Qt::AlignCenter);
    ansCode1 = new QLineEdit();
    ansCode1->setFont(font);
    ansCode1->setEnabled(false);
    ansCode1->setFixedWidth(WIDTH);
    ansCode1->setAlignment(Qt::AlignCenter);
    ansCode2 = new QLineEdit();
    ansCode2->setFont(font);
    ansCode2->setEnabled(false);
    ansCode2->setFixedWidth(WIDTH);
    ansCode2->setAlignment(Qt::AlignCenter);
    ansCode3 = new QLineEdit();
    ansCode3->setFont(font);
    ansCode3->setEnabled(false);
    ansCode3->setFixedWidth(WIDTH);
    ansCode3->setAlignment(Qt::AlignCenter);
    btnOK = new QPushButton(tr("OK"));
    btnClear = new QPushButton(tr("Clear"));
    btnCancel = new QPushButton(tr("Cancel"));

    layout->addWidget(txtCode1, 0, 0);
    layout->addWidget(txtCode2, 0, 1);
    layout->addWidget(txtCode3, 0, 2);
    layout->addWidget(btnOK, 1, 0);
    layout->addWidget(btnClear, 1, 1);
    layout->addWidget(btnCancel, 1, 2);
    layout->addWidget(ansCode1, 2, 0);
    layout->addWidget(ansCode2, 2, 1);
    layout->addWidget(ansCode3, 2, 2);

    connect(btnOK, SIGNAL(clicked()), this, SLOT(slotOK()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(slotClear()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

MainLayout::~MainLayout()
{
    delete txtCode1;
    delete txtCode2;
    delete txtCode3;
    delete ansCode1;
    delete ansCode2;
    delete ansCode3;
    delete webcard;
    delete btnOK;
    delete btnCancel;
    delete btnClear;
}

void MainLayout::slotOK()
{
    ansCode1->setText(webcard->get(txtCode1->text()));
    ansCode2->setText(webcard->get(txtCode2->text()));
    ansCode3->setText(webcard->get(txtCode3->text()));
}

void MainLayout::slotClear()
{
    txtCode1->setText(tr(""));
    txtCode2->setText(tr(""));
    txtCode3->setText(tr(""));
}
