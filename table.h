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
    //Список наших событий
    QVector<ScheduledEvent> events;
    //Инициализация таблицы через метод
    void initTable(QVector<Event>);
    //Очистка таблицы
    void clear();
    //Виджеты списка
    QTextEdit* label;

    QVector<bool> getState(QTime);

private:
    QTime add(QTime, QTime);
    const int N = 20;
    const int T1 = 2;
    const int T2 = 5;

protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // TABLE_H
