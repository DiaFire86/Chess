#include "stdafx.h"
#include "queen.h"

// Adresses à ajuster pour le moment
const QString Queen::WHITE_QUEEN_IMAGE_URL = "./Images/queen_w.png";
const QString Queen::BLACK_QUEEN_IMAGE_URL = "./Images/queen_b.png";

Queen::Queen(int yCoord, int xCoord, Color color) : ChessPiece(getImageUrl(color), yCoord, xCoord, color, QUEEN), _color(color), _xCoord(xCoord), _yCoord(yCoord) {}

QPixmap Queen::getImageUrl(Color color)
{
    QPixmap pixmap((color == WHITE) ? WHITE_QUEEN_IMAGE_URL : BLACK_QUEEN_IMAGE_URL);
    return pixmap;
}

void Queen::changeCoord(int yCoord, int xCoord)
{
    _yCoord = yCoord;
    _xCoord = xCoord;
}

QList<QPointF> Queen::possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const
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
                canMooveRight = false;
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

    // Déplacement Haut-Droite
    bool canMooveUpRight = true;
    cpt = 1;
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
        if ((_yCoord + cpt <= 7) && (_xCoord - cpt >= 0))
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