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
    void setState(QVector<bool>);

private:
    QTime* time;
    QTimer* timer;
    bool active();
    QVector<ScheduledEvent> events;

    const int K = 5;


protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // CLOCK_H
