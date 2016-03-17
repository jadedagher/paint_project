#include "view.h"
#include "paintarea.h"

#include <QDesktopWidget>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QInputDialog>

View::View(Model* model,QWidget *parent): QMainWindow(parent){
    this->model = model;

    setWindowTitle(tr("ThePaint by Jade Dagher & Jeremie Tata "));
    resize(1300, 693);

    affichage();
}

View::~View(){
}


void View::affichage(){

    QDesktopWidget *toolbox = new QDesktopWidget;
//    _______TAB-TOOLBOX
    TAB = new QTabWidget(this);
    TAB->setStyleSheet("QTabWidget::pane {background-color:orange;}");
    TAB->setGeometry(0,0,toolbox->screenGeometry().width(),toolbox->screenGeometry().height()*0.1);

//    _______TABcote-TOOLBOX
    TABcote = new QTabWidget(this);
    TABcote->setStyleSheet("QTabWidget::pane {background-color:grey;}");
    TABcote->setGeometry(0,0,toolbox->screenGeometry().width()*0.1,toolbox->screenGeometry().height());

    file = new QWidget;
    BoxLayout = new QHBoxLayout(TAB);
    BoxLayoutcote = new QVBoxLayout(TABcote);


//    _______BUTTON_____BoxLayout

        //fantome
        QPushButton *fantome1 = new QPushButton("                ",file);
        fantome1->setFlat(true);

        //save
        QPushButton *SaveButton = new QPushButton("&Save",file);
        QPixmap saveIcon(":/save.png");
        QIcon saveIcon2(saveIcon);
        SaveButton->setFlat(true);
        SaveButton->setMinimumSize(3, 3);
        SaveButton->setIcon(saveIcon2);
        SaveButton->setIconSize(saveIcon.rect().size());
        connect(SaveButton, SIGNAL(clicked()), this, SLOT(save()));

        //upload
        QPushButton *UploadButton = new QPushButton("&Upload",file);
        QPixmap uploadIcon(":/upload.png");
        QIcon uploadIcon2(uploadIcon);
        UploadButton->setFlat(true);
        UploadButton->setMinimumSize(3, 3);
        UploadButton->setIcon(uploadIcon2);
        UploadButton->setIconSize(uploadIcon.rect().size());
        connect(UploadButton, SIGNAL(clicked()), this, SLOT(upload()));

        //screenCleaner
        QPushButton *screenCleanerButton = new QPushButton("Bin",file);
        QPixmap binIcon(":/bin.png");
        QIcon binIcon2(binIcon);
        screenCleanerButton->setFlat(true);
        screenCleanerButton->setMinimumSize(3, 3);
        screenCleanerButton->setIcon(binIcon2);
        screenCleanerButton->setIconSize(binIcon.rect().size());
        connect(screenCleanerButton, SIGNAL(clicked()), this, SLOT(screenCleaner()));

        //pencil
        QPushButton *pencil = new QPushButton("&Pen",file);
        QPixmap pencilIcon(":/pencil.png");
        QIcon pencilIcon2(pencilIcon);
        pencil->setFlat(true);
        pencil->setMinimumSize(3, 3);
        pencil->setIcon(pencilIcon);
        pencil->setIconSize(pencilIcon.rect().size());
        connect(pencil, SIGNAL(clicked()), this, SLOT(draw()));

//------------------------Shapes----------------------------
        //shapeLine
        QPushButton *shapeLine = new QPushButton("&Line",file);
        QPixmap LineIcon(":/line.png");
        QIcon LineIcon2(LineIcon);
        shapeLine->setFlat(true);
        shapeLine->setMinimumSize(3, 3);
        shapeLine->setIcon(LineIcon);
        shapeLine->setIconSize(LineIcon.rect().size());
        connect(shapeLine, SIGNAL(clicked()), this, SLOT(drawLine()));

        //shapeCircle
        QPushButton *shapeCircle = new QPushButton("&Circle",file);
        QPixmap circleIcon(":/circle.png");
        QIcon circleIcon2(circleIcon);
        shapeCircle->setFlat(true);
        shapeCircle->setMinimumSize(3, 3);
        shapeCircle->setIcon(circleIcon);
        shapeCircle->setIconSize(circleIcon.rect().size());
        connect(shapeCircle, SIGNAL(clicked()), this, SLOT(drawCircle()));

        //shapeRect
        QPushButton *shapeRect = new QPushButton("&Rect",file);
        QPixmap rectangleIcon(":/rectangle.png");
        QIcon rectangleIcon2(rectangleIcon);
        shapeRect->setFlat(true);
        shapeRect->setMinimumSize(3, 3);
        shapeRect->setIcon(rectangleIcon);
        shapeRect->setIconSize(rectangleIcon.rect().size());
        connect(shapeRect, SIGNAL(clicked()), this, SLOT(drawRect()));
//------------------------Shapes----------------------------

        //penColor
        QPushButton *PenColorButton = new QPushButton("&PenColor",file);
        QPixmap changeColorIcon(":/changeColor.png");
        QIcon changeColorIcon2(uploadIcon);
        PenColorButton->setFlat(true);
        PenColorButton->setMinimumSize(3, 3);
        PenColorButton->setIcon(changeColorIcon);
        PenColorButton->setIconSize(changeColorIcon.rect().size());
        connect(PenColorButton, SIGNAL(clicked()), this, SLOT(changerCouleurStylo()));

        //eraser
        QPushButton *eraserButton = new QPushButton("&Eraser",file);
        QPixmap eraserIcon(":/eraser.png");
        QIcon eraserIcon2(eraserIcon);
        eraserButton->setFlat(true);
        eraserButton->setMinimumSize(3, 3);
        eraserButton->setIcon(eraserIcon);
        eraserButton->setIconSize(eraserIcon.rect().size());
        connect(eraserButton, SIGNAL(clicked()), this, SLOT(eraser()));

        //penWidth
        changePenWidth = new QSpinBox(this);
        changePenWidth->setAlignment(Qt::AlignCenter);
        changePenWidth->setMaximumWidth(100);
        changePenWidth->setRange(1,40);
        connect(changePenWidth, SIGNAL(valueChanged(int)), this, SLOT(penWidth(int)));

        BoxLayout->addWidget(fantome1);
        BoxLayout->addWidget(SaveButton);
        BoxLayout->addWidget(UploadButton);
        BoxLayout->addWidget(screenCleanerButton);
        BoxLayout->addWidget(pencil);
        BoxLayout->addWidget(shapeLine);
        BoxLayout->addWidget(shapeCircle);
        BoxLayout->addWidget(shapeRect);
        BoxLayout->addWidget(PenColorButton);
        BoxLayout->addWidget(eraserButton);
        BoxLayout->addWidget(changePenWidth);

//    _______BUTTON_____BoxLayoutcote



//------------------------PaletteCouleur----------------------------
        //Black
        QPushButton *colorBlack = new QPushButton(file);
        QPixmap blackIcon(":/black(000000).png");
        QIcon blackIcon2(blackIcon);
        colorBlack->setFlat(true);
        colorBlack->setMinimumSize(3, 3);
        colorBlack->setIcon(blackIcon2);
        colorBlack->setIconSize(blackIcon.rect().size());
        connect(colorBlack, SIGNAL(clicked()), this, SLOT(penBlackColor()));

        //Rouge
        QPushButton *colorRouge = new QPushButton(file);
        QPixmap rougeIcon(":/rouge(f7001d).png");
        QIcon rougeIcon2(rougeIcon);
        colorRouge->setFlat(true);
        colorRouge->setMinimumSize(3, 3);
        colorRouge->setIcon(rougeIcon2);
        colorRouge->setIconSize(rougeIcon.rect().size());
        connect(colorRouge, SIGNAL(clicked()), this, SLOT(penRougeColor()));

        //Blue
        QPushButton *colorBlue = new QPushButton(file);
        QPixmap blueIcon(":/blue(0f2cf7).png");
        QIcon blueIcon2(blueIcon);
        colorBlue->setFlat(true);
        colorBlue->setMinimumSize(3, 3);
        colorBlue->setIcon(blueIcon2);
        colorBlue->setIconSize(blueIcon.rect().size());
        connect(colorBlue, SIGNAL(clicked()), this, SLOT(penBlueColor()));

        //Cyan
        QPushButton *colorTurquoise = new QPushButton(file);
        QPixmap turquoiseIcon(":/turquoise(38C9BD).png");
        QIcon turquoiseIcon2(turquoiseIcon);
        colorTurquoise->setFlat(true);
        colorTurquoise->setMinimumSize(3, 3);
        colorTurquoise->setIcon(turquoiseIcon2);
        colorTurquoise->setIconSize(turquoiseIcon.rect().size());
        connect(colorTurquoise, SIGNAL(clicked()), this, SLOT(penTurquoiseColor()));

        //Vert
        QPushButton *colorVert = new QPushButton(file);
        QPixmap VertIcon(":/vert(88C915).png");
        QIcon VertIcon2(VertIcon);
        colorVert->setFlat(true);
        colorVert->setMinimumSize(3, 3);
        colorVert->setIcon(VertIcon2);
        colorVert->setIconSize(VertIcon.rect().size());
        connect(colorVert, SIGNAL(clicked()), this, SLOT(penVertColor()));

        //Yellow
        QPushButton *colorYellow = new QPushButton(file);
        QPixmap yellowIcon(":/yellow(faee06).png");
        QIcon yellowIcon2(yellowIcon);
        colorYellow->setFlat(true);
        colorYellow->setMinimumSize(3, 3);
        colorYellow->setIcon(yellowIcon2);
        colorYellow->setIconSize(yellowIcon.rect().size());
        connect(colorYellow, SIGNAL(clicked()), this, SLOT(penYellowColor()));

        //Grey
        QPushButton *colorGray = new QPushButton(file);
        QPixmap GrayIcon(":/grey.png");
        QIcon GrayIcon2(GrayIcon);
        colorGray->setFlat(true);
        colorGray->setMinimumSize(3, 3);
        colorGray->setIcon(GrayIcon2);
        colorGray->setIconSize(GrayIcon.rect().size());
        connect(colorGray, SIGNAL(clicked()), this, SLOT(penGrayColor()));

        //Rose
        QPushButton *colorRose = new QPushButton(file);
        QPixmap roseIcon(":/rose(F267C0).png");
        QIcon roseIcon2(roseIcon);
        colorRose->setFlat(true);
        colorRose->setMinimumSize(3, 3);
        colorRose->setIcon(roseIcon2);
        colorRose->setIconSize(roseIcon.rect().size());
        connect(colorRose, SIGNAL(clicked()), this, SLOT(penRoseColor()));

        //chat
        QPushButton *catButton = new QPushButton(file);
        QPixmap catIcon(":/cat.png");
        QIcon catIcon2(catIcon);
        catButton->setFlat(true);
        catButton->setMinimumSize(3, 3);
        catButton->setIcon(catIcon2);
        catButton->setIconSize(catIcon.rect().size());
        connect(catButton, SIGNAL(clicked()), this, SLOT(cat()));

        BoxLayoutcote->addWidget(catButton);
        BoxLayoutcote->addWidget(colorRose);
        BoxLayoutcote->addWidget(colorTurquoise);
        BoxLayoutcote->addWidget(colorVert);
        BoxLayoutcote->addWidget(colorYellow);
        BoxLayoutcote->addWidget(colorRouge);
        BoxLayoutcote->addWidget(colorBlue);
        BoxLayoutcote->addWidget(colorGray);
        BoxLayoutcote->addWidget(colorBlack);
//------------------------PaletteCouleur----------------------------

//    _______Tableau
    Tableau = new PaintArea(model,this);
    Tableau->setStyleSheet("background-color:white;");
    model->setTableau(Tableau);

}

//-----------------------------Save&Upload-------------------------------------------
bool View::save(){
    bool save = false;
    QString file = QFileDialog::getSaveFileName(this, "Save a file",
                                                QString(), "Image (*.png *.gif *.jpg *.jpeg)");
    const char* fileExtension = file.section('.', -1).toLocal8Bit().constData();
    if(!file.isEmpty()){
        save = control->save(file,fileExtension);
    }
    return save;
}

bool View::upload(){

    QString fichier = QFileDialog::getOpenFileName(this, "Upload file", QString(), "Images (*.png *.jpg *.jpeg)");
    control->upload(fichier);
}
//-----------------------------Save&Upload-------------------------------------------

void View::screenCleaner(){
    control->screenCleaner();
}
void View::penWidth(int newWidth){
     control->penWidth(newWidth);
}
void View::changerCouleurStylo()
{
    QColor newColor = QColorDialog::getColor(model->changerCouleurStylo());
    if (newColor.isValid()){
        model->setPenColor(newColor);
    }
}
void View::eraser(){
    QColor newColor = Qt::white;
    model->setPenColor(newColor);
}

//------------------------PaletteCouleur----------------------------
void View::penBlackColor(){
    QColor newColor = Qt::black;
    model->setPenColor(newColor);
}
void View::penBlueColor(){
    QColor newColor = Qt::blue;
    model->setPenColor(newColor);
}
void View::penRougeColor(){
    QColor newColor = Qt::red;
    model->setPenColor(newColor);
}
void View::penYellowColor(){
    QColor newColor = Qt::yellow;
    model->setPenColor(newColor);
}
void View::penVertColor(){
    QColor newColor = Qt::green;
    model->setPenColor(newColor);
}
void View::penRoseColor(){
    QColor newColor = Qt::magenta;
    model->setPenColor(newColor);
}
void View::penTurquoiseColor(){
    QColor newColor = Qt::cyan;
    model->setPenColor(newColor);
}
void View::penGrayColor(){
    QColor newColor = Qt::gray;
    model->setPenColor(newColor);
}
//------------------------END-PaletteCouleur----------------------------

//------------------------Shapes----------------------------
void View::draw(){
    model->setActionLigne(0);
}
void View::drawLine(){
    model->setActionLigne(1);
}
void View::drawRect(){
    model->setActionLigne(2);
}
void View::drawCircle(){
    model->setActionLigne(3);
}
void View::cat(){
    model->setActionLigne(4);
}
//------------------------Shapes----------------------------
