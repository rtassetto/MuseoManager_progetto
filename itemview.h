#ifndef ITEMVIEW_H
#define ITEMVIEW_H
#include <QLabel>
#include <QTextEdit>

#include <QMainWindow>

class ItemView : public QMainWindow
{
    Q_OBJECT
public:
    explicit ItemView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ITEMVIEW_H
