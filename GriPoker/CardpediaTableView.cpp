#include "CardpediaTableView.h"

#include "CardpediaTableModel.h"

#include <QHeaderView>
#include <QDragEnterEvent>

#include <iostream>

CardpediaTableView::CardpediaTableView(QWidget * a_parentWidget)
    : QTableView(a_parentWidget)
{
    setModel(new CardpediaTableModel());

    horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    verticalHeader()->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader()->setDefaultSectionSize(35);

    setDragEnabled(true);
}

CardpediaTableView::~CardpediaTableView()
{

}

