#include "paintarea.h"
#include "model.h"
#include "control.h"

#include <QPainter>
#include <QtWidgets>

PaintArea::PaintArea(Model *model,QWidget *parent) : QWidget(parent)
{
    setGeometry(128,80,1150,720);
    setAttribute(Qt::WA_StaticContents);
    setCursor(Qt::CrossCursor);
    this->model=model;
}
PaintArea::~PaintArea(){
}


void PaintArea::setGeometryTI(int px,int py,int tx,int ty){
    setGeometry(px,py,tx,ty);
}
void PaintArea::mousePressEvent(QMouseEvent *event){
    model->mousePressEvent(event);
}
void PaintArea::mouseMoveEvent(QMouseEvent *event){
    model->mouseMoveEvent(event);
}
void PaintArea::mouseReleaseEvent(QMouseEvent *event){
    model->mouseReleaseEvent(event);
}
void PaintArea::paintEvent(QPaintEvent *event){
    model->paintEvent(event);
}


