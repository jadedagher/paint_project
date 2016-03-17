#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>

class Model;
class View;

class Control
{
private:
    Model *model;
    View *view;

public:
    Control(Model *model, View *view);
    ~ Control();

    View* getView(){return view;}
    bool save(const QString &fileName, const char *fileFormat);
    QSize upload(QString);
    void screenCleaner();
    void penWidth(int);

};

#endif // CONTROL_H
