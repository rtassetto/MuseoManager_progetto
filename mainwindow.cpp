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

MainWindow::MainWindow(QWidget *parent, bool toLoad)
    : QWidget(parent),search(new SearchView(this)),insert(new InsertItem(this)),
      view(new TableView(this))
{
    insert->hide();
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setFixedSize(QSize(550,600));
    setWindowIcon(QIcon(":/data/images/icon.png"));



    proxymodel = new QProxyModel(this, search->getType());
    model = new QTableModel(this, insert);
    if(toLoad) load();
    proxymodel->setSourceModel(model);
    view->setModel(proxymodel);


    // MENÙ e MENUBAR
    QMenuBar* menuBar = new QMenuBar();
    QMenu* menuFile = new QMenu("File", menuBar);
    QMenu* menuAdd = new QMenu("Aggiungi", menuBar);
    QAction* addItemAction = new QAction("Inserisci nuovo", menuAdd);
    QAction* loadAction=new QAction("Carica", menuFile);
    QAction* saveAction = new QAction("Salva", menuFile);
    QAction* exitAction = new QAction("Esci", menuFile);

    // Setup del menù
    menuBar->addMenu(menuFile);
    menuBar->addMenu(menuAdd);
    menuAdd->addAction(addItemAction);
    menuFile->addAction(loadAction);
    menuFile->addAction(saveAction);
    menuFile->addAction(exitAction);

    // LAYOUT
    QVBoxLayout* mainLayout = new QVBoxLayout(this);


    // Setup Main layout
    mainLayout->addWidget(menuBar);
    mainLayout->addWidget(search);
    mainLayout->addWidget(view,0);
    mainLayout->addWidget(insert);


    connect(loadAction,SIGNAL(triggered(bool)),this,SLOT(load()));
    connect(saveAction,SIGNAL(triggered(bool)),this,SLOT(save()));
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(closeRequest()));
    connect(insert, SIGNAL(inserito()), this, SLOT(addItem()));
    connect(insert, SIGNAL(noInsert()), this, SLOT(showMain()));
    connect(addItemAction,SIGNAL(triggered()),this,SLOT(showInsert()));


    connect(search->getSearchbar(), SIGNAL(textChanged(const QString&)), this, SLOT(searchTextChanged()));
    connect(search->getType(), SIGNAL(currentTextChanged(const QString&)), this, SLOT(searchTextChanged()));

}



void MainWindow::addItem() const
{

    proxymodel->insertRows(proxymodel->rowCount(), 1);
    view->clearSelection();
    view->selectionModel()->clearCurrentIndex();
    view->selectionModel()->select(proxymodel->index(model->rowCount() - 1, 0), QItemSelectionModel::Select);
    insert->hide();
    view->show();
    search->show();

}
void MainWindow::showInsert(){
    view->hide();
    search->hide();
    insert->show();

}

void MainWindow::showMain(){
    view->show();
    search->show();
    insert->hide();
}

void MainWindow::save()
{
    if(!file.isEmpty())
    {
        model->save(file.toStdString());
    }else{
        file=QFileDialog::getSaveFileName(this,tr("Salva"), "",tr("XML (*.xml);;All Files (*)"));
        model->save(file.toStdString());
    }
}

void MainWindow::load()
{
    file= QFileDialog::getOpenFileName(this,tr("Carica"), "",tr("XML (*.xml);;All Files (*)"));
    if(!file.isEmpty()){
        setWindowTitle(QFileInfo(file).fileName() + tr("/ MuseoManager"));
        model->load(file.toStdString());
    }
}

void MainWindow::searchTextChanged()
{
    QRegExp expr(search->getSearchbar()->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxymodel->setFilterRegExp(expr);
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


