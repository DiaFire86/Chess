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

    const int directions[8][2] = { {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} };
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

    return moves;
}