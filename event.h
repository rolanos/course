#ifndef EVENTYPE_H
#define EVENTYPE_H

#include <QString>
#include <QTime>

class Event
{
public:
    Event(QString, int);

    QString getName();
    //в секундах
    int duration;
    //Название события
    QString name;
    //Время начала события
    QTime start;
    //Время окончания актуальности события
    QTime end;
    //Индикатор того, было ли показано событие
    bool isShown;
};

#endif // EVENTYPE_H
