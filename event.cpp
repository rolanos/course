#include "event.h"

Event::Event(QString name, QTime duration) {
    this->name = name;
    this->duration = duration;
}


ScheduledEvent::ScheduledEvent(QString name, QTime duration, QTime startTime, QTime endTime) : Event(name, duration)
{
    this->start = startTime;
    this->end = endTime;
}


void ScheduledEvent::copyFromEvent(Event event) {
    this->name = event.name;
    this->duration = event.duration;
}
