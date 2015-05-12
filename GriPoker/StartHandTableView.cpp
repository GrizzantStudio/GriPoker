#include "StartHandTableView.h"

#include <StartHandTableModel.h>
#include <QHeaderView>

StartHandTableView::StartHandTableView(QWidget * a_parentWidget)
    : QTableView(a_parentWidget)
{
    setModel(new StartHandTableModel());
    horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(9, QHeaderView::ResizeToContents);

    verticalHeader()->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader()->setDefaultSectionSize(33);
}

StartHandTableView::~StartHandTableView()
{

}

