#include "model.h"

#include <QFile>
#include <QDebug>
#include <QPainter>
#include <QtWidgets>
#include <QMessageBox>

Model::Model()
{
    dessiner = false;
    PenWidth = 1;
    PenColor = Qt::magenta;

    QSize taille_par_defaut(1280,720);
    resizeImage(&image,taille_par_defaut);

}

Model::~Model(){

}

void Model::setTableau(PaintArea* tableau){
    this->tableau=tableau;
}

void Model::resizeImage(QImage *image, const QSize &nouvelleTaille){
    if (image->size() == nouvelleTaille)
        return;

    QImage nouvelleImage(nouvelleTaille, QImage::Format_RGB32);
    nouvelleImage.fill(qRgb(255, 255, 255));
    QPainter painter(&nouvelleImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = nouvelleImage;
}

//-----------------------------Save&Upload-------------------------------------------

bool Model::save(const QString &fileName, const char *fileFormat){
    QImage visibleImage = image;
    resizeImage(&visibleImage, tableau->size());
    if (visibleImage.save(fileName, fileFormat)) {
        return true;
    } else {
        return false;
    }
}

QSize Model::upload(QString fileName){

    QImage imageCharge;
    if (!imageCharge.load(fileName))
        return QSize(0,0);
    else if(imageCharge.size().width()>image.size().width() && imageCharge.size().height()>image.size().height()){
        tableau->setGeometryTI(0,0,imageCharge.size().width(),imageCharge.size().height());
    }

    QPainter painter(&image);
    painter.drawImage(QPoint(0, 0), imageCharge);
    tableau->update();

    historique.push(image);
    return QSize(image.size().width(),image.size().height());
}
//-----------------------------Save&Upload-------------------------------------------

//-----------------------------MouseEvent-------------------------------------------

void Model::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        firstPoint = event->pos();
        dessiner = true;
    }
}

void Model::mouseMoveEvent(QMouseEvent *event){
    if ((event->buttons() & Qt::LeftButton) && dessiner){
        if(action == 0){
            drawing(event->pos());
        }
        else if(action == 2){
            rectangle(event->pos());
        }
    }
}

void Model::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && dessiner){
            if(action == 0){
                drawing(event->pos());
            }
            else if(action == 1){
                line(event->pos());
            }
            else if(action == 2){
                rectangle(event->pos());
            }
            else if(action == 3){
                circle(event->pos());
            }
            else if(action == 4){
                cat(event->pos());
            }
            dessiner = false;
            historique.push(image);
    }
}
//-----------------------------MouseEvent-------------------------------------------

void Model::paintEvent(QPaintEvent *event){
    QPainter painter(tableau);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void Model::screenCleaner(){
    image.fill(qRgb(255, 255, 255));
    tableau->update();
    historique.push(image);
}

void Model::setPenWidth(int newWidth){
   PenWidth=newWidth;
}

//-----------------------------color&width-------------------------------------------

void Model::setPenColor(QColor &newColor)
{
    PenColor = newColor;
}

void Model::setActionLigne(int action){
    this->action=action;
}

//-----------------------------color&width-------------------------------------------


//-----------------------------pencil&shape&cat-------------------------------------------

void Model::drawing(const QPoint &endPoint){
    QPainter painter(&image);
    painter.setPen(QPen(PenColor,PenWidth, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawLine(firstPoint, endPoint);

    int rad = (PenWidth / 2) + 2;
    tableau->update(QRect(firstPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    firstPoint = endPoint;
}

void Model::cat(const QPoint &endPoint){
     QPainter painter(&image);
     painter.drawPixmap(QPoint(endPoint.x(),endPoint.y()),QPixmap(":/cat.png"));
     tableau->update();
}

void Model::circle(const QPoint &endPoint){
    QPainter painter(&image);
    painter.setPen(QPen(PenColor,PenWidth, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawEllipse(firstPoint.x(), firstPoint.y(), (endPoint.x()-firstPoint.x()), (endPoint.y()-firstPoint.y()));
    tableau->update();
}

void Model::rectangle(const QPoint &endPoint){
    image=historique.top();
    QPainter painter(&image);
    painter.setPen(QPen(PenColor,PenWidth, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    QRect rect = QRect(firstPoint.x(), firstPoint.y(), (endPoint.x()-firstPoint.x()), (endPoint.y()-firstPoint.y()));
    painter.drawRect(rect);
    tableau->update();
}

void Model::line(const QPoint &endPoint){
    QPainter painter(&image);
    painter.setPen(QPen(PenColor,PenWidth, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawLine(firstPoint, endPoint);
    tableau->update();
}
//-----------------------------pencil&shape&cat-------------------------------------------

