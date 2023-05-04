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

    // Toutes les directions possibles
    const int directions[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
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