#include "clock.h"
#include <QPainter>
#include <cmath>

state::state() {
    act = false;
}

Clock::Clock(QWidget *parent) : QWidget(parent)
{
    setParent(parent);
    setGeometry(0, 0, 330, 330);

    key.resize(K);
    timer = new QTimer(this);
    timer->setInterval(250);

    time = new QTime();
    *time = time->currentTime();

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
}

void Clock::setState(QVector<bool> state) {
    for (int i = 0; i < key.size(); ++i)
        key[i].act = state[i];
}

bool Clock::active() {
    bool f = false;
    for (int i = 0; i < key.size(); ++i) {
        f |= key[i].act;
    }
    return f;
}

void Clock::paintEvent(QPaintEvent*)
{
    // *time = time->currentTime();

    // QPainter p;
    // p.begin(this);
    // p.setRenderHint(QPainter::SmoothPixmapTransform);

    // if (!active()) p.drawPixmap(0, 0, 330, 330, QPixmap(":/img/Calm"));
    // else if (time->msec() % 500 > 250)
    //     p.drawPixmap(0, 0, 330, 330, QPixmap(":/img/act1"));
    // else
    //     p.drawPixmap(0, 0, 330, 330, QPixmap(":/img/act2"));

    // p.setPen(QPen(QColor("#ee8")));
    // p.setBrush(QBrush(QColor("#ee8")));
    // p.setFont(QFont("Magneto", 12, 1, false));
    // p.drawText(129, 221, time->toString());

    // p.setRenderHint(QPainter::Antialiasing);
    // p.setPen(QPen(Qt::white));
    // p.setBrush(QBrush(Qt::white));
    // QPointF arrow[3];
    // double a = 2*acos(-1)/60;

    // double b = a * (time->second() - 15);
    // arrow[0] = QPointF(168 + 70*cos(b), 184 + 70*sin(b));
    // arrow[1] = QPointF(168 + 7*cos(b+2*a), 184 + 7*sin(b+2*a));
    // arrow[2] = QPointF(168 + 7*cos(b-2*a), 184 + 7*sin(b-2*a));
    // p.drawPolygon(arrow, 3);

    // b = a * (time->minute() - 15);
    // arrow[0] = QPointF(168 + 60*cos(b), 184 + 60*sin(b));
    // arrow[1] = QPointF(168 + 7*cos(b+2*a), 184 + 7*sin(b+2*a));
    // arrow[2] = QPointF(168 + 7*cos(b-2*a), 184 + 7*sin(b-2*a));
    // p.drawPolygon(arrow, 3);

    // b = 5 * a * (time->hour() - 3);
    // arrow[0] = QPointF(168 + 40*cos(b), 184 + 40*sin(b));
    // arrow[1] = QPointF(168 + 7*cos(b+2*a), 184 + 7*sin(b+2*a));
    // arrow[2] = QPointF(168 + 7*cos(b-2*a), 184 + 7*sin(b-2*a));
    // p.drawPolygon(arrow, 3);

    // int pos = 0, base = 165;
    // for (int i = 0; i < key.size(); ++i) {
    //     if (key[i].act) base -= 33;
    // }
    // for (int i = 0; i < key.size(); ++i) {
    //     if (key[i].act) {
    //         p.setPen(QPen(Qt::black));
    //         p.setBrush(QBrush(Qt::black));
    //         p.setOpacity(0.7);
    //         p.drawRect(QRectF(0, base + pos*66, 330, 60));

    //         p.setOpacity(1);
    //         p.setPen(QPen(QColor("#3e9bff")));
    //         p.setBrush(QBrush(QColor("#0a40d6")));
    //         p.setFont(QFont("Modern No.20", 32, 1, false));
    //         p.drawText(QRectF(0, base + pos*66, 330, 60), key[i].type->name, QTextOption(Qt::AlignCenter));

    //         pos++;
    //     }
    // }

    // p.end();
}
