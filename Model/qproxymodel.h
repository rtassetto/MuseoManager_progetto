#ifndef QPROXYMODEL_H
#define QPROXYMODEL_H
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <Model/qtablemodel.h>
class QProxyModel : public QSortFilterProxyModel
{
private:
    const QComboBox* attribute;
public:
    QProxyModel(QObject* =nullptr, QComboBox * =nullptr);
    void removeDisplayed();
    void showView(const QModelIndex&) const;
    bool insertRows(int, int =1, const QModelIndex& = QModelIndex()) override;
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};

#endif // QPROXYMODEL_H
