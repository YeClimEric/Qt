#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QBrush>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this)),
    game(new GameController(scene, this))
{
    //ui->setupUi(this);
//    setCentralWidget(view);
//    resize(600, 600);
//    initScene();
//    initSceneBackground();
//    setWindowTitle("Gluttonous Snake");

//    //call Slot
//    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
//    setWindowFlags();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adjustViewSize()
{

}

void MainWindow::initScene()
{
    scene->setSceneRect(-100, -100, 200, 200);
}

void MainWindow::initSceneBackground()
{
    //使用pixmap填充整个显示区域
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0,0,TILE_SIZE, TILE_SIZE);
    view->setBackgroundBrush(QBrush(bg));
}
