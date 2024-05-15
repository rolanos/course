#include "interface.h"
#include <QFileDialog>
#include <QTextStream>

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    double height = 480;
    double width = 720;


    setWindowTitle("Будильник");
    setFixedSize(width, height);
    // cl = new Clock(this);
    // cl->update();
    schedule = new Table(this);
    schedule->update();
    timer = new QTimer(this);
    timer->setSingleShot(false);
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateState()));
}

Interface::~Interface()
{
    delete cl;
    delete schedule;
}

void Interface::on_pushButton_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, "расписание", NULL, "TXT (*.txt);");
    QFile file(name);
    if (file.open(QIODevice::ReadOnly)) {
        types.clear();
        QTextStream in(&file);
        QString out = "";
        while (!in.atEnd()) {
            QString line = in.readLine();
            line.remove(QChar(' '));
            QStringList splitted = line.split('"');
            splitted.removeAll(QString(""));
            QString name_type = splitted.first();

            out += name_type + " ";

            int sec = splitted.last().toInt();

            QTime t(sec / 3600 % 24, sec / 60 % 60, sec % 60);

            types.append(Event(name_type, t));

            out += t.toString() + "\n";
        }

        for (int i = 0; i < types.size(); ++i) {
            events[i].copyFromEvent(types[i]);
        }
        schedule->label->setText(out);
    }
}

void Interface::updateState()
{
    cl->setState(schedule->getState(QTime::currentTime()));
}

void Interface::on_pushButton_2_clicked()
{

}

