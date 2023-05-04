#pragma once

#include <QtWidgets/QWidget>

namespace Chess {
    class ChessBoard : public QGraphicsScene
    {
    public:
        ChessBoard(QGraphicsView* view, int width, int height);
        ChessBoard(QGraphicsView* view, int width, int height, bool init);

        void initBoard();
        void initPieces();
        void dispPieces();
        void startGameWhite();
        void startGameBlack();

        void removeDispPieces();

        void pawnPromotion(int xCoord, int yCoord);
        void rookPromotion(int xCoord, int yCoord);
        void bishopPromotion(int xCoord, int yCoord);
        void knightPromotion(int xCoord, int yCoord);
        void queenPromotion(int xCoord, int yCoord);

        bool isWhiteKingInCheckMate(QGraphicsPixmapItem* (&board)[8][8]);
        bool isBlackKingInCheckMate(QGraphicsPixmapItem* (&board)[8][8]);

        ~ChessBoard();

        int getCellSize() { return cellSize; }
        QList<QGraphicsEllipseItem*> tempPossibleMoves;


    private:
        QGraphicsView* m_view;
        int boardWidth = 0;
        int boardHeight = 0;
        int cellSize = 0;
        bool isWhiteTurn = true;
        bool isStarted = false;
        bool isPaused = false;

        QGraphicsPixmapItem* board[8][8];
        QGraphicsPixmapItem* selectedPiece;
        QPointF initialPos;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    };
}