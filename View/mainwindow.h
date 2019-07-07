#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <View/tableview.h>
#include <View/insertitem.h>
#include <QMessageBox>
#include <Model/Gerarchia/museoitem.h>
#include <Model/qtablemodel.h>
#include <Model/qproxymodel.h>
#include <View/searchview.h>


class MainWindow : public QWidget
{
    Q_OBJECT
private:
    SearchView* search;
    InsertItem* insert;
    QProxyModel* proxymodel;
    QTableModel* model;
    TableView* view;
    QString file;


public:
    MainWindow(QWidget *parent = 0, bool toLoad=true);
    ~MainWindow() override=default;
    bool isSaved;

private slots:
    void addItem() const;
    void closeRequest();
    void showInsert();
    void searchTextChanged();
    void showMain();
    void showView();
    void deleteData();
    void deleteAllData();
    void save();
    void load();
 signals:
    void noInsert();
    void confirmExit();
};

#endif // MAINWINDOW_H
