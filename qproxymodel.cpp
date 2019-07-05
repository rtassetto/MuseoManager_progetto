#include "qproxymodel.h"

QProxyModel::QProxyModel(QObject * parent,  QComboBox * a): QSortFilterProxyModel(parent), attribute(a)
{

}

void QProxyModel::removeDisplayed()
{
    while(rowCount()){
        removeRows(0,1);
    }
}

bool QProxyModel::insertRows(int beg, int c, const QModelIndex &parent)
{

    bool result = sourceModel()->insertRows(beg, c, parent);
    invalidateFilter();
    return result;

}

bool QProxyModel::filterAcceptsRow(int row, const QModelIndex &) const
{
    return static_cast<QTableModel*>(sourceModel())->searchMatch(static_cast<unsigned int>(row), filterRegExp(), attribute->currentText());
}
