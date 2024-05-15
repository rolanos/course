#include "table.h"
#include <QRandomGenerator>
#include <QMap>

Table::Table(QWidget *parent) : QWidget(parent)
{
    setParent(parent);
    label = new QLabel(parent);
    label->setGeometry(720 * 0.6, 10, 200, 480);
    label->setAlignment(Qt::AlignTop);
    label->setStyleSheet("font-size: 20px;");


}

Table::~Table() {
    delete label;
}

QTime Table::add(QTime t1, QTime t2)
{
    int sec, min, h, r;
    sec = t1.second() + t2.second();
    r = sec / 60;
    sec = sec % 60;

    min = t1.minute() + t2.minute() + r;
    r = min / 60;
    min = min % 60;

    h = t1.hour() + t2.hour() + r;
    h = h % 24;

    return QTime(h, min, sec);
}

void Table::initTable(QVector<Event> events)
{
    QTime startTime = QTime::currentTime();
    //Заводим генератор случайных чисел
    QRandomGenerator gen(QTime::currentTime().second());
    //Получаем случайное число от 0 до events.size() - 1
    int randomIndex = gen.bounded(0, events.size());
    //Добавляем первое событие в список таблицы
    events.append(ScheduledEvent(events[randomIndex].name, events[randomIndex].duration, startTime ,add(startTime, events[randomIndex].duration)));
    //Добавляем оставшиеся 19 событий в список таблицы
    for (int i = 1; i < N; ++i) {
        startTime = add(startTime, QTime(0, 0, gen.bounded(T1, T2)));
        randomIndex = gen.bounded(0, events.size());
        events.append(ScheduledEvent(events[randomIndex].name, events[randomIndex].duration, startTime, add(startTime, events[randomIndex].duration)));
    }
}

void Table::clear() {
    events.clear();
}

QVector<bool> Table::getState(QTime time)
{
    QVector<bool> state(events.size());
    for (int i = 0; i < state.size(); ++i) state[i] = false;
    for (int i = 0; i < N; ++i) {
        if (time <= events[i].end && time >= events[i].start)
            state[i] = true;
    }
    return state;
}


void Table::paintEvent(QPaintEvent*)
{
    QVector<ScheduledEvent>::iterator it = events.begin();
    QString out = "Наше расписание";

    while (it != events.end()) {
        out += it->name + " " + it->start.toString() + " " + it->end.toString() + "\n";
        it++;
    }
    label->setText(out);
}

