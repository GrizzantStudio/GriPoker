#ifndef CARDPEDIATABLEVIEW_H
#define CARDPEDIATABLEVIEW_H

#include <QTableView>

class CardpediaTableView : public QTableView
{
private :

    QModelIndex m_dragStartIndex;

public:
    CardpediaTableView(QWidget * a_parentWidget);
    ~CardpediaTableView();
};

#endif // CARDPEDIATABLEVIEW_H
