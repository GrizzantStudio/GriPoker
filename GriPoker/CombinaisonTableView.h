#ifndef COMBINAISONTABLEVIEW_H
#define COMBINAISONTABLEVIEW_H

#include <QTableView>

class QWidget;

class CombinaisonTableView : public QTableView
{
public:
    CombinaisonTableView(QWidget * a_parentWidget);
    ~CombinaisonTableView();
};

#endif // COMBINAISONTABLEVIEW_H
