#include "table.h"
#include <QRandomGenerator>
#include <QMap>

Table::Table()
{

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

void Table::fillTable(QVector<EvenType> types)
{
    QTime t = QTime::currentTime();
    for (int i = 0; i < types.size(); ++i) {
        tipes.insert(types[i].name, i);
    }
    QRandomGenerator gen(QTime::currentTime().second());
    int r = gen.bounded(0, types.size());
    events.append(Even ( types[r] , t , add(t, types[r].len)));
    for (int i = 1; i < N; ++i) {
        t = add(t, QTime(0, 0, gen.bounded(T1, T2)));
        r = gen.bounded(0, types.size());
        events.append( Even ( types[r] , t , add(t, types[r].len) ) );
    }
}

QVector<bool> Table::getState(QTime time)
{
    QVector<bool> state(tipes.size());
    for (int i = 0; i < state.size(); ++i) state[i] = false;
    for (int i = 0; i < N; ++i) {
        if (time <= events[i].end && time >= events[i].start)
            state[*tipes.find(events[i].type->name)] = true;
    }
    return state;
}

void Table::clear() {
    events.clear();
    tipes.clear();
}
