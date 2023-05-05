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

    // Toutes les directions possibles
    const int directions[8][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    for (const auto& direction : directions)
    {
        const int xDirection = direction[0];
        const int yDirection = direction[1];

        for (int i = 1; i < 8; ++i)
        {
            const int x = _xCoord + i * xDirection;
            const int y = _yCoord + i * yDirection;

            // Vérifie si position est valide
            if (x < 0 || x > 7 || y < 0 || y > 7)
            {
                break;
            }

            // Vérifie si case contient deja une piece
            if (board[x][y] == nullptr)
            {
                moves.append(QPointF(x, y));
            }
            else if (dynamic_cast<ChessPiece*>(board[x][y])->getColor() != _color)
            {
                moves.append(QPointF(x, y));
                break;
            }
            else
            {
                break;
            }
        }
    }
    return moves;
}