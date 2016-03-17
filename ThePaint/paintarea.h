#ifndef PAINTAREA_H
#define PAINTAREA_H


#include <QMainWindow>

#include <QMainWindow>
#include <QTableWidget>
#include <QScrollArea>
#include <QColor>
#include <QStack>
#include <QSizeGrip>


class Model;

class PaintArea : public QWidget
{

private:
    Model *model;

public:
    PaintArea(Model *model, QWidget *parent=0);
    ~PaintArea();
    void setGeometryTI(int,int,int,int);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // PAINTAREA_H
