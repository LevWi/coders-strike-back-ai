#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "consts.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, ArenaScreen::WIDGTH, ArenaScreen::HEIGHT);
    ui->arenaView->setScene(scene);

    QBrush brush(Qt::red);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);
    scene->setBackgroundBrush(Qt::yellow);
    ellipsetest = scene->addEllipse(10,10,100,100, blackPen, brush);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto pos = ellipsetest->pos();
    ellipsetest->setPos(pos.x() + 10, pos.y() + 10);
    ellipsetest->setFlag(QGraphicsItem::ItemIsMovable);
}
