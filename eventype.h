#ifndef EVENTYPE_H
#define EVENTYPE_H

#include <QString>
#include <QTime>

class EvenType
{
public:
    EvenType(QString, QTime);
    QString name;
    QTime len;
};

class Even
{
public:
    Even(EvenType, QTime, QTime);
    EvenType* type;
    QTime start, end;
};

#endif // EVENTYPE_H
