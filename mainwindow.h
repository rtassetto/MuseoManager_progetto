#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <tableview.h>
#include <insertitem.h>
#include <QMessageBox>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    InsertItem* insert;
    QLineEdit* searchbar;
    TableView* view;
private slots:
    void addItem() const;
    void closeRequest();
 signals:
    void confirmExit();
};

#endif // MAINWINDOW_H
