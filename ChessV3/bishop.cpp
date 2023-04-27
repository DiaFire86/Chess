#include "stdafx.h"
#include "bishop.h"

// Adresses à ajuster pour le moment
const QString Bishop::WHITE_BISHOP_IMAGE_URL = "./Images/bishop_w.png";
const QString Bishop::BLACK_BISHOP_IMAGE_URL = "./Images/bishop_b.png";

Bishop::Bishop(int yCoord, int xCoord, Color color) : ChessPiece(getImageUrl(color), yCoord, xCoord, color, BISHOP), _color(color), _xCoord(xCoord), _yCoord(yCoord) {}

QPixmap Bishop::getImageUrl(Color color)
{
    QPixmap pixmap((color == WHITE) ? WHITE_BISHOP_IMAGE_URL : BLACK_BISHOP_IMAGE_URL);
    return pixmap;
}

void Bishop::changeCoord(int yCoord, int xCoord)
{
    _yCoord = yCoord;
    _xCoord = xCoord;
}

QList<QPointF> Bishop::possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const
{
    QList<QPointF> moves;

    // Déplacement Haut-Droite
    bool canMooveUpRight = true;
    int cpt = 1;
    while (canMooveUpRight)
    {
        if ((_yCoord - cpt >= 0) && (_xCoord + cpt <= 7))
        {
            if (board[_xCoord + cpt][_yCoord - cpt] == nullptr)
            {
                moves.append(QPointF(_xCoord + cpt, _yCoord - cpt));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + cpt][_yCoord - cpt])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord + cpt, _yCoord - cpt));
                canMooveUpRight = false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + cpt][_yCoord - cpt])->getColor() == _color)
            {
                canMooveUpRight = false;
            }
        }
        else
        {
            canMooveUpRight = false;
        }
    }

    // Déplacement Bas-Droite
    bool canMooveDownRight = true;
    cpt = 1;
    while (canMooveDownRight)
    {
        if ((_yCoord + cpt <= 7) && (_xCoord + cpt <= 7))
        {
            if (board[_xCoord + cpt][_yCoord + cpt] == nullptr)
            {
                moves.append(QPointF(_xCoord + cpt, _yCoord + cpt));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + cpt][_yCoord + cpt])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord + cpt, _yCoord + cpt));
                canMooveDownRight = false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + cpt][_yCoord + cpt])->getColor() == _color)
            {
                canMooveDownRight = false;
            }
        }
        else
        {
            canMooveDownRight = false;
        }
    }

    // Déplacement Bas-Gauche
    bool canMooveDownLeft = true;
    cpt = 1;
    while (canMooveDownLeft)
    {
        if ((_yCoord + cpt <= 7 ) && (_xCoord - cpt >= 0))
        {
            if (board[_xCoord - cpt][_yCoord + cpt] == nullptr)
            {
                moves.append(QPointF(_xCoord - cpt, _yCoord + cpt));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - cpt][_yCoord + cpt])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord - cpt, _yCoord + cpt));
                canMooveDownLeft = false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - cpt][_yCoord + cpt])->getColor() == _color)
            {
                canMooveDownLeft = false;
            }

        }
        else
        {
            canMooveDownLeft = false;
        }
    }

    // Déplacement Haut-Gauche
    bool canMooveUpLeft = true;
    cpt = 1;
    while (canMooveUpLeft)
    {
        if ((_yCoord - cpt >= 0) && (_xCoord - cpt >= 0))
        {
            if (board[_xCoord - cpt][_yCoord - cpt] == nullptr)
            {
                moves.append(QPointF(_xCoord - cpt, _yCoord - cpt));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - cpt][_yCoord - cpt])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord - cpt, _yCoord - cpt));
                canMooveUpLeft = false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - cpt][_yCoord - cpt])->getColor() == _color)
            {
                canMooveUpLeft = false;
            }

        }
        else
        {
            canMooveUpLeft = false;
        }
    }

    return moves;
}