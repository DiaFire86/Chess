#pragma once

#include "chesspiece.h"

class Bishop : public Piece::ChessPiece
{
public:
    Bishop(int yCoord, int xCoord, Color color);
    void changeCoord(int yCoord, int xCoord) override;

    QList<QPointF> possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const override;

private:
    static const QString WHITE_BISHOP_IMAGE_URL;
    static const QString BLACK_BISHOP_IMAGE_URL;

    static QPixmap getImageUrl(Color color);
    Color _color;
    int _xCoord;
    int _yCoord;
};