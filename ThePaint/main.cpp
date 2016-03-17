#include "model.h"
#include "view.h"
#include "control.h"

#include <QApplication>

//Bonjour monsieur X toutes les fonctionnalités de notre programme marche

//Jade Dagher & Jeremie Tata //classe 2x serie 3

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    View v(&m);
    Control c(&m, &v);

    v.show();

    return a.exec();
}
