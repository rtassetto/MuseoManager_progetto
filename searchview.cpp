#include "searchview.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

SearchView::SearchView(QWidget *parent) : QWidget(parent),searchbar(new QLineEdit(this)),clear(new QPushButton("Clear",this)), type(new QComboBox(this))
{
    QLabel* filterLabel=new QLabel("Filtra per:",this);
    type->addItem("Nome");
    type->addItem("Tipo");
    type->addItem("Autore");

    // Dà un nome al pulsante per usarlo nel css
    clear->setObjectName("clearbutton");
    clear->setToolTip("Pulisci ricerca");

    searchbar->setPlaceholderText("Cosa stai cercando?");

    QVBoxLayout* mainLayout=new QVBoxLayout(this);
    QHBoxLayout* searchLayout=new QHBoxLayout();
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(filterLabel);
    searchLayout->addWidget(type);
    searchLayout->addWidget(clear);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();

    QPushButton* showButton=new QPushButton("Mostra/Modifica",this);
    showButton->setToolTip(QString("Permette di visualizzare e modificare i campi dell'oggetto selezionato"));
    QPushButton* removeButton=new QPushButton("Elimina",this);
    removeButton->setToolTip(QString("Rimuove l'oggetto selezionato"));
    QPushButton* removeAllButton=new QPushButton("Elimina tutti",this);
    removeAllButton->setToolTip(QString("Rimuove tutti gli oggetti risultato della ricerca"));
    buttonsLayout->addWidget(showButton);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addWidget(removeAllButton);

    mainLayout->addLayout(searchLayout);
    mainLayout->addLayout(buttonsLayout);

    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clearSearch()));


}

QComboBox *SearchView::getType() const
{
    return type;

}

QLineEdit *SearchView::getSearchbar() const
{
    return searchbar;

}

void SearchView::clearSearch()
{
    searchbar->setText("");
}
