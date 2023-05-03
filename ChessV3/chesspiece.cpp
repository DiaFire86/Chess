#include "stdafx.h"
#include "chesspiece.h"

namespace Piece {
    ChessPiece::ChessPiece(QPixmap pixmap, int yCoord = 0, int xCoord = 0, Color color = WHITE, TypePiece type = PAWN) : QGraphicsPixmapItem(pixmap)
    {
        _type = type;
        _color = color;
        _yCoord = yCoord;
        _xCoord = xCoord;
        setPos(_xCoord * 90, _yCoord * 90);
    }

    ChessPiece::~ChessPiece() {}

    bool ChessPiece::isKingInCheck(QGraphicsPixmapItem* (&board)[8][8])
    {
        // Verifie tous les mouvements des pieces de la couleur opposé
        QList<QPointF> opponentMoves;
        int xKing;
        int yKing;
        for (int column = 0; column < 8; column++)
        {
            for (int row = 0; row < 8; row++)
            {
                ChessPiece* piece = dynamic_cast<ChessPiece*>(board[column][row]);
                if (piece != nullptr && piece->getColor() != _color)
                {
                    QList<QPointF> pieceMoves = piece->possibleMoves(board, piece, QPointF(row, column));
                    opponentMoves.append(pieceMoves);
                }
                else if (piece != nullptr && piece->_type == KING && piece->getColor() == _color)
                {
                    xKing = column;
                    yKing = row;
                }
            }
        }

        // Verifie si un de ces mouvements mettrait le roi en echec
        for (int moves = 0; moves < opponentMoves.size(); moves++)
        {
            QPointF move = opponentMoves.at(moves);
            if (move.x() == xKing && move.y() == yKing)
            {
                return true; // Le roi est en echec
            }
        }
        return false; // Le roi n'est pas en echec
    }
}