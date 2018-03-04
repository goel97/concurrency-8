#include <QApplication>
#include "target.h"
#include "myplayer1.h"
#include "score.h"
#include "scoreboard.h"
#include <QGraphicsScene>
#include "gamestate.h"
//#include <QPointF>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QJsonObject>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QJsonValue>

score * points ;
int flag;
int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    gamestate * state = new gamestate(scene);
    // create an item to add to the scene
    myplayer1 * p1 = new myplayer1(state);
    myplayer1 * p2 = new myplayer1(1);
    // add the item to the scene
    scene->addItem(p1);
    scene->addItem(p1->bow1);
    scene->addItem(p2);
    target * t = new target(state);
    scene->addItem(t);
    // make rect focusable
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scoreboard * s =new scoreboard();
    scene->addItem(s);
    points = new score();
    scene->addItem(points);

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.resized.jpeg")));
    p1->setPos(0,200);
    p1->bow1->setPos(60,210);
    p2->setPos(650,200);
    s->setPos(200,0);
    t->setPos(view->width()/2,view->height()-60);
    //state->StateSet(p1,p2,t);
    state->Player1Position.setX(p1->x());
    state->Player1Position.setY(p1->y());
    state->Player2Position.setX(p2->x());
    state->Player2Position.setY(p2->y());
    state->TargetPosition.setX(t->x());
    state->TargetPosition.setY(t->y());
    return a.exec();
}
