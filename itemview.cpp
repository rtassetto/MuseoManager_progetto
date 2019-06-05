#include "itemview.h"
#include <QPushButton>

ItemView::ItemView(QWidget *parent) : QMainWindow(parent)
{
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());
    //campi item
    QPushButton* exit= new QPushButton("Chiudi",this);

    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
}
