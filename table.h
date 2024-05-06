#ifndef TABLE_H
#define TABLE_H

#include "eventype.h"
#include <QVector>
#include <QMap>

class Table
{
public:
    Table();
    QVector<Even> events;
    QMap<QString, int> tipes;
    void fillTable(QVector<EvenType>);
    void clear();
    QVector<bool> getState(QTime);

private:
    QTime add(QTime, QTime);
    const int N = 20;
    const int T1 = 2;
    const int T2 = 5;
};

#endif // TABLE_H
