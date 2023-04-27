#include "stdafx.h"
#include "king.h"

// Adresses à ajuster pour le moment
const QString King::WHITE_KING_IMAGE_URL = "./Images/king_w.png";
const QString King::BLACK_KING_IMAGE_URL = "./Images/king_b.png";

int King::_kingCounter = 0;

King::King(int yCoord, int xCoord, Color color) : ChessPiece(getImageUrl(color), yCoord, xCoord, color, KING), _color(color), _xCoord(xCoord), _yCoord(yCoord) 
{ 
    ++_kingCounter; 
    try 
    {
        kingCounted();
    }
    catch (std::runtime_error& e) 
    {   
        QLabel* messageLabel = new QLabel();
        messageLabel->setFixedSize(400, 50);
        
        messageLabel->setText(e.what());
        messageLabel->setStyleSheet("color: red; font-weight: bold;");
        messageLabel->setAlignment(Qt::AlignCenter);
        messageLabel->show();
    }
}

int King::kingCounted()
{
    if (_kingCounter > 4)
    {
        throw std::runtime_error("Il ne peut pas avoir plus de 2 rois sur le jeu a la fois !");
    }
}

QPixmap King::getImageUrl(Color color)
{
    QPixmap pixmap((color == WHITE) ? WHITE_KING_IMAGE_URL : BLACK_KING_IMAGE_URL);
    return pixmap;
}

void King::changeCoord(int yCoord, int xCoord)
{
    _yCoord = yCoord;
    _xCoord = xCoord;
}

QList<QPointF> King::possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const
{
    QList<QPointF> moves;

    // Haut, Haut-Droite, Haut-Gauche
    if (_yCoord - 1 >= 0)
    {
        // Haut
        QPointF up(_xCoord, _yCoord - 1);
        if (board[_xCoord][_yCoord - 1] == nullptr)
        {
            moves.append(up);
        }
        else if (dynamic_cast<ChessPiece*>(board[_xCoord][_yCoord - 1])->getColor() != _color)
        {
            moves.append(up);
        }

        // Haut-Droite
        if (_xCoord + 1 <= 7)
        {
            QPointF upRight(_xCoord + 1, _yCoord - 1);
            if (board[_xCoord + 1][_yCoord - 1] == nullptr)
            {
                moves.append(upRight);
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + 1][_yCoord - 1])->getColor() != _color)
            {
                moves.append(upRight);
            }

        }

        // Haut-Gauche
        if (_xCoord - 1 >= 0)
        {
            QPointF upLeft(_xCoord - 1, _yCoord - 1);
            if (board[_xCoord - 1][_yCoord - 1] == nullptr)
            {
                moves.append(upLeft);
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - 1][_yCoord - 1])->getColor() != _color)
            {
                moves.append(upLeft);
            }
        }
    }

    // Bas, Bas-Droite, Bas-Gauche
    if (_yCoord + 1 <= 7)
    {
        // Bas
        QPointF down(_xCoord, _yCoord + 1);
        if (board[_xCoord][_yCoord + 1] == nullptr)
        {
            moves.append(down);
        }
        else if (dynamic_cast<ChessPiece*>(board[_xCoord][_yCoord + 1])->getColor() != _color)
        {
            moves.append(down);
        }

        // Bas-Droite
        if (_xCoord + 1 <= 7)
        {
            QPointF downRight(_xCoord + 1, _yCoord + 1);
            if (board[_xCoord + 1][_yCoord + 1] == nullptr)
            {
                moves.append(downRight);
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + 1][_yCoord + 1])->getColor() != _color)
            {
                moves.append(downRight);
            }

        }

        // Bas-Gauche
        if (_xCoord - 1 >= 0)
        {
            QPointF downLeft(_xCoord - 1, _yCoord + 1);
            if (board[_xCoord - 1][_yCoord + 1] == nullptr)
            {
                moves.append(downLeft);
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - 1][_yCoord + 1])->getColor() != _color)
            {
                moves.append(downLeft);
            }
        }
    }

    // Droite
    if (_xCoord + 1 <= 7)
    {
        QPointF right(_xCoord + 1, _yCoord);
        {
            if (board[_xCoord + 1][_yCoord] == nullptr)
            {
                moves.append(right);
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord + 1][_yCoord])->getColor() != _color)
            {
                moves.append(right);
            }
        }
    }

    // Gauche
    if (_xCoord - 1 >= 0)
    {
        QPointF left(_xCoord - 1, _yCoord);
        {
            if (board[_xCoord - 1][_yCoord] == nullptr)
            {
                moves.append(left);
            }
            else if (dynamic_cast<ChessPiece*>(board[_xCoord - 1][_yCoord])->getColor() != _color)
            {
                moves.append(left);
            }
        }
    }

    return moves;
}