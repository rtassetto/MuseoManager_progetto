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

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),searchbar(new QLineEdit(this)),insert(new InsertItem(this)),
      view(new TableView(this))
{
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setFixedSize(QSize(800,600));
    setWindowIcon(QIcon(":/data/images/icon.png"));

    //Pulsanti
    QPushButton* clearSearchButton = new QPushButton("X", this);

    // Dà un nome al pulsante per usarlo nel css
    clearSearchButton->setObjectName("clearbutton");
    clearSearchButton->setToolTip("Pulisci ricerca");

    // MENÙ e MENUBAR
    QMenuBar* menuBar = new QMenuBar();
    QMenu* menu = new QMenu("File", menuBar);
    QAction* saveAction = new QAction("Salva", menu);
    QAction* exitAction = new QAction("Esci", menu);

    // Setup del menù
    menuBar->addMenu(menu);
    menu->addAction(saveAction);
    menu->addAction(exitAction);

    // LAYOUT
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Searchbar sottolayout
    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchbar);
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
    /*connect(addDocAction,SIGNAL(triggered()),insert,SLOT(docView()));
    connect(addStatueAction,SIGNAL(triggered()),insert,SLOT(statueView()));
    connect(addPicAction,SIGNAL(triggered()),insert,SLOT(pictureView()));*/
    //connect(insert, SIGNAL(inserito()), this, SLOT(addItem()));

}

MainWindow::~MainWindow()
{

}


void MainWindow::addItem() const
{


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
