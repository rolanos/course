#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include "event.h"

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = nullptr);

    QVector<ScheduledEvent> getActualEvents(QVector<ScheduledEvent>);

    ~Clock();
private:
    QTime* time;

    QTimer* timer;

    //Определения time в промежутке. Если он между start и end - true, иначе - false
    bool isTimeBetween(QTime start, QTime end);

protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // CLOCK_H
