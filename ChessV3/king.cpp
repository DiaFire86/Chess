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

    const int directions[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    for (const auto& direction : directions)
    {
        const int xDirection = direction[0];
        const int yDirection = direction[1];

        const int x = _xCoord +  xDirection;
        const int y = _yCoord +  yDirection;

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

    return moves;
}