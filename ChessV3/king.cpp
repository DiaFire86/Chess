#include "stdafx.h"
#include "king.h"
#include "rook.h"

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
    if (color == WHITE)
    {
        if (xCoord == 4 && yCoord == 0)
        {
            asMooved = false;
        }
        else
        {
            asMooved = true;
        }
    }
    else
    {
        if (xCoord == 4 && yCoord == 7)
        {
            asMooved = false;
        }
        else
        {
            asMooved = true;
        }
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

    const int directions[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    for (const auto& direction : directions)
    {
        const int xDirection = direction[0];
        const int yDirection = direction[1];

        const int x = _xCoord + xDirection;
        const int y = _yCoord + yDirection;

        // Vérifie si position est valide
        if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
        {
            if (board[x][y] == nullptr)
            {
                moves.append(QPointF(x, y));
            }
            else if (dynamic_cast<ChessPiece*>(board[x][y])->getColor() != _color)
            {
                moves.append(QPointF(x, y));
            }
        }
    }

    // Roque
    if (!asMooved)
    {
        bool canRoqueRight = true;
        for (int i = 1; i < 3; i++)
        {
            if (board[_xCoord + i][_yCoord] != nullptr)
            {
                canRoqueRight = false;
                break;
            }
        }
        Piece::ChessPiece* chessPieceRight;
        if (board[_xCoord + 3][_yCoord] != nullptr)
        {
            chessPieceRight = dynamic_cast<Piece::ChessPiece*>(board[_xCoord + 3][_yCoord]);
        }
        if (chessPieceRight->getType() == ROOK && canRoqueRight)
        {
            if (!dynamic_cast<Rook*>(chessPieceRight)->asMooved)
            {
                moves.append(QPointF(_xCoord + 2, _yCoord));
            }
        }

        bool canRoqueLeft = true;
        for (int i = 1; i < 4; i++)
        {
            if (board[_xCoord - i][_yCoord] != nullptr)
            {
                canRoqueLeft = false;
                break;
            }
        }
        Piece::ChessPiece* chessPieceLeft;
        if (board[_xCoord - 4][_yCoord] != nullptr)
        {
            chessPieceLeft = dynamic_cast<Piece::ChessPiece*>(board[_xCoord - 4][_yCoord]);
        }
        if (chessPieceLeft->getType() == ROOK && canRoqueLeft)
        {
            if (!dynamic_cast<Rook*>(chessPieceLeft)->asMooved)
            {
                moves.append(QPointF(_xCoord - 2, _yCoord));
            }
        }
    }
    return moves;

}