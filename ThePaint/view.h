#ifndef VIEW_H
#define VIEW_H

#include "model.h"
#include "control.h"
#include "paintarea.h"

#include <QMainWindow>
#include <QColor>
#include <QTableWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>


class View : public QMainWindow
{
    Q_OBJECT

    Control     *control;
    Model       *model;

    PaintArea   *Tableau;

    QTabWidget  *TAB;
    QTabWidget  *TABcote;

    QPushButton *fantome1;
    QPushButton *SaveButton;
    QPushButton *UploadButton;

    QPushButton *screenCleanerButton;

    QPushButton *pencil;
    QPushButton *shapeLine;
    QPushButton *shapeCircle;
    QPushButton *shapeRect;

    QPushButton *PenColorButton;
    QPushButton *eraserButton;
    QSpinBox    *changePenWidth;

    QWidget     *file;
    QHBoxLayout *BoxLayout;
    QVBoxLayout *BoxLayoutcote;

    //COLOR_BUTTON
    QPushButton *catButton;
    QPushButton *colorBlack;
    QPushButton *colorRouge;
    QPushButton *colorBlue;
    QPushButton *colorRose;
    QPushButton *colorOrange;
    QPushButton *colorTurquoise;
    QPushButton *colorVert;
    QPushButton *colorYellow;

public:
    explicit View(Model* model, QWidget *parent = 0);
    ~View();
    void setControl(Control *control){
        this->control = control;
    }


private:
    void affichage();

private slots:
    bool save();
    bool upload();
    void screenCleaner();
    void penWidth(int);
    void changerCouleurStylo();
    void eraser();

    //palette
    void penBlackColor();
    void penBlueColor();
    void penRoseColor();
    void penRougeColor();
    void penYellowColor();
    void penVertColor();
    void penTurquoiseColor();
    void penGrayColor();

    //pencil&shapes&cat
    void draw();
    void drawLine();
    void drawRect();
    void drawCircle();
    void cat();

};

#endif // VIEW_H
