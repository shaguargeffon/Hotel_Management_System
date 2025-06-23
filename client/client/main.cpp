#include "widget.h"

#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QTcpSocket>
#include "tcp_client.h"
#include "QObject"



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Widget w;
    w.resize(1000, 500);

    QPushButton button_connection(&w);
    button_connection.move(500, 100);
    button_connection.resize(80, 30);
    button_connection.setText("Connect");


    QPushButton button_receive_data(&w);
    button_receive_data.move(200, 100);
    button_receive_data.resize(80, 30);
    button_receive_data.setText("receive");


    QObject::connect(&button_connection, SIGNAL(clicked()), &w, SLOT(trigger_connection()));

    QObject::connect(&button_receive_data, SIGNAL(clicked()), &w, SLOT(trigger_receive()));


    w.show();
    return app.exec();
}
