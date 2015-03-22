#include "UpgradeProbaTableView.h"

#include "UpgradeProbaTableModel.h"

#include <QHeaderView>

UpgradeProbaTableView::UpgradeProbaTableView(QWidget * a_parentWidget)
    : QTableView(a_parentWidget)
{
    setModel(new UpgradeProbaTableModel());
    horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
}

UpgradeProbaTableView::~UpgradeProbaTableView()
{

}

