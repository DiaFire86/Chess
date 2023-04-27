#include "stdafx.h"
#include "knight.h"

// Adresses à ajuster pour le moment
const QString Knight::WHITE_KNIGHT_IMAGE_URL = "./Images/knight_w.png";
const QString Knight::BLACK_KNIGHT_IMAGE_URL = "./Images/knight_b.png";

Knight::Knight(int yCoord, int xCoord, Color color) : ChessPiece(getImageUrl(color), yCoord, xCoord, color, KNIGHT), _color(color), _xCoord(xCoord), _yCoord(yCoord) {}

QPixmap Knight::getImageUrl(Color color)
{
    QPixmap pixmap((color == WHITE) ? WHITE_KNIGHT_IMAGE_URL : BLACK_KNIGHT_IMAGE_URL);
    return pixmap;
}

void Knight::changeCoord(int yCoord, int xCoord)
{
    _yCoord = yCoord;
    _xCoord = xCoord;
}

QList<QPointF> Knight::possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const
{
    QList<QPointF> moves;

    // Haut-Gauche
    if ((_xCoord - 1) >= 0 && (_yCoord - 2 >= 0) && (_xCoord - 1) <= 7 && (_yCoord - 2 <= 7))
    {
        QPointF upLeft(_xCoord - 1, _yCoord - 2);
        if (board[_xCoord - 1][_yCoord - 2] == nullptr)
        {
            moves.append(upLeft);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord - 1][_yCoord - 2])->getColor() != _color)
        {
            moves.append(upLeft);
        }
    }

    // Haut-Droite
    if ((_xCoord + 1) >= 0 && (_yCoord - 2 >= 0) && (_xCoord + 1) <= 7 && (_yCoord - 2 <= 7))
    {
        QPointF upRight(_xCoord + 1, _yCoord - 2);
        if (board[_xCoord + 1][_yCoord - 2] == nullptr)
        {
            moves.append(upRight);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord + 1][_yCoord - 2])->getColor() != _color)
        {
            moves.append(upRight);
        }
    }

    // Droite-Haut
    if ((_xCoord + 2) >= 0 && (_yCoord - 1 >= 0) && (_xCoord + 2) <= 7 && (_yCoord - 1 <= 7))
    {
        QPointF rightUp(_xCoord + 2, _yCoord - 1);
        if (board[_xCoord + 2][_yCoord - 1] == nullptr)
        {
            moves.append(rightUp);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord + 2][_yCoord - 1])->getColor() != _color)
        {
            moves.append(rightUp);
        }
    }

    // Droite-Bas
    if ((_xCoord + 2) >= 0 && (_yCoord + 1 >= 0) && (_xCoord + 2) <= 7 && (_yCoord + 1 <= 7))
    {
        QPointF rightDown(_xCoord + 2, _yCoord + 1);
        if (board[_xCoord + 2][_yCoord + 1] == nullptr)
        {
            moves.append(rightDown);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord + 2][_yCoord + 1])->getColor() != _color)
        {
            moves.append(rightDown);
        }
    }

    // Bas-Droite
    if ((_xCoord + 1) >= 0 && (_yCoord + 2 >= 0) && (_xCoord + 1) <= 7 && (_yCoord + 2 <= 7))
    {
        QPointF downRight(_xCoord + 1, _yCoord + 2);
        if (board[_xCoord + 1][_yCoord + 2] == nullptr)
        {
            moves.append(downRight);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord + 1][_yCoord + 2])->getColor() != _color)
        {
            moves.append(downRight);
        }
    }

    // Bas-Gauche
    if ((_xCoord - 1) >= 0 && (_yCoord + 2 >= 0) && (_xCoord - 1) <= 7 && (_yCoord + 2 <= 7))
    {
        QPointF downLeft(_xCoord - 1, _yCoord + 2);
        if (board[_xCoord - 1][_yCoord + 2] == nullptr)
        {
            moves.append(downLeft);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord - 1][_yCoord + 2])->getColor() != _color)
        {
            moves.append(downLeft);
        }
    }

    // Gauche-Bas
    if ((_xCoord - 2) >= 0 && (_yCoord + 1 >= 0) && (_xCoord - 2) <= 7 && (_yCoord + 1 <= 7))
    {
        QPointF leftDown(_xCoord - 2, _yCoord + 1);
        if (board[_xCoord - 2][_yCoord + 1] == nullptr)
        {
            moves.append(leftDown);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord - 2][_yCoord + 1])->getColor() != _color)
        {
            moves.append(leftDown);
        }
    }

    // Gauche-Haut
    if ((_xCoord - 2) >= 0 && (_yCoord - 1 >= 0) && (_xCoord - 2) <= 7 && (_yCoord - 1 <= 7))
    {
        QPointF leftUp(_xCoord - 2, _yCoord - 1);
        if (board[_xCoord - 2][_yCoord - 1] == nullptr)
        {
            moves.append(leftUp);
        }
        // Prise
        else if (dynamic_cast<ChessPiece*>(board[_xCoord - 2][_yCoord - 1])->getColor() != _color)
        {
            moves.append(leftUp);
        }
    }

    return moves;
}