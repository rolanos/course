#include "event.h"

Event::Event(QString name, int duration)
{
    this->name = name;
    this->duration = duration;
    start = QTime::currentTime();
    end = QTime::currentTime().addSecs(duration);
}

