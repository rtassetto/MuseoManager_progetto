#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include <QWidget>
#include <QLineEdit>
#include<QComboBox>
#include <QPushButton>
#include <QLabel>

class SearchView : public QWidget
{
    Q_OBJECT
private:
    QLineEdit* searchbar;
    QPushButton* clear;
    QComboBox* type;
public:
    explicit SearchView(QWidget *parent = nullptr);
    QComboBox* getType() const;
    QLineEdit* getSearchbar()const;

signals:

public slots:
    void clearSearch();
};

#endif // SEARCHVIEW_H
