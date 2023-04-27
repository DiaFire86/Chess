#pragma once

#include "chesspiece.h"

class King : public Piece::ChessPiece
{
public:
    King(int yCoord, int xCoord, Color color);
    void changeCoord(int yCoord, int xCoord) override;

    QList<QPointF> possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const override;

    void decreaseKingCount() { --_kingCounter; }
    static int kingCount() { return _kingCounter; };
    static int kingCounted();

    ~King() { decreaseKingCount(); }

private:
    static const QString WHITE_KING_IMAGE_URL;
    static const QString BLACK_KING_IMAGE_URL;

    static QPixmap getImageUrl(Color color);
    Color _color;
    int _xCoord;
    int _yCoord;

    static int _kingCounter;
};