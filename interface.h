#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QThread>
#include <QPushButton>

#include "clock.h"
#include "event.h"
#include "table.h"


class Interface : public QWidget
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

    Clock* cl;
    Table* schedule;
    QVector<Event> types;
    QVector<ScheduledEvent> events;
    QTimer* timer;

    QPushButton* chooseFileButton;
    QPushButton* startAlarm;


private slots:
    void onPushButtonFileClicked();
    void updateState();
    void on_pushButton_2_clicked();
};
#endif // INTERFACE_H
