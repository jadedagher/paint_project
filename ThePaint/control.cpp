#include "control.h"
#include "model.h"
#include "view.h"

#include <QDebug>

Control::Control(Model *model, View *view) : view(view){
  this->model = model;
  view->setControl(this);
}

Control::~Control(){
}

bool Control::save(const QString &fileName, const char *fileFormat){
    return model->save(fileName,fileFormat);
}

QSize Control::upload(QString fileName){
    return model->upload(fileName);
}

void Control::screenCleaner(){
    model->screenCleaner();
}

void Control::penWidth(int newWidth){
    model->setPenWidth(newWidth);
}
