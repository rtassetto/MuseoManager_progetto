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
    return 5;
}

QVariant QTableModel::data(const QModelIndex & index, int n) const
{
    if (!index.isValid() || index.row() >= model->getDataSize() || index.row()<0)
        return QVariant();
    switch(n){
    case Qt::BackgroundColorRole:
        return QVariant(QBrush(QColor(Qt::blue)));
    case Qt::TextAlignmentRole:
        return QVariant ( Qt::AlignVCenter | Qt::AlignHCenter );
    case Qt::SizeHintRole:
        return QSize( 500, 0 );
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

void QTableModel::removeRows(int row, int count, const QModelIndex &parent)
{

}

QVariant QTableModel::headerData(int section, Qt::Orientation orientation, int n) const
{
    if (n != Qt::DisplayRole)
        return QVariant();
    if(n==Qt::FontRole)
    {
        return QFont("Times", 20, QFont::Bold);
    }
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Nome");
        case 1:
            return QString("Autore");
        case 2:
            return QString("Data Scoperta");
        case 3:
            return QString("Descrizione");
        case 4:
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
    std::string tipo = insert->getTipo();
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

