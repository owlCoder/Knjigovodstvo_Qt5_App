#include "dodajkorisnika.h"
#include "ui_dodajkorisnika.h"

#include "prijavanasistem.h"

#include <QMessageBox>

DodajKorisnika::DodajKorisnika(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajKorisnika)
{
    ui->setupUi(this);
}

DodajKorisnika::~DodajKorisnika()
{
    delete ui;
}

void DodajKorisnika::on_dodaj_clicked()
{
    Konekcija baza;
    baza.dbOpen();

    QSqlQuery upit;
    QString user = ui -> korIme -> text(),
            lozinka = ui -> lozinka -> text();

    upit.prepare("INSERT INTO korisnici VALUES(:user, :pass);");
    upit.bindValue(":user", user);
    upit.bindValue(":pass", lozinka);

    if( upit.exec() )
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Obaveštenje");
        msgBox.setText("Korisnik je dodat u bazu podataka!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Obaveštenje");
        msgBox.setText("Korisnik već postoji u bazi podataka!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }


}

void DodajKorisnika::on_izlaz_clicked()
{
    this -> close();
    PrijavaNaSistem *p = new PrijavaNaSistem(this);
    p -> show();
}
