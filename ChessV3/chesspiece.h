#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsView>

enum TypePiece
{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    KING,
    QUEEN
};

enum Color
{
    WHITE,
    BLACK
};

namespace Piece {
    class ChessPiece : public QGraphicsPixmapItem, public QGraphicsView
    {
    public:
        ChessPiece(QPixmap pixmap, int yCoord, int xCoord, Color color, TypePiece type);
        ~ChessPiece();
        Color getColor() { return _color; };
        TypePiece getType() { return _type; };
        int getXCoord() { return _xCoord; };
        int getYCoord() { return _yCoord; };

        virtual void changeCoord(int yCoord, int xCoord) { _yCoord = yCoord; _xCoord = xCoord; };
        virtual QList<QPointF> possibleMoves(QGraphicsPixmapItem* (&board)[8][8], ChessPiece* chessPiece, QPointF pos) const = 0;

        bool isKingInCheck(QGraphicsPixmapItem* (&board)[8][8]);

    private:
        TypePiece _type;
        Color _color;
        int _xCoord;
        int _yCoord;
    };
}