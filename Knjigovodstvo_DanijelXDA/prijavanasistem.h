#ifndef PRIJAVANASISTEM_H
#define PRIJAVANASISTEM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PrijavaNaSistem; }
QT_END_NAMESPACE

class PrijavaNaSistem : public QMainWindow
{
    Q_OBJECT

public:
    PrijavaNaSistem(QWidget *parent = nullptr);
    ~PrijavaNaSistem();

private slots:
    void on_prijava_clicked();

    void on_izlaz_clicked();

private:
    Ui::PrijavaNaSistem *ui;
};
#endif // PRIJAVANASISTEM_H
