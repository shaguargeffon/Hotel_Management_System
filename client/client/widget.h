#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tcp_client.h"

static TcpClient client;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void trigger_connection() {
        client.doConnect();
    }

    void trigger_receive() {
        client.receive_data();
    }

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
