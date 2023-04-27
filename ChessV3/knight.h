#pragma once

#include "chesspiece.h"

class Knight : public Piece::ChessPiece
{
public:
    Knight(int yCoord, int xCoord, Color color);
    void changeCoord(int yCoord, int xCoord) override;

    QList<QPointF> possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const override;


private:
    static const QString WHITE_KNIGHT_IMAGE_URL;
    static const QString BLACK_KNIGHT_IMAGE_URL;

    static QPixmap getImageUrl(Color color);
    Color _color;
    int _xCoord;
    int _yCoord;
};