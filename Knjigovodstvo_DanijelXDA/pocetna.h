#ifndef POCETNA_H
#define POCETNA_H

#include <QDialog>

namespace Ui {
class Pocetna;
}

class Pocetna : public QDialog
{
    Q_OBJECT

public:
    explicit Pocetna(QWidget *parent = nullptr);
    ~Pocetna();

private:
    Ui::Pocetna *ui;
};

#endif // POCETNA_H
