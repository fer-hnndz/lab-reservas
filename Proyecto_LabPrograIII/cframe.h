#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <ListaReservas.h>
#include<Solicitante.h>
#include <vector>
#include <ReservaDia.h>
#include<Reserva.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Cframe; }
QT_END_NAMESPACE

class Cframe : public QMainWindow
{
    Q_OBJECT

public:
    Cframe(QWidget *parent = nullptr);
    ~Cframe();

private slots:
    void on_pushButton_clicked();

    void on_CBX_PerfSol_activated(const QString &arg1);

    void on_PB_Enviar_clicked();

private:
    Ui::Cframe *ui;
    ListaReservas reservas;
    std::vector<ReservaDia> reservasDia;

};
#endif // CFRAME_H
