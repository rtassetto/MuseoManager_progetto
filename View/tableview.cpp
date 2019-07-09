#include "tableview.h"
#include <QMouseEvent>

TableView::TableView(QWidget* parent) : QTableView(parent) {
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

QSize TableView::sizeHint() const {
    return QSize(1000, 450);
}

void TableView::mousePressEvent(QMouseEvent* event) {
     if (!indexAt(event->pos()).isValid()) {
        clearSelection();
        selectionModel()->clearCurrentIndex();
    }
    QTableView::mousePressEvent(event);
}
