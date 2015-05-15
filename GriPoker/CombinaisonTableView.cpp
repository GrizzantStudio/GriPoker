#include "CombinaisonTableView.h"
#include <CombinaisonTableModel.h>
#include <QHeaderView>
#include <HierarchicalHeaderView.h>

CombinaisonTableView::CombinaisonTableView(QWidget * a_parentWidget)
    : QTableView(a_parentWidget)
{
    HierarchicalHeaderView * hv =new HierarchicalHeaderView(Qt::Horizontal, this);
    hv->setHighlightSections(true);
    hv->setSectionsClickable(true);
    setHorizontalHeader(hv);

    CombinaisonTableModel * model = new CombinaisonTableModel();
    setModel(model);

    for(int col = 0; col < model->columnCount(); ++ col)
        setColumnWidth(col, 50);

    setAlternatingRowColors(true);
    resizeRowsToContents();
}

CombinaisonTableView::~CombinaisonTableView()
{

}

