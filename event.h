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
};

class ScheduledEvent : public Event
{
public:
    //Полная инициализация
    ScheduledEvent(QString, QTime, QTime, QTime);

    //Время начала события
    QTime start;
    //Время окончания актуальности события
    QTime end;

    void copyFromEvent(Event);
};

#endif // EVENTYPE_H
