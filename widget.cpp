#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

   rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);

   // addEllipse(x,y,w,h,pen,brush)
   ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);

   text = scene->addText("bogotobogo.com", QFont("Arial", 20) );
   // movable text
   text->setFlag(QGraphicsItem::ItemIsMovable);


   item = new MyItem();
   scene->addItem(item);
}

Widget::~Widget()
{
    delete ui;
}
