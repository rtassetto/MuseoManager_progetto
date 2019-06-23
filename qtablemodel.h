#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H
#include <QAbstractTableModel>
#include <modello.h>
#include<insertitem.h>

class QTableModel : public QAbstractTableModel
{
private:
    Modello* model;
    InsertItem* insert;
public:
    QTableModel(QObject* = nullptr, InsertItem* = nullptr);
    ~QTableModel() override;
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    bool removeRows(int , int , const QModelIndex &)override;
    bool insertRows(int , int , const QModelIndex &) override;
    void removeRows(int , int , const QModelIndex &) override;
};

#endif // QTABLEMODEL_H
