#include "stdafx.h"
#include "pawn.h"

// Adresses à ajuster pour le moment
const QString Pawn::WHITE_PAWN_IMAGE_URL = "./Images/pawn_w.png";
const QString Pawn::BLACK_PAWN_IMAGE_URL = "./Images/pawn_b.png";

Pawn::Pawn(int yCoord, int xCoord, Color color) : ChessPiece(getImageUrl(color), yCoord, xCoord, color, PAWN), _color(color), _yCoord(yCoord), _xCoord(xCoord) {}

void Pawn::changeCoord(int yCoord, int xCoord)
{
    _yCoord = yCoord;
    _xCoord = xCoord;
} 

QPixmap Pawn::getImageUrl(Color color)
{
    QPixmap pixmap((color == WHITE) ? WHITE_PAWN_IMAGE_URL : BLACK_PAWN_IMAGE_URL);
    return pixmap;
}

QList<QPointF> Pawn::possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const
{
    QList<QPointF> moves;

    int direction = (_color == WHITE) ? 1 : -1;

    // Avancement d'une case
    if (_yCoord + direction >= 0 && _yCoord + direction <= 7)
    {
        if (board[_xCoord][_yCoord + direction] == nullptr)
        {
            moves.append(QPointF(_xCoord, _yCoord + direction));
        }
    }
    
    // Avancement de deux cases
    if (_yCoord + 2 * direction >= 0 && _yCoord + 2 * direction <= 7)
    {
        if (board[_xCoord][_yCoord + direction] == nullptr && board[_xCoord][_yCoord + 2 * direction] == nullptr && ((_color == WHITE && _yCoord == 1) || (_color == BLACK && _yCoord == 6)))
        {
            moves.append(QPointF(_xCoord, _yCoord + 2 * direction));
        }
    }

    // Prise à gauche
    if (_xCoord != 0 && _yCoord + direction >= 0 && _yCoord + direction <= 7)
    {
        if (board[_xCoord - 1][_yCoord + direction] != nullptr)
        {
            if (dynamic_cast<ChessPiece*>(board[_xCoord - 1][_yCoord + direction])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord - 1, _yCoord + direction));
            }
        }
    }

    // Prise à droite
    if (_xCoord != 7 && _yCoord + direction >= 0 && _yCoord + direction <= 7)
    {
        if (board[_xCoord + 1][_yCoord + direction] != nullptr)
        {
            if (dynamic_cast<ChessPiece*>(board[_xCoord + 1][_yCoord + direction])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord + 1, _yCoord + direction));
            }
        }
    }

    return moves;
}