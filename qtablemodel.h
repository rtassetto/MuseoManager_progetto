#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H
#include <QAbstractTableModel>
#include <modello.h>
#include<insertitem.h>
#include <itemview.h>

class QTableModel : public QAbstractTableModel
{
private:
    InsertItem* insert;
    Modello* model;
public:
    QTableModel(QObject* = nullptr, InsertItem* = nullptr);
    ~QTableModel() override;
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    bool setData(const QModelIndex&, const QVariant&, int) override;
    bool insertRows(int , int , const QModelIndex &) override;
    bool removeRows(int , int , const QModelIndex &) override;
    Qt::ItemFlags flags(const QModelIndex&) const override;
    void save(const std::string&) const;
    void load(const std::string &) const;
    void showView(const QModelIndex&) const;
    bool searchMatch(unsigned int , const QRegExp& , const QString& ) const;
    bool getSaved() const;
};

#endif // QTABLEMODEL_H
