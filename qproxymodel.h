#ifndef QPROXYMODEL_H
#define QPROXYMODEL_H
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <qtablemodel.h>
class QProxyModel : public QSortFilterProxyModel
{
private:
    const QComboBox* attribute;
public:
    QProxyModel(QObject* =nullptr, const QComboBox* =nullptr);
    void removeDisplayed();
    bool insertRows(int, int =1, const QModelIndex& = QModelIndex()) override;
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};

#endif // QPROXYMODEL_H