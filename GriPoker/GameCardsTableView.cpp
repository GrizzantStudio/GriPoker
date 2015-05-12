#include "GameCardsTableView.h"

#include "GameCardsTableModel.h"

#include <QHeaderView>
#include <QDragEnterEvent>
#include <QMimeData>

#include <iostream>

GameCardsTableView::GameCardsTableView(QWidget * a_parentWidget)
    : QTableView(a_parentWidget)
{
    setModel(new GameCardsTableModel());

    horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);

    verticalHeader()->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader()->setDefaultSectionSize(33);

    setFixedHeight(35 + horizontalHeader()->height());

    setAcceptDrops(true);
    setDropIndicatorShown(true);
}

GameCardsTableView::~GameCardsTableView()
{

}

