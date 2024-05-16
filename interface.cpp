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

    cl = new Clock(this);
    cl->update();

    schedule = new Table(this);
    schedule->update();

    timer = new QTimer(this);
    timer->setSingleShot(false);
    timer->setInterval(500);

    chooseFileButton = new QPushButton("Выбрать конфигурацию", this);
    chooseFileButton->setGeometry(width * 0.07, height * 0.6, width * 0.4, height * 0.1);
    chooseFileButton->setStyleSheet("padding: 12px; border-radius: 10px; background-color: darkblue; color: white;");

    startAlarm = new QPushButton("Запустить будильник", this);
    startAlarm->setGeometry(width * 0.07, height * 0.75, width * 0.4, height * 0.1);
    startAlarm->setStyleSheet("padding: 12px; border-radius: 10px; background-color: darkblue; color: white;");
    startAlarm->setCheckable(true);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateState()));
    connect(chooseFileButton, SIGNAL(pressed()), this, SLOT(onPushButtonFileClicked()));
    connect(startAlarm, SIGNAL(pressed()), this, SLOT(onChangeTimerStatus()));
}

Interface::~Interface()
{
    delete cl;
    delete schedule;
    delete chooseFileButton;
    delete startAlarm;
}

void Interface::onPushButtonFileClicked()
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

            QTime time((sec / 3600) % 24, (sec / 60) % 60, sec % 60);

            types.append(Event(name_type, time));

            out += time.toString() + "\n";
        }

        schedule->initTable(types);
        schedule->update();
    }
}

void Interface::onChangeTimerStatus()
{
    if (types.size() != 0) {
        if (schedule->scheduledEvents.isEmpty()) {
            startAlarm->setText("Стоп");
            schedule->fillAlertTable();
            timer->start();
            schedule->update();
        }
        else {
            startAlarm->setText("Завести будильник");
            schedule->clearAlerts();
            timer->stop();
            schedule->update();

        }
    }
}

void Interface::updateState()
{
    schedule->updateActuals(cl->getActualEvents(schedule->scheduledEvents));
}



