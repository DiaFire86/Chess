#include "stdafx.h"
#include "rook.h"

// Adresses à ajuster pour le moment
const QString Rook::WHITE_ROOK_IMAGE_URL = "./Images/rook_w.png";
const QString Rook::BLACK_ROOK_IMAGE_URL = "./Images/rook_b.png";

Rook::Rook(int yCoord, int xCoord, Color color) : ChessPiece(getImageUrl(color), yCoord, xCoord, color, ROOK), _color(color), _xCoord(xCoord), _yCoord(yCoord) {}

QPixmap Rook::getImageUrl(Color color)
{
    QPixmap pixmap((color == WHITE) ? WHITE_ROOK_IMAGE_URL : BLACK_ROOK_IMAGE_URL);
    return pixmap;
}

void Rook::changeCoord(int yCoord, int xCoord)
{
    _yCoord = yCoord;
    _xCoord = xCoord;
}

QList<QPointF> Rook::possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const
{
    QList<QPointF> moves;

    // Déplacement Haut
    bool canMooveUp = true;
    int cpt = 1;
    while (canMooveUp)
    {
        if (_yCoord - cpt >= 0)
        {
            if (board[_xCoord][_yCoord - cpt] == nullptr)
            {
                moves.append(QPointF(_xCoord, _yCoord - cpt));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord][_yCoord - cpt])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord, _yCoord - cpt));
                canMooveUp = false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord][_yCoord - cpt])->getColor() == _color)
            {
                canMooveUp = false;
            }
        }
        else
        {
            canMooveUp = false;
        }
    }

    // Déplacement Bas
    bool canMooveDown = true;
    cpt = 1;
    while (canMooveDown)
    {
        if (_yCoord + cpt <= 7)
        {
            if (board[_xCoord][_yCoord + cpt] == nullptr)
            {
                moves.append(QPointF(_xCoord, _yCoord + cpt));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord][_yCoord + cpt])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord, _yCoord + cpt));
                canMooveDown = false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord][_yCoord + cpt])->getColor() == _color)
            {
                canMooveDown = false;
            }
        }
        else
        {
            canMooveDown = false;
        }
    }

    // Déplacement Droite
    bool canMooveRight = true;
    cpt = 1;
    while (canMooveRight)
    {
        if (_xCoord + cpt <= 7)
        {
            if (board[_xCoord + cpt][_yCoord] == nullptr)
            {
                moves.append(QPointF(_xCoord + cpt, _yCoord));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + cpt][_yCoord])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord + cpt, _yCoord));
                canMooveRight= false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + cpt][_yCoord])->getColor() == _color)
            {
                canMooveRight = false;
            }

        }
        else
        {
            canMooveRight = false;
        }
    }

    // Déplacement Gauche
    bool canMooveLeft = true;
    cpt = 1;
    while (canMooveLeft)
    {
        if (_xCoord - cpt >= 0)
        {
            if (board[_xCoord - cpt][_yCoord] == nullptr)
            {
                moves.append(QPointF(_xCoord - cpt, _yCoord));
                cpt++;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - cpt][_yCoord])->getColor() != _color)
            {
                moves.append(QPointF(_xCoord - cpt, _yCoord));
                canMooveLeft = false;
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - cpt][_yCoord])->getColor() == _color)
            {
                canMooveLeft = false;
            }

        }
        else
        {
            canMooveLeft = false;
        }
    }

    return moves;
}
