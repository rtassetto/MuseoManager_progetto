#include "qtablemodel.h"

QTableModel::QTableModel(QObject * parent, InsertItem * ins):QAbstractTableModel(parent),insert(ins), model(new Modello())
{

}

QTableModel::~QTableModel()
{
    if(model) delete model;
}

int QTableModel::rowCount(const QModelIndex & ) const
{
    return model->getDataSize();

}

int QTableModel::columnCount(const QModelIndex & ) const
{
    return 6;
}

QVariant QTableModel::data(const QModelIndex & index, int n) const
{
    if (!index.isValid() || index.row() >= static_cast<int>(model->getDataSize()) || index.row()<0)
        return QVariant();
    switch(n){
    case Qt::BackgroundColorRole:
        return QVariant(QBrush(QColor(Qt::gray)));
    case Qt::TextAlignmentRole:
        return QVariant ( Qt::AlignVCenter | Qt::AlignHCenter );
    case Qt::SizeHintRole:
        return QSize( 700, 0 );
    case Qt::EditRole:
    case Qt::DisplayRole:
    {
        switch(index.column())
        {
        case 0:
            return index.row()+1;
        case 1:
            return QString::fromStdString((model->position(index.row()))->getNome());
        case 2:
            return QString::fromStdString((model->position(index.row()))->getAutore());
        case 3:
            return (model->position(index.row()))->getData();
        case 4:
            return QString::fromStdString((model->position(index.row()))->getDescrizione());
        case 5:
            return QString::fromStdString((model->position(index.row()))->getTipo());
        default:
            return QVariant();
        }
    }
    default:    return QVariant();
    }
}

bool QTableModel::setData(const QModelIndex & index, const QVariant & val, int role)
{
    if (!index.isValid() && role != Qt::EditRole)
        return false;
    switch(index.column())
    {
    case 1:
        model->position(static_cast<unsigned int>(index.row()))->setNome(val.toString().toStdString()); break;
    case 2:
        model->position(static_cast<unsigned int>(index.row()))->setAutore(val.toString().toStdString()); break;
    }
    emit dataChanged(index, index);
    return true;
}

bool QTableModel::removeRows(int row, int count, const QModelIndex &)
{
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (int i = 0; i < count; ++i)
    {
        model->erase(i);
    }
    endRemoveRows();
    return true;
}

Qt::ItemFlags QTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    if(index.column()==0 || index.column()==4)
        return QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

void QTableModel::save(const std::string &file) const
{
    model->save(file);
}

void QTableModel::load(const std::string &file) const
{
    model->load(file);
}

QVariant QTableModel::headerData(int section, Qt::Orientation orientation, int n) const
{
    if (n != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 1:
            return QString("Nome");
        case 2:
            return QString("Autore");
        case 3:
            return QString("Data Scoperta");
        case 4:
            return QString("Descrizione");
        case 5:
            return QString("Tipo");
        default:
            return QVariant();
        }
    }
    return QVariant();
}


bool QTableModel::insertRows(int begin, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, begin, begin + count - 1);
    string tipo = insert->getTipo();
    if(tipo=="Libro"){
        model->push_end(new BookItem(insert->getNome(),insert->getAutore(),insert->getDescrizione(),insert->getData(),insert->getDataLibro(),insert->getPrefazione(),insert->getCopertina()));
    } else if (tipo=="Lettera"){
        model->push_end(new LetterItem(insert->getNome(),insert->getAutore(),insert->getDescrizione(),insert->getData(),insert->getDataLettera(),insert->getDestinatario(),insert->getTesto()));
    } else if (tipo=="Magazine"){
       model->push_end(new MagazineItem(insert->getNome(),insert->getAutore(),insert->getDescrizione(),insert->getData(),insert->getDataMagazine(),insert->getPrimaPagina(),model->getEnumM(insert->getCatM())));
    } else if (tipo=="Statua"){
        model->push_end(new StatueItem(insert->getNome(),insert->getAutore(),insert->getDescrizione(),insert->getData(),model->getEnumS(insert->getCatS()),insert->getSoggettoS(),insert->getMateriale(),insert->getFotoS()));
    }else if (tipo=="Pittura"){
        model->push_end(new PictureItem(insert->getNome(),insert->getAutore(),insert->getDescrizione(),insert->getData(),model->getEnumP(insert->getCatP()),insert->getSoggettoP(),insert->getMovimento(),insert->getFotoP()));
    }
    endInsertRows();
    return true;
}

bool QTableModel::searchMatch(unsigned int r, const QRegExp& s, const QString& a) const{
    if(a=="Tipo")
        return QString::fromStdString(model->position(r)->getTipo()).contains(s);
    else if(a=="Nome")
        return QString::fromStdString(model->position(r)->getNome()).contains(s);
    else if(a=="Autore")
        return QString::fromStdString(model->position(r)->getAutore()).contains(s);
    else
        return false;
}

bool QTableModel::getSaved() const
{
    return model->getSaved();
}

void QTableModel::showView(const QModelIndex & i) const {
    if (i.isValid() && (i.row()) < rowCount() && i.column()<columnCount()){
        ItemView* item = new ItemView(model->position(static_cast<unsigned int>(i.row())), QAbstractTableModel::createIndex(i.row(), 0), QAbstractTableModel::createIndex(i.row(), columnCount()-1));
        connect(item, SIGNAL(dataChanged(QModelIndex, QModelIndex)), this, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)));
        item->setAttribute(Qt::WA_DeleteOnClose); //item viene distrutto alla sua chiusura
        item->show();
    }
}
