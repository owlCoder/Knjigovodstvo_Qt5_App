#ifndef DODAJKORISNIKA_H
#define DODAJKORISNIKA_H

#include <QDialog>
#include "BAZA/konekcija.h"

namespace Ui {
class DodajKorisnika;
}

class DodajKorisnika : public QDialog
{
    Q_OBJECT

public:
    explicit DodajKorisnika(QWidget *parent = nullptr);
    ~DodajKorisnika();

private slots:
    void on_dodaj_clicked();
    void on_izlaz_clicked();

private:
    Ui::DodajKorisnika *ui;
};

#endif // DODAJKORISNIKA_H
