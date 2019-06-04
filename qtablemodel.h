#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H
#include <QAbstractTableModel>
#include <modello.h>

class QTableModel : public QAbstractTableModel
{
private:
    Modello* model;
public:
    QTableModel();
    ~QTableModel();
    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;
    bool insertColumns(int , int , const QModelIndex &)override;
    bool insertRows(int , int , const QModelIndex &) override;
    void removeColumns(int , int , const QModelIndex &) override;
    void removeRows(int , int , const QModelIndex &) override;
};

#endif // QTABLEMODEL_H
