#include <QApplication>
#include <QGraphicsScene>
#include "myplayer1.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * game = new QGraphicsScene();

    myplayer1 * p1 = new myplayer1();

    p1->setRect(0,0,100,100);

     // add the player to the game

    game->addItem(p1);

    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();


        // add a screen to visualize the game

    QGraphicsView * screen = new QGraphicsView(game);
    screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    screen-> show();
    screen->setFixedSize(950,700);
    game->setSceneRect(0,0,950,700);
    p1->setPos(0,300);

    return a. exec();
}
