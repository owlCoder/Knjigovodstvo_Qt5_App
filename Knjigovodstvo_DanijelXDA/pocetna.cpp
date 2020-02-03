#include "pocetna.h"
#include "ui_pocetna.h"

Pocetna::Pocetna(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pocetna)
{
    ui->setupUi(this);
}

Pocetna::~Pocetna()
{
    delete ui;
}
