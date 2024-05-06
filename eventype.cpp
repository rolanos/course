#include "eventype.h"

EvenType::EvenType(QString n, QTime s)
{
    name = n;
    len = s;
}

Even::Even(EvenType t, QTime time1, QTime time2)
{
    type = new EvenType(t.name, t.len);
    start = time1;
    end = time2;
}
