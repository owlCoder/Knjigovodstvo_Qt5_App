#ifndef KONEKCIJA_H
#define KONEKCIJA_H

#include <QtSql/QtSql>

class Konekcija
{
    public:
        Konekcija();
        void dbOpen();
        void dbClose();

    private:
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        QString dbPutanja = "C:/Program Files/DanijelXDA/Knjige/Baza.db";  // Obavezno podesiti adresu baze!!!
    };

#endif // KONEKCIJA_H
