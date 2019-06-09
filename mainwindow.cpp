#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QLineEdit>
#include <insertitem.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),searchbar(new QLineEdit(this)),insert(new InsertItem(this)),
      view(new TableView(this))
{
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setFixedSize(QSize(500,550));
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
    QAction* exitAction = new QAction("Esci", menu); //aggiungere controllo, quando clicco per uscire controllare se non ho salvato mi chiede di salvare
    QMenu* add = new QMenu("Aggiungi", menuBar);
    QAction* addStatueAction= new QAction("Nuova statua", add);
    QAction* addDocAction= new QAction("Nuovo documento", add);
    QAction* addPicAction= new QAction("Nuovo dipinto", add);

    // Setup del menù
    menuBar->addMenu(menu);
    menu->addAction(saveAction);
    menu->addAction(exitAction);
    menuBar->addMenu(add);
    add->addAction(addStatueAction);
    add->addAction(addDocAction);
    add->addAction(addPicAction);

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
