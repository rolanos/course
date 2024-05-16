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

    //LOGIC
    QTimer* timer;

    //DATA
    QVector<Event> types;
    QVector<ScheduledEvent> events;

    //WIDGETS
    Clock* cl;
    Table* schedule;

    QPushButton* chooseFileButton;
    QPushButton* startAlarm;


private slots:
    //Callback выбор файла с конфигурацией
    void onPushButtonFileClicked();
    //Callback при остановке/запуске таймера (timer)
    void onChangeTimerStatus();
    //Callback при работе таймера в активном режиме обновляем состояние
    void updateState();
};
#endif // INTERFACE_H
