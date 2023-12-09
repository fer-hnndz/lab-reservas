#include "cframe.h"
#include "ui_cframe.h"

Cframe::Cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cframe)
{
    ui->setupUi(this);
}

Cframe::~Cframe()
{
    delete ui;
}

