#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Cframe; }
QT_END_NAMESPACE

class Cframe : public QMainWindow
{
    Q_OBJECT

public:
    Cframe(QWidget *parent = nullptr);
    ~Cframe();

private:
    Ui::Cframe *ui;
};
#endif // CFRAME_H
