#ifndef MODEL_H
#define MODEL_H

#include "paintarea.h"

#include <QMainWindow>
#include <QColor>
#include <QStack>

class Model
{

private:

    void resizeImage(QImage *image, const QSize &nouvelleTaille);

    PaintArea *tableau;

    bool dessiner;
    int PenWidth;
    bool maybeSave();
    QColor PenColor;
    QImage image;

    QPoint firstPoint;
    void drawing(const QPoint &endPoint);

    QStack<QImage>historique;

    int action;

public:
    Model();
    ~Model();

    //save&upload
    bool save(const QString &fileName, const char *fileFormat);
    QSize upload(QString fileName);

    void setTableau(PaintArea* Tableau);

    //mouseEvent
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);
    void screenCleaner();

    //width
    void setPenWidth(int newWidth);

    //colors
    void setPenColor(QColor &newColor);
    QColor changerCouleurStylo(){return PenColor;}

    void setActionLigne(int action);

    //shapes
    void line(const QPoint &endPoint);
    void rectangle(const QPoint &endPoint);
    void circle(const QPoint &endPoint);
    void cat(const QPoint &endPoint);

};

#endif // MODEL_H
