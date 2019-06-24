#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <tableview.h>
#include <insertitem.h>
#include <QMessageBox>
#include <museoitem.h>
#include <qtablemodel.h>
#include <qproxymodel.h>

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QLineEdit* searchbar;
    InsertItem* insert;
    QProxyModel* proxymodel;
    QTableModel* model;
    TableView* view;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow() override=default;

private slots:
    void addItem() const;
    void closeRequest();
    void clearSearchBar();
    void showInsert();
 signals:
    void confirmExit();
};

#endif // MAINWINDOW_H
