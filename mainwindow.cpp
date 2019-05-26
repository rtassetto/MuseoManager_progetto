#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setWindowIcon(QIcon(":/images/icon.png"));
    setFixedSize(QSize(500,650));
}

MainWindow::~MainWindow()
{

}
