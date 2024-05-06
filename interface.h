#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include "clock.h"
#include "eventype.h"
#include "table.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface :
                  public QWidget
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

    Clock* cl;
    Table* schedule;
    QVector<EvenType> types;
    QTimer* timer;

private slots:
    void on_pushButton_clicked();
    void updateState();
    void on_pushButton_2_clicked();
    void printTable();

private:
    Ui::Interface *ui;
};
#endif // INTERFACE_H
