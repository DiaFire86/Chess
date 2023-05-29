#include "stdafx.h"
#include "chessboard.h"
#include "chesspiece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "display.h"

namespace Chess {
    ChessBoard::ChessBoard(QGraphicsView* view = nullptr, int width = 0, int height = 0, int predefined = 0, bool init = true) : QGraphicsScene(0, 0, width + 10, height + 10), boardWidth(width), boardHeight(height), m_view(view), selectedPiece(nullptr), isStarted(init), isPaused(false)
    {
        initBoard();
        if (init)
        {
            initPieces(predefined);
        }
        else
        {
            dispPieces();
        }
    }

    void ChessBoard::initBoard()
    {
        // Cr�ation du plateau
        setSceneRect(0, 0, boardWidth, boardHeight);
        for (int column = 0; column < 8; column++)
        {
            for (int row = 0; row < 8; row++)
            {
                QColor color = ((column + row) % 2 == 0) ? QColor(82, 122, 122) : Qt::white;
                addRect(column * (boardWidth / 8), row * (boardHeight / 8), (boardWidth / 8), (boardHeight / 8), QPen(Qt::black), QBrush(color));
            }
        }
        cellSize = boardWidth / 8;
    }

    void ChessBoard::initPieces(int predefined)
    {
        // Initialisation des pi�ces
        if (predefined == 0)
        {
            Piece::ChessPiece* pieces0[8][8] =
            {
                {new Rook(0,0, WHITE),new Pawn(1,0, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,0, BLACK),new Rook(7,0, BLACK)},
                {new Knight(0, 1, WHITE),new Pawn(1,1, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,1, BLACK),new Knight(7,1, BLACK)},
                {new Bishop(0, 2, WHITE),new Pawn(1,2, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,2, BLACK),new Bishop(7,2, BLACK)},
                {new Queen(0, 3, WHITE),new Pawn(1,3, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,3, BLACK),new Queen(7,3, BLACK)},
                {new King(0, 4, WHITE),new Pawn(1,4, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,4, BLACK),new King(7,4, BLACK)},
                {new Bishop(0, 5, WHITE),new Pawn(1,5, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,5, BLACK),new Bishop(7,5, BLACK)},
                {new Knight(0, 6, WHITE),new Pawn(1,6, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,6, BLACK),new Knight(7,6, BLACK)},
                {new Rook(0, 7, WHITE),new Pawn(1,7, WHITE),nullptr,nullptr,nullptr,nullptr,new Pawn(6,7, BLACK),new Rook(7,7, BLACK)},
            };
            for (int column = 0; column < 8; column++)
            {
                for (int row = 0; row < 8; row++)
                {
                    board[column][row] = pieces0[column][row];
                    addItem(pieces0[column][row]);
                }
            }
        }
        else if (predefined == 1)
        {
            Piece::ChessPiece* pieces1[8][8] =
            {
                {nullptr, nullptr, new Rook(2,0, BLACK), nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, new Rook(4,1, WHITE), nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, new Bishop(4,3, WHITE), new King(5,3, BLACK), nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, new Knight(4,4, BLACK), nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, new Bishop(3,5, BLACK), nullptr, nullptr, nullptr, nullptr},
                {nullptr, new King(1,6, WHITE), nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
            };
            for (int column = 0; column < 8; column++)
            {
                for (int row = 0; row < 8; row++)
                {
                    board[column][row] = pieces1[column][row];
                    addItem(pieces1[column][row]);
                }
            }
        }
        else if (predefined == 2)
        {
            Piece::ChessPiece* pieces2[8][8] =
            {
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new Queen(6,2, WHITE), nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, new Knight(2,5, BLACK), nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, new King(3,6, BLACK), nullptr, nullptr, nullptr, nullptr},
                {new King(0,7, WHITE), nullptr, new Bishop(2,7, BLACK), nullptr, nullptr, nullptr, nullptr, nullptr},
            };
            for (int column = 0; column < 8; column++)
            {
                for (int row = 0; row < 8; row++)
                {
                    board[column][row] = pieces2[column][row];
                    addItem(pieces2[column][row]);
                }
            }
        }
        else if (predefined == 3)
        {
            Piece::ChessPiece* pieces3[8][8] =
            {
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, new Bishop(5,1, BLACK), nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new King(6,2, BLACK)},
                {nullptr, nullptr, nullptr, nullptr, new Bishop(4,3, BLACK), nullptr, nullptr, nullptr},
                {new Rook(0, 4, WHITE), new Rook(1,4, WHITE), nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {new King(0, 5, WHITE), nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
            };
            for (int column = 0; column < 8; column++)
            {
                for (int row = 0; row < 8; row++)
                {
                    board[column][row] = pieces3[column][row];
                    addItem(pieces3[column][row]);
                }
            }
        }
    }

    void ChessBoard::dispPieces()
    {
        addItem(new Rook(-1, 0, WHITE));
        addItem(new Knight(-1, 1, WHITE));
        addItem(new Bishop(-1, 2, WHITE));
        addItem(new Queen(-1, 3, WHITE));
        addItem(new King(-1, 4, WHITE));
        addItem(new Pawn(-1, 5, WHITE));
        addItem(new Rook(8, 0, BLACK));
        addItem(new Knight(8, 1, BLACK));
        addItem(new Bishop(8, 2, BLACK));
        addItem(new Queen(8, 3, BLACK));
        addItem(new King(8, 4, BLACK));
        addItem(new Pawn(8, 5, BLACK));
        for (int column = 0; column < 8; column++)
        {
            for (int row = 0; row < 8; row++)
            {
                board[column][row] = nullptr;
            }
        }
    }

    void ChessBoard::removeDispPieces()
    {
        for (int i = 0; i < 7; i++)
        {
            QPointF posWhite = QPointF(i * cellSize + cellSize / 2, -1 * cellSize + cellSize / 2);
            QGraphicsItem* targetItemWhite = itemAt(posWhite, QTransform());
            removeItem(targetItemWhite);
            delete targetItemWhite;
            QPointF posBlack = QPointF(i * cellSize + cellSize / 2, 8 * cellSize + cellSize / 2);
            QGraphicsItem* targetItemBlack = itemAt(posBlack, QTransform());
            removeItem(targetItemBlack);
            delete targetItemBlack;
        }
    }

    void ChessBoard::startGameWhite()
    {
        removeDispPieces();
        isStarted = true;
        isWhiteTurn = true;
    }

    void ChessBoard::startGameBlack()
    {
        removeDispPieces();
        isStarted = true;
        isWhiteTurn = false;
    }

    void ChessBoard::pawnPromotion(int xCoord, int yCoord)
    {
        Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(board[xCoord][yCoord]);
        if (chessPiece != nullptr)
        {
            removeItem(chessPiece);
            delete(chessPiece);
        }
        Color color((yCoord == 0) ? BLACK : WHITE);
        Piece::ChessPiece* newPiece = new Pawn(yCoord, xCoord, color);
        addItem(newPiece);
        board[xCoord][yCoord] = newPiece;
        QWidget* choice = qobject_cast<QWidget*>(sender()->parent());
        choice->close();
        isPaused = false;
    }

    void ChessBoard::rookPromotion(int xCoord, int yCoord)
    {
        Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(board[xCoord][yCoord]);
        if (chessPiece != nullptr)
        {
            removeItem(chessPiece);
            delete(chessPiece);
        }
        Color color((yCoord == 0) ? BLACK : WHITE);
        Piece::ChessPiece* newPiece = new Rook(yCoord, xCoord, color);
        addItem(newPiece);
        board[xCoord][yCoord] = newPiece;
        QWidget* choice = qobject_cast<QWidget*>(sender()->parent());
        choice->close();
        isPaused = false;
    }

    void ChessBoard::bishopPromotion(int xCoord, int yCoord)
    {
        Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(board[xCoord][yCoord]);
        if (chessPiece != nullptr)
        {
            removeItem(chessPiece);
            delete(chessPiece);
        }
        Color color((yCoord == 0) ? BLACK : WHITE);
        Piece::ChessPiece* newPiece = new Bishop(yCoord, xCoord, color);
        addItem(newPiece);
        board[xCoord][yCoord] = newPiece;
        QWidget* choice = qobject_cast<QWidget*>(sender()->parent());
        choice->close();
        isPaused = false;
    }

    void ChessBoard::knightPromotion(int xCoord, int yCoord)
    {
        Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(board[xCoord][yCoord]);
        if (chessPiece != nullptr)
        {
            removeItem(chessPiece);
            delete(chessPiece);
        }
        Color color((yCoord == 0) ? BLACK : WHITE);
        Piece::ChessPiece* newPiece = new Knight(yCoord, xCoord, color);
        addItem(newPiece);
        board[xCoord][yCoord] = newPiece;
        QWidget* choice = qobject_cast<QWidget*>(sender()->parent());
        choice->close();
        isPaused = false;
    }

    void ChessBoard::queenPromotion(int xCoord, int yCoord)
    {
        Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(board[xCoord][yCoord]);
        if (chessPiece != nullptr)
        {
            removeItem(chessPiece);
            delete(chessPiece);
        }
        Color color((yCoord == 0) ? BLACK : WHITE);
        Piece::ChessPiece* newPiece = new Queen(yCoord, xCoord, color);
        addItem(newPiece);
        board[xCoord][yCoord] = newPiece;
        QWidget* choice = qobject_cast<QWidget*>(sender()->parent());
        choice->close();
        isPaused = false;
    }

    bool ChessBoard::isWhiteKingInCheckMate(QGraphicsPixmapItem* (&board)[8][8])
    {
        for (int column = 0; column < 8; column++)
        {
            for (int row = 0; row < 8; row++)
            {
                Piece::ChessPiece* piece = dynamic_cast<Piece::ChessPiece*>(board[column][row]);
                if (piece != nullptr && piece->getColor() == WHITE)
                {
                    QList<QPointF> pieceMoves = piece->possibleMoves(board, piece, QPointF(row, column));
                    for (int moves = 0; moves < pieceMoves.size(); moves++)
                    {
                        QPointF move = pieceMoves.at(moves);
                        int newXCoord = move.x();
                        int newYCoord = move.y();
                        Piece::ChessPiece* pieceTemp = dynamic_cast<Piece::ChessPiece*>(board[newXCoord][newYCoord]);
                        board[newXCoord][newYCoord] = piece;
                        board[column][row] = nullptr;
                        if (!piece->isKingInCheck(board))
                        {
                            board[newXCoord][newYCoord] = pieceTemp;
                            board[column][row] = piece;
                            return false;
                            break;
                        }
                        else
                        {
                            board[newXCoord][newYCoord] = pieceTemp;
                            board[column][row] = piece;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool ChessBoard::isBlackKingInCheckMate(QGraphicsPixmapItem* (&board)[8][8])
    {
        for (int column = 0; column < 8; column++)
        {
            for (int row = 0; row < 8; row++)
            {
                Piece::ChessPiece* piece = dynamic_cast<Piece::ChessPiece*>(board[column][row]);
                if (piece != nullptr && piece->getColor() == BLACK)
                {
                    QList<QPointF> pieceMoves = piece->possibleMoves(board, piece, QPointF(row, column));
                    for (int moves = 0; moves < pieceMoves.size(); moves++)
                    {
                        QPointF move = pieceMoves.at(moves);
                        int newXCoord = move.x();
                        int newYCoord = move.y();
                        Piece::ChessPiece* pieceTemp = dynamic_cast<Piece::ChessPiece*>(board[newXCoord][newYCoord]);
                        board[newXCoord][newYCoord] = piece;
                        board[column][row] = nullptr;
                        if (!piece->isKingInCheck(board))
                        {
                            board[newXCoord][newYCoord] = pieceTemp;
                            board[column][row] = piece;
                            return false;
                            break;
                        }
                        else
                        {
                            board[newXCoord][newYCoord] = pieceTemp;
                            board[column][row] = piece;
                        }
                    }
                }
            }
        }
        return true;
    }


    // D�placement des pi�ces et calcul du jeu
    void ChessBoard::mousePressEvent(QGraphicsSceneMouseEvent* event)
    {
        if (event->button() == Qt::LeftButton && !isPaused)
        {
            Display* display = new Display();

            // S�l�ction de la pi�ce
            QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
            if (item && item->type() == QGraphicsPixmapItem::Type)
            {
                selectedPiece = static_cast<QGraphicsPixmapItem*>(item);
                initialPos = selectedPiece->pos();

                if (isStarted)
                {
                    // Calcul et affichage des coups possibles avec v�rification du tour
                    Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(selectedPiece);
                    if ((isWhiteTurn && chessPiece->getColor() == WHITE) || (!isWhiteTurn && chessPiece->getColor() == BLACK))
                    {
                        QList<QPointF> moves = chessPiece->possibleMoves(board, chessPiece, initialPos);
                        display->DisplayPossibleMoves(this->m_view->scene(), this, moves);
                    }
                }
                selectedPiece->setZValue(selectedPiece->zValue() + 1);

                delete display;
            }
            event->accept();
        }
    }

    void ChessBoard::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
    {
        if (selectedPiece && !isPaused)
        {
            QPointF newPos = event->scenePos() - QPointF(cellSize / 2, cellSize / 2);
            selectedPiece->setPos(newPos);
        }
        event->accept();
    }

    void ChessBoard::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
    {
        if (selectedPiece && !isPaused)
        {
            Display* display = new Display();
            // Si la partie � commenc�e
            if (isStarted)
            {
                // Calcul et Suppresion de l'affichage des coups possibles
                Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(selectedPiece);
                QList<QPointF> moves = chessPiece->possibleMoves(board, chessPiece, initialPos);
                display->ErasePossibleMoves(this->m_view->scene(), &tempPossibleMoves);

                // V�rification du tour
                if ((isWhiteTurn && chessPiece->getColor() == WHITE) || (!isWhiteTurn && chessPiece->getColor() == BLACK))
                {
                    selectedPiece->setPos(initialPos); // On remet la pi�ce � sa position initiale le temps de regarder si il y a une autre pi�ce � la nouvelle position
                    QPointF newPos = event->scenePos();

                    int xCoord = newPos.x() / cellSize;
                    int yCoord = newPos.y() / cellSize;
                    QPointF centerCoord(xCoord, yCoord);
                    QPointF newPosCenter(xCoord * cellSize + cellSize / 2, yCoord * cellSize + cellSize / 2);
                    QPointF newPosCorner(xCoord * cellSize, yCoord * cellSize);
                    QPointF initialPosCorner((initialPos.x() / cellSize) * cellSize, (initialPos.y() / cellSize) * cellSize);

                    // V�rification que le coup est valide
                    if (moves.contains(centerCoord))
                    {
                        // Ajustement des coordonn�es dans le tableau
                        int init_xCoord = initialPos.x() / cellSize;
                        int init_yCoord = initialPos.y() / cellSize;
                        board[init_xCoord][init_yCoord] = nullptr;
                        chessPiece->changeCoord(yCoord, xCoord);
                        QGraphicsPixmapItem* tempInit = board[xCoord][yCoord];
                        board[xCoord][yCoord] = selectedPiece;

                        // V�rification du roi en echec
                        if (chessPiece->isKingInCheck(board))
                        {
                            board[init_xCoord][init_yCoord] = selectedPiece;
                            chessPiece->changeCoord(init_yCoord, init_xCoord);
                            board[xCoord][yCoord] = tempInit;
                            display->kingInCheck();
                        }
                        else
                        {
                            // Si prise, suppression de la pi�ce prise
                            QGraphicsItem* targetItem = itemAt(newPosCenter, QTransform());
                            if (targetItem && targetItem->type() == QGraphicsPixmapItem::Type && targetItem != selectedPiece)
                            {
                                removeItem(targetItem);
                                delete targetItem;
                            }

                            // Si la pi�ce est un pion, de l'autre cot� du board, on laisse le joueur choisir une nouvelle pi�ce � �changer
                            if (chessPiece->getType() == PAWN && ((chessPiece->getColor() == WHITE && yCoord == 7) || (chessPiece->getColor() == BLACK && yCoord == 0)))
                            {
                                isPaused = true;
                                QWidget* choice = new QWidget();
                                QVBoxLayout* layout = new QVBoxLayout();
                                QPushButton* pawnButton = new QPushButton("Pion");
                                QPushButton* rookButton = new QPushButton("Tour");
                                QPushButton* bishopButton = new QPushButton("Fou");
                                QPushButton* knightButton = new QPushButton("Cavalier");
                                QPushButton* queenButton = new QPushButton("Reine");
                                layout->addWidget(pawnButton);
                                layout->addWidget(rookButton);
                                layout->addWidget(bishopButton);
                                layout->addWidget(knightButton);
                                layout->addWidget(queenButton);

                                choice->setWindowTitle("Choisi la nouvelle piece");
                                choice->resize(400, 200);
                                choice->setLayout(layout);
                                choice->show();

                                QObject::connect(pawnButton, &QPushButton::clicked, this, [this, layout, choice, pawnButton, rookButton, bishopButton, knightButton, queenButton, xCoord, yCoord]() {pawnPromotion(xCoord, yCoord); delete pawnButton; delete rookButton; delete bishopButton; delete knightButton; delete queenButton; delete layout; delete choice; });
                                QObject::connect(rookButton, &QPushButton::clicked, this, [this, layout, choice, pawnButton, rookButton, bishopButton, knightButton, queenButton, xCoord, yCoord]() {rookPromotion(xCoord, yCoord); delete pawnButton; delete rookButton; delete bishopButton; delete knightButton; delete queenButton; delete layout; delete choice; });
                                QObject::connect(bishopButton, &QPushButton::clicked, this, [this, layout, choice, pawnButton, rookButton, bishopButton, knightButton, queenButton, xCoord, yCoord]() {bishopPromotion(xCoord, yCoord); delete pawnButton; delete rookButton; delete bishopButton; delete knightButton; delete queenButton; delete layout; delete choice; });
                                QObject::connect(knightButton, &QPushButton::clicked, this, [this, layout, choice, pawnButton, rookButton, bishopButton, knightButton, queenButton, xCoord, yCoord]() {knightPromotion(xCoord, yCoord); delete pawnButton; delete rookButton; delete bishopButton; delete knightButton; delete queenButton; delete layout; delete choice; });
                                QObject::connect(queenButton, &QPushButton::clicked, this, [this, layout, choice, pawnButton, rookButton, bishopButton, knightButton, queenButton, xCoord, yCoord]() {queenPromotion(xCoord, yCoord);; delete pawnButton; delete rookButton; delete bishopButton; delete knightButton; delete queenButton; delete layout; delete choice; });
                            }

                            // Changement de la position de la pi�ce pour l'affichage
                            selectedPiece->setPos(newPosCorner); 

                            // Si c'�tait un Roque de roi, changer la position de la tour :
                            if (chessPiece->getType() == KING)
                            {
                                if (xCoord == 2 && yCoord == 0)
                                {
                                    QGraphicsItem* rookQG = itemAt(QPointF(0.5 * cellSize, 0.5 * cellSize), QTransform());
                                    Piece::ChessPiece* rook = dynamic_cast<Piece::ChessPiece*>(board[0][0]);
                                    rook->changeCoord(0, 3);
                                    board[3][0] = board[0][0];
                                    board[0][0] = nullptr;
                                    rookQG->setPos(QPointF(3 * cellSize, 0));
                                }
                                if (xCoord == 6 && yCoord == 0)
                                {
                                    QGraphicsItem* rookQG = itemAt(QPointF(7.5 * cellSize, 0.5 * cellSize), QTransform());
                                    Piece::ChessPiece* rook = dynamic_cast<Piece::ChessPiece*>(board[7][0]);
                                    rook->changeCoord(0, 5);
                                    board[5][0] = board[7][0];
                                    board[7][0] = nullptr;
                                    rookQG->setPos(QPointF(5 * cellSize, 0));
                                }
                                if (xCoord == 2 && yCoord == 7)
                                {
                                    QGraphicsItem* rookQG = itemAt(QPointF(0.5 * cellSize, 7.5 * cellSize), QTransform());
                                    Piece::ChessPiece* rook = dynamic_cast<Piece::ChessPiece*>(board[0][7]);
                                    rook->changeCoord(7, 3);
                                    board[3][7] = board[0][7];
                                    board[0][7] = nullptr;
                                    rookQG->setPos(QPointF(3 * cellSize, 7 * cellSize));
                                }
                                if (xCoord == 6 && yCoord == 7)
                                {
                                    QGraphicsItem* rookQG = itemAt(QPointF(7.5 * cellSize, 7.5 * cellSize), QTransform());
                                    Piece::ChessPiece* rook = dynamic_cast<Piece::ChessPiece*>(board[7][7]);
                                    rook->changeCoord(7, 5);
                                    board[5][7] = board[7][7];
                                    board[0][7] = nullptr;
                                    rookQG->setPos(QPointF(5 * cellSize, 7 * cellSize));
                                }
                            }

                            // Changement de tour si la position � chang�e
                            if (isWhiteTurn && initialPosCorner != newPosCorner)
                            {
                                if (chessPiece->getType() == KING)
                                {
                                    King* king = dynamic_cast<King*>(chessPiece);
                                    king->asMooved = true;
                                }
                                if (chessPiece->getType() == ROOK)
                                {
                                    Rook* rook = dynamic_cast<Rook*>(chessPiece);
                                    rook->asMooved = true;
                                }
                                isWhiteTurn = false;
                                if (this->isBlackKingInCheckMate(board))
                                {
                                    display->BlackKingInCheckMate();
                                    isPaused = true;
                                }
                            }
                            else if (!isWhiteTurn && initialPosCorner != newPosCorner)
                            {
                                if (chessPiece->getType() == KING)
                                {
                                    King* king = dynamic_cast<King*>(chessPiece);
                                    king->asMooved = true;
                                }
                                if (chessPiece->getType() == ROOK)
                                {
                                    Rook* rook = dynamic_cast<Rook*>(chessPiece);
                                    rook->asMooved = true;
                                }
                                isWhiteTurn = true;
                                if (this->isWhiteKingInCheckMate(board))
                                {
                                    display->WhiteKingInCheckMate();
                                    isPaused = true;
                                }
                            }
                        }
                    }
                }
                else
                {
                    selectedPiece->setPos(initialPos);
                }
                selectedPiece->setZValue(0);
                selectedPiece = nullptr;
            }
            // Si la partie n'as pas commenc�e
            else
            {
                Piece::ChessPiece* chessPiece = dynamic_cast<Piece::ChessPiece*>(selectedPiece);
                selectedPiece->setPos(initialPos); // On remet la pi�ce � sa position initiale le temps de regarder si il y a une autre pi�ce � la nouvelle position
                QPointF newPos = event->scenePos();

                int xCoord = newPos.x() / cellSize;
                int yCoord = newPos.y() / cellSize;
                QPointF centerCoord(xCoord, yCoord);
                QPointF newPosCenter(xCoord * cellSize + cellSize / 2, yCoord * cellSize + cellSize / 2);
                QPointF newPosCorner(xCoord * cellSize, yCoord * cellSize);
                QPointF initialPosCorner((initialPos.x() / cellSize) * cellSize, (initialPos.y() / cellSize) * cellSize);

                // On v�rifie si la pi�ce vient du board ou non
                if ((initialPos.x() / cellSize) < 8 && (initialPos.x() / cellSize) >= 0 && (initialPos.y() / cellSize) < 8 && (initialPos.y() / cellSize) >= 0)
                {
                    // On v�rifie que la pi�ce est lach�e sur le board
                    if (xCoord < 8 && newPos.x() >= 0 && yCoord < 8 && newPos.y() >= 0)
                    {
                        // Si la pi�ce est un roi qui change de position, on dit que le roi as boug�
                        if (chessPiece->getType() == KING && initialPosCorner != newPosCorner)
                        {
                            King* king = dynamic_cast<King*>(chessPiece);
                            king->asMooved = true;
                        }
                        if (chessPiece->getType() == ROOK)
                        {
                            Rook* rook = dynamic_cast<Rook*>(chessPiece);
                            rook->asMooved = true;
                        }

                        // Ajustement des coordonn�es dans le tableau
                        int init_xCoord = initialPos.x() / cellSize;
                        int init_yCoord = initialPos.y() / cellSize;
                        board[init_xCoord][init_yCoord] = nullptr;
                        chessPiece->changeCoord(yCoord, xCoord);
                        board[xCoord][yCoord] = selectedPiece;

                        // Si on passe sur une pi�ce, on echange les deux pi�ces
                        QGraphicsItem* targetItem = itemAt(newPosCenter, QTransform());
                        if (targetItem && targetItem->type() == QGraphicsPixmapItem::Type && targetItem != selectedPiece)
                        {
                            Piece::ChessPiece* targetPiece = dynamic_cast<Piece::ChessPiece*>(targetItem);
                            targetPiece->changeCoord(init_yCoord, init_yCoord);
                            board[init_xCoord][init_yCoord] = targetPiece;
                            targetPiece->setPos(initialPos);
                        }

                        // Changement de la position de la pi�ce pour l'affichage
                        selectedPiece->setPos(newPosCorner);
                        selectedPiece->setZValue(selectedPiece->zValue() - 1);
                    }
                    // Si la pi�ce est lach�e en dehors du board elle est supprim�e
                    else
                    {
                        board[xCoord][yCoord] = nullptr;
                        removeItem(selectedPiece);
                        delete selectedPiece;
                    }
                }
                else
                {
                    // On v�rifie que la pi�ce est lach�e sur le board
                    if (xCoord < 8 && newPos.x() >= 0 && yCoord < 8 && newPos.y() >= 0)
                    {
                        TypePiece type = chessPiece->getType();
                        Piece::ChessPiece* newPiece;
                        switch (type)
                        {
                        case PAWN:
                            newPiece = new Pawn(yCoord, xCoord, chessPiece->getColor());
                            break;
                        case ROOK:
                            newPiece = new Rook(yCoord, xCoord, chessPiece->getColor());
                            break;
                        case KNIGHT:
                            newPiece = new Knight(yCoord, xCoord, chessPiece->getColor());
                            break;
                        case BISHOP:
                            newPiece = new Bishop(yCoord, xCoord, chessPiece->getColor());
                            break;
                        case KING:
                            newPiece = new King(yCoord, xCoord, chessPiece->getColor());
                            break;
                        case QUEEN:
                            newPiece = new Queen(yCoord, xCoord, chessPiece->getColor());
                            break;
                        }

                        // V�rification du nombre de rois
                        if (King::kingCount() > 4)
                        {
                            King* king = dynamic_cast<King*>(newPiece);
                            delete king;
                        }
                        else
                        {
                            // Si prise, suppression de la pi�ce prise
                            QGraphicsItem* targetItem = itemAt(newPosCenter, QTransform());
                            if (targetItem && targetItem->type() == QGraphicsPixmapItem::Type && targetItem != selectedPiece)
                            {
                                removeItem(targetItem);
                                delete targetItem;
                            }

                            newPiece->setPos(newPosCorner);
                            board[xCoord][yCoord] = newPiece;
                            addItem(newPiece);
                        }
                    }
                }
            }
            delete display;
        }
        event->accept();
    }

    ChessBoard::~ChessBoard() 
    {
        for (int column = 0; column < 8; column++)
        {
            for (int row = 0; row < 8; row++)
            {
                if (board[column][row] != nullptr)
                {
                    delete board[column][row];
                }
            }
        }
    }
}