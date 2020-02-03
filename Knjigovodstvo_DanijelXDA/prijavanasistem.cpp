#include "prijavanasistem.h"
#include "ui_prijavanasistem.h"
#include "dodajkorisnika.h"
#include "BAZA/konekcija.h"
#include "pocetna.h"

PrijavaNaSistem::PrijavaNaSistem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PrijavaNaSistem)
{
    ui->setupUi(this);

    ui -> statusbar -> showMessage("Copyright © 2020. Sixth Sense & Danijel Jovanović");
}

PrijavaNaSistem::~PrijavaNaSistem()
{
    delete ui;
}


void PrijavaNaSistem::on_prijava_clicked()
{
    if(ui -> korIme -> text() == "danijelxda" && ui -> lozinka -> text() == "danijelxda")
    {
        this -> close();
        DodajKorisnika *d = new DodajKorisnika(this);
        d -> setModal(true);
        d -> show(); 
    }
    else if(ui -> korIme -> text().isEmpty() || ui -> lozinka -> text().isEmpty())
    {
        ui -> statusbar -> showMessage("Popunite sva polja za nastavak!");
    }
    else
    {
        Konekcija baza;
        baza.dbOpen();

        QSqlQuery upit;
        QString user = ui -> korIme -> text(),
                lozinka = ui -> lozinka -> text();


        upit.prepare("SELECT *FROM korisnici WHERE username=:user AND password=:pass;");
        upit.bindValue(":user", user);
        upit.bindValue(":pass", lozinka);
        upit.exec();

        upit.first();
        if(upit.value(0) == user && upit.value(1) == lozinka)
        {
            this -> close();
            Pocetna *p = new Pocetna(this);
            p -> setModal(true);
            p -> show();
        }
        else
            ui -> statusbar -> showMessage("Korisnik se ne nalazi u bazi podataka!");

        baza.dbClose();
    }

}

void PrijavaNaSistem::on_izlaz_clicked()
{
    this -> close();
}
