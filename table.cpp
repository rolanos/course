#include "table.h"
#include <QRandomGenerator>
#include <QMap>

Table::Table(QWidget *parent) : QWidget(parent)
{
    setParent(parent);
    label = new QTextEdit(parent);
    label->setReadOnly(true);
    label->setGeometry(720 * 0.5, 10, 720 * 0.4, 480 * 0.5);
    label->setAlignment(Qt::AlignTop);
    label->setStyleSheet("font-size: 18px;");
    label->setFrameShape(QFrame::NoFrame);

    actualLabel = new QTextEdit(parent);
    actualLabel->setReadOnly(true);
    actualLabel->setGeometry(720 * 0.5, 480 * 0.6, 720 * 0.4, 480 * 0.3);
    actualLabel->setAlignment(Qt::AlignTop);
    actualLabel->setStyleSheet("font-size: 18px;");
    actualLabel->setFrameShape(QFrame::NoFrame);
}

Table::~Table() {
    delete label;
    delete actualLabel;
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

void Table::initTable(QVector<Event> eventsBuffer)
{
    events = eventsBuffer;
}

void Table::fillAlertTable()
{
    clearAlerts();
    QTime startTime = QTime::currentTime();
    //Заводим генератор случайных чисел
    QRandomGenerator gen(QTime::currentTime().second());
    //Получаем случайное число от 0 до events.size() - 1
    int randomIndex = gen.bounded(0, events.size());
    //Добавляем первое событие в список таблицы
    scheduledEvents.append(ScheduledEvent(events[randomIndex].name, events[randomIndex].duration, startTime , add(startTime, events[randomIndex].duration)));
    //Добавляем оставшиеся 19 событий в список таблицы
    for (int i = 1; i < N; ++i) {
        startTime = add(startTime, QTime(0, 0, gen.bounded(T1, T2)));
        randomIndex = gen.bounded(0, events.size());
        scheduledEvents.append(ScheduledEvent(events[randomIndex].name, events[randomIndex].duration, startTime, add(startTime, events[randomIndex].duration)));
    }
}

void Table::updateActuals(QVector<ScheduledEvent> actualBuffer)
{
    actualEvents = actualBuffer;
}

void Table::clear() {
    events.clear();
    clearAlerts();
}

void Table::clearAlerts() {
    scheduledEvents.clear();
}


void Table::paintEvent(QPaintEvent*)
{
    QVector<ScheduledEvent>::iterator scheduledIterator = scheduledEvents.begin();
    QVector<ScheduledEvent>::iterator actualIterator = actualEvents.begin();

    QString scheduledOut = "Расписание событий\n";
    QString actualOut = "Актуальные события\n";

    if(scheduledEvents.isEmpty()) {
        QVector<Event>::iterator eventsIterator = events.begin();
        while (eventsIterator != events.end()) {
            scheduledOut += eventsIterator->name + " - " + eventsIterator->duration.toString() + "\n";
            eventsIterator++;
        }
    }
    else {
        while (scheduledIterator != scheduledEvents.end()) {
            scheduledOut += scheduledIterator->name + " " + scheduledIterator->start.toString() + " - " + scheduledIterator->end.toString() + "\n";
            scheduledIterator++;
        }
    }

    while (actualIterator != actualEvents.end()) {
        actualOut += actualIterator->name + " " + actualIterator->start.toString() + " - " + actualIterator->end.toString() + "\n";
        actualIterator++;
    }
    label->setText(scheduledOut);
    actualLabel->setText(actualOut);

}

