#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H



#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <iostream>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    //explicit TcpClient(QObject *parent = 0);



signals:

public slots:
    void doConnect(){
        socket = new QTcpSocket(this);
        socket->connectToHost(QString("192.168.2.185"), 8888);
        if(!socket->waitForConnected(5000))
        {
           qDebug()<<"Connection failed";
        }
    }

    void receive_data(){
        QByteArray buffer = socket->readAll();
        QString receive_str = QString(buffer);
        qDebug()<<receive_str;
    }

    void connected(){}
    void disconnected(){}
    //void bytesWritten(qint64 bytes){}
    void readyRead(){}

private:
    QTcpSocket *socket;

};



#endif // TCP_CLIENT_H
