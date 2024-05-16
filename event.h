#ifndef EVENTYPE_H
#define EVENTYPE_H

#include <QString>
#include <QTime>

class Event {
public:
    Event(QString, QTime);

    //Название события
    QString name;
    //Время задержки
    QTime duration;
    //Индикатор того, было ли показано событие
    bool isActual = false;
};

class ScheduledEvent : public Event
{
public:
    //Полная инициализация по имени,
    ScheduledEvent(QString, QTime, QTime, QTime);

    //Время начала события
    QTime start;
    //Время окончания актуальности события
    QTime end;

    void copyFromEvent(Event);
};

#endif // EVENTYPE_H
