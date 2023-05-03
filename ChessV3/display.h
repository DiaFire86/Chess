#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsView>
#include "chessboard.h"
#include "chesspiece.h"

class Display
{
public:
	Display() {}

	void DisplayPossibleMoves(QGraphicsScene* scene, Chess::ChessBoard* board, QList<QPointF> moves);
	void ErasePossibleMoves(QGraphicsScene* scene, QList<QGraphicsEllipseItem*>* tempPossibleMoves);
	void kingInCheck();
	void WhiteKingInCheckMate();
	void BlackKingInCheckMate();

	~Display() {}
private:
};