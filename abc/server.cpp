
#include "server.h"
#include <QDebug>

server::server(QGraphicsScene scene_param, quint16 port_param):
    port(port_param)
{

    gameStarted = false;
    server_local = new QWebSocketServer(QStringLiteral("Archery Server"),QWebSocketServer::NonSecureMode,this);
}

void server::startServer()
{

    if(server_local->listen(QHostAddress("0.0.0.0"),port))
    {
            qDebug() << "Server Started";
            qDebug() << "Server listening on port" << port;
            QObject::connect(server_local,&QWebSocketServer::newConnection,this, &server::connectionSetup);
    }
    else
    {
            qDebug() << "Error In Connecting To Port : " << port;
            qDebug() << "Error Message : " << server_local->errorString();
            std::exit(EXIT_FAILURE);
    }
            qDebug() << "Server's connecting URL : " << server_local->serverUrl();
}
void server::startGame()
{

}

void server::connectionSetup()
{
            qDebug() << "Got A New Connection To Play Game";

    if(gameStarted)
    {
            QWebSocket *client_Socket = server_local->nextPendingConnection();
            client_Socket->sendTextMessage("The Game Has Already Started . <br>Please Join Us For The Next Game.");
    }

    else
    {
            QWebSocket *client_Socket = server_local->nextPendingConnection();
            QObject::connect(client_Socket, &QWebSocket::binaryMessageReceived, this, &server::processBinary,Qt::DirectConnection);
            QObject::connect(client_Socket, &QWebSocket::textMessageReceived, this, &server::processText,Qt::DirectConnection);

            client_Socket->sendTextMessage("Successfully Connected.");
            qDebug() << "Added To server_local And Sent Response Message";
    }
}

void server::gameLoop()
{

}

void server::processText()
{

}

void server::processBinary()
{

}



