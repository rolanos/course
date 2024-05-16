#ifndef TABLE_H
#define TABLE_H

#include "event.h"
#include <QVector>
#include <QMap>
#include <QPaintEvent>
#include <QWidget>
#include <QTextEdit>

class Table : public QWidget
{
    Q_OBJECT
public:
    //Пустая таблица
    explicit Table(QWidget* parent = nullptr);
    //Деструктор
    ~Table();
    //Список событий
    QVector<Event> events;
    //Список запланированных событий
    QVector<ScheduledEvent> scheduledEvents;
    //Список наших событий
    QVector<ScheduledEvent> actualEvents;
    //Виджет списка событий
    QTextEdit* label;
    //Виджет списка актуальных событий
    QTextEdit* actualLabel;

    //Инициализация таблицы через метод
    void initTable(QVector<Event>);
    //Заполняем таблицу 20ю событиями
    void fillAlertTable();
    //Обновить актуальные события
    void updateActuals(QVector<ScheduledEvent>);
    //Очистка таблицы
    void clear();
    //Очистка таблицы с запланированными событиями
    void clearAlerts();

private:
    QTime add(QTime, QTime);
    const int N = 20;
    const int T1 = 2;
    const int T2 = 5;

protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // TABLE_H
