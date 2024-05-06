#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include "eventype.h"

class state {
public:
    state();
    EvenType* type;
    bool act;
};

class Clock :
              public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = nullptr);
    void setState(QVector<bool>);
    QVector<state> key;

private:
    QTime* time;
    QTimer* timer;
    bool active();
    const int K = 5;

protected:
    void paintEvent(QPaintEvent*) override;

};

#endif // CLOCK_H
