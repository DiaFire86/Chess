#include "stdafx.h"
#include "display.h"

void Display::DisplayPossibleMoves(QGraphicsScene* scene, Chess::ChessBoard* board, QList<QPointF> moves)
{
    int cellSize = board->getCellSize();
    foreach(QPointF pos, moves)
    {
        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem((pos.x() * cellSize) + (cellSize / 4), (pos.y() * cellSize) + (cellSize / 4), cellSize / 2, cellSize / 2);
        ellipse->setPen(QPen(Qt::black));
        ellipse->setBrush(QBrush(Qt::black));
        board->tempPossibleMoves.append(ellipse);
        scene->addItem(ellipse);
        scene->update();
    }
}

void Display::ErasePossibleMoves(QGraphicsScene* scene, QList<QGraphicsEllipseItem*>* tempPossibleMoves)
{
    for (QGraphicsEllipseItem* ellipse : *tempPossibleMoves)
    {
        scene->removeItem(ellipse);
        delete ellipse;
    }
    tempPossibleMoves->clear();
}

void Display::kingInCheck()
{
    QLabel* messageLabel = new QLabel();
    messageLabel->setFixedSize(400, 50);
    messageLabel->setText("Coup invalide, votre roi est en echec !");
    messageLabel->setStyleSheet("color: red; font-weight: bold;");
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->show();
}

void Display::WhiteKingInCheckMate()
{
    QLabel* messageLabel = new QLabel();
    messageLabel->setFixedSize(400, 50);
    messageLabel->setText("Le roi blanc est en echec et mat !\nVictoire des noirs !");
    messageLabel->setStyleSheet("color: red; font-weight: bold;");
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->show();
}

void Display::BlackKingInCheckMate()
{
    QLabel* messageLabel = new QLabel();
    messageLabel->setFixedSize(400, 50);
    messageLabel->setText("Le roi noir est en echec et mat !\nVictoire des blancs !");
    messageLabel->setStyleSheet("color: red; font-weight: bold;");
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->show();
}