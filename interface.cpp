#include "interface.h"
#include "ui_interface.h"
#include <QFileDialog>
#include <QTextStream>

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    this->setWindowTitle("Будильник");
    cl = new Clock(ui->widget);
    cl->update();
    schedule = new Table();
    timer = new QTimer(this);
    timer->setSingleShot(false);
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateState()));
    ui->pushButton_2->setChecked(false);
}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_pushButton_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, "расписание", NULL, "TXT (*.txt);");
    QFile file(name);
    if (file.open(QIODevice::ReadOnly)) {
        types.clear();
        QTextStream in(&file);
        QString out = "";
        bool i = !in.atEnd();
        while (!in.atEnd()) {
            QString line = in.readLine();
            line.remove(QChar(' '));
            QStringList splitted = line.split('"');
            splitted.removeAll(QString(""));
            QString name_type = splitted.first();

            out += name_type + " ";

            int sec = splitted.last().toInt();

            QTime t(sec / 3600 % 24, sec / 60 % 60, sec % 60);

            types.append(EvenType(name_type, t));

            out += t.toString() + "\n";
        }

        for (int i = 0; i < types.size(); ++i)
            cl->key[i].type = new EvenType(types[i].name, types[i].len);
        ui->textEdit->setText(out);
    }
}

void Interface::updateState()
{
    cl->setState(schedule->getState(QTime::currentTime()));
}

void Interface::on_pushButton_2_clicked()
{
    if (types.size() != 0) {
        if (ui->pushButton_2 != nullptr) {
            if (!ui->pushButton_2->isChecked()) {
                ui->pushButton_2->setChecked(false);
                ui->pushButton_2->setText("Завести будильник");

                QVector<bool> v = {false, false, false, false, false};
                cl->setState(v);
                timer->stop();
                schedule->clear();
                QString out = "";
                for (int i = 0; i < types.size(); ++i)
                    out += types[i].name + " " + types[i].len.toString() + "\n";
                ui->textEdit->setText(out);
            }
        }
    }
    else {
        if(ui->pushButton_2 != nullptr)
            ui->pushButton_2->setText("Стоп");
        if(ui->pushButton_2 != nullptr)
            ui->pushButton_2->setChecked(true);
        if(schedule != nullptr)
            schedule->fillTable(types);
        if(cl != nullptr)
            cl->setState(schedule->getState(QTime::currentTime()));
        if(timer != nullptr)
            timer->start();

        printTable();
    }
}

void Interface::printTable()
{

    QVector<Even>::iterator it = schedule->events.begin();
    QString out = "                         Расписание:\n___________________________________\n";

    while (it != schedule->events.end()) {
        out += "   " + it->type->name + " " + it->start.toString() + " " + it->end.toString() + "\n";
        it++;
    }
    ui->textEdit->setText(out);
}
