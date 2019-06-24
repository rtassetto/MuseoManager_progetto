#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLineEdit>
#include <insertitem.h>
#include <QMessageBox>
#include <museoitem.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),searchbar(new QLineEdit(this)),insert(new InsertItem(this)),
      view(new TableView(this))
{
    insert->hide();
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setFixedSize(QSize(550,600));
    setWindowIcon(QIcon(":/data/images/icon.png"));


    QComboBox* searchAttribute = new QComboBox();
    proxymodel = new QProxyModel(this, searchAttribute);
    model = new QTableModel(this, insert);
    /*if(load)
        loadData(); //caricamento modello*/
    proxymodel->setSourceModel(model);
    view->setModel(proxymodel);

    QLabel* filterLabel=new QLabel("Filtra per:",this);
    searchAttribute->addItem("Nome");
    searchAttribute->addItem("Tipo");
    searchAttribute->addItem("Autore");


    //Pulsanti
    QPushButton* clearSearchButton = new QPushButton("Clear", this);

    // Dà un nome al pulsante per usarlo nel css
    clearSearchButton->setObjectName("clearbutton");
    clearSearchButton->setToolTip("Pulisci ricerca");

    // MENÙ e MENUBAR
    QMenuBar* menuBar = new QMenuBar();
    QMenu* menuFile = new QMenu("File", menuBar);
    QMenu* menuAdd = new QMenu("Aggiungi", menuBar);
    QAction* addItemAction = new QAction("Salva", menuAdd);
    QAction* saveAction = new QAction("Salva", menuFile);
    QAction* exitAction = new QAction("Esci", menuFile);

    // Setup del menù
    menuBar->addMenu(menuFile);
    menuBar->addMenu(menuAdd);
    menuAdd->addAction(addItemAction);
    menuFile->addAction(saveAction);
    menuFile->addAction(exitAction);

    // LAYOUT
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Searchbar sottolayout
    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(filterLabel);
    searchLayout->addWidget(searchAttribute);
    searchLayout->addWidget(clearSearchButton);
    searchbar->setPlaceholderText("Cosa stai cercando? ...");

    // Pulsanti sottolayout
   /* QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addWidget(toggleButton);*/

    // Setup Main layout
    mainLayout->addWidget(menuBar);
    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(view, 0);
    mainLayout->addWidget(insert);
    /*mainLayout->addLayout(buttonsLayout, 50);*/

    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(closeRequest()));
    connect(clearSearchButton,SIGNAL(clicked()),this,SLOT(clearSearchBar()));
    connect(insert, SIGNAL(inserito()), this, SLOT(addItem()));
    connect(addItemAction,SIGNAL(triggered()),this,SLOT(showInsert()));

}



void MainWindow::addItem() const
{

    proxymodel->insertRows(proxymodel->rowCount(), 1);
    view->clearSelection();
    view->selectionModel()->clearCurrentIndex();
    view->selectionModel()->select(proxymodel->index(model->rowCount() - 1, 0), QItemSelectionModel::Select);
    insert->hide();
    view->show();
    searchbar->show();

}
void MainWindow::showInsert(){
    view->hide();
    searchbar->hide();
    insert->show();

}
void MainWindow::closeRequest()
{
    QMessageBox dialog;
    QPushButton* saveButton=dialog.addButton("Salva",QMessageBox::ActionRole);
    QPushButton* exitButton=dialog.addButton("Esci senza salvare",QMessageBox::ActionRole);
    QPushButton* cancelButton=dialog.addButton("Annulla",QMessageBox::ActionRole);
    dialog.setText("Il documento non e' salvato.");
    dialog.setInformativeText("Vuoi effettuare un salvataggio?");
    dialog.setDefaultButton(saveButton);
    dialog.exec();
    if(dialog.clickedButton()==saveButton){
        this->close();
    }else if(dialog.clickedButton()==exitButton){
        this->close();
    }else if(dialog.clickedButton()==cancelButton){
        dialog.close();
    }
}

void MainWindow::clearSearchBar()
{
    searchbar->setText("");
}
