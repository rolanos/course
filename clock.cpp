#include "clock.h"
#include <QPainter>
#include <cmath>

Clock::Clock(QWidget *parent) : QWidget(parent)
{
    setParent(parent);
    setGeometry(0, 0, 330, 330);

    timer = new QTimer(this);
    timer->setInterval(250);

    time = new QTime();
    *time = time->currentTime();

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
}

bool Clock::active() {
    bool f = false;
    for (int i = 0; i < events.size(); ++i) {
        f |= events[i].isShown;
    }
    return f;
}

void Clock::setState(QVector<bool> state) {
    for (int i = 0; i < events.size(); ++i)
        events[i].isShown = state[i];
}

void Clock::paintEvent(QPaintEvent*)
{
    *time = time->currentTime();

    QPainter p;
    QPen pen = QPen(Qt::black);
    QBrush brush = QBrush(Qt::black);

    double radius = 170;

    p.begin(this);

    p.setPen(pen);
    p.setBrush(brush);


    QPointF arrow[3];

    double a = 2 * acos(-1)/60;

    // Дизайн циферблата часов
    pen.setColor(Qt::gray);
    pen.setWidth(4);
    brush.setColor(Qt::transparent);

    p.setBrush(brush);

    // Круглый циферблат вокруг стрелок
    p.drawEllipse(radius/2, radius/2, radius, radius);


    double b = a * (time->second() - 15);
    arrow[0] = QPointF(radius + 75*cos(b), radius + 75*sin(b));
    arrow[1] = QPointF(radius + 7*cos(b+2*a), radius + 7*sin(b+2*a));
    arrow[2] = QPointF(radius + 7*cos(b-2*a), radius + 7*sin(b-2*a));
    p.setPen(pen);
    p.drawPolygon(arrow, 3);

    pen.setColor(Qt::blue);
    pen.setWidth(6);
    b = a * (time->minute() - 15);
    arrow[0] = QPointF(radius + 65*cos(b), radius + 65*sin(b));
    arrow[1] = QPointF(radius + 7*cos(b+2*a), radius + 7*sin(b+2*a));
    arrow[2] = QPointF(radius + 7*cos(b-2*a), radius + 7*sin(b-2*a));
    p.setPen(pen);
    p.drawPolygon(arrow, 3);

    pen.setColor(Qt::blue);
    pen.setWidth(8);
    b = 5 * a * (time->hour() - 3);
    arrow[0] = QPointF(radius + 55*cos(b), radius + 55*sin(b));
    arrow[1] = QPointF(radius + 7*cos(b+2*a), radius + 7*sin(b+2*a));
    arrow[2] = QPointF(radius + 7*cos(b-2*a), radius + 7*sin(b-2*a));
    p.setPen(pen);
    p.drawPolygon(arrow, 3);


    pen = QPen(Qt::black);
    brush = QBrush(Qt::black);
    p.setPen(pen);
    p.setBrush(brush);
    p.setFont(QFont("Times", 18, 2, false));
    p.drawText(radius * 0.70, radius * 0.8, time->toString());

    // int pos = 0, base = radius;
    // for (int i = 0; i < events.size(); ++i) {
    //     if (events[i].isShown) base -= 33;
    // }
    // for (int i = 0; i < events.size(); ++i) {
    //     if (events[i].isShown) {
    //         p.setPen(QPen(Qt::black));
    //         p.setBrush(QBrush(Qt::black));
    //         p.setOpacity(0.7);
    //         p.drawRect(QRectF(0, base + pos*66, 330, 60));

    //         p.setOpacity(1);
    //         p.setPen(QPen(QColor("#9b0000")));
    //         p.setBrush(QBrush(QColor("#0a40d6")));
    //         p.setFont(QFont("Modern No.20", 32, 1, false));
    //         p.drawText(QRectF(0, base + pos*66, 330, 60), events[i].name, QTextOption(Qt::AlignCenter));

    //         pos++;
    //     }
    // }

    p.end();
}
