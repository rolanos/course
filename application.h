#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();
};
#endif // APPLICATION_H
