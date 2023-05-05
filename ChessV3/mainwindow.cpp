#include "stdafx.h"
#include "mainwindow.h"


MainWindow::MainWindow(int width = 0, int height = 0) : boardWidth(width), boardHeight(height)
{
	setWindowTitle("Jeu d'echec");
	setFixedSize(boardWidth + 10, boardHeight + 10);

	QPushButton* playButton = new QPushButton("Demarrer une partie classique\n", this);
	QPushButton* customButton = new QPushButton("Demarrer une partie personnalisee\n", this);
	QPushButton* predefined1Button = new QPushButton("Demarrer la partie predefinie 1 (Unzicker, 1949)\n", this);
	QPushButton* predefined2Button = new QPushButton("Demarrer la partie predefinie 2 (Ponziani, 1782)\n", this);
	QPushButton* predefined3Button = new QPushButton("Demarrer la partie predefinie 3 (Tilburg, 1991)\n", this);
	playButton->setGeometry(boardWidth/2 - 125, boardHeight/2 - 145, 250, 50);
	customButton->setGeometry(boardWidth / 2 - 125, boardHeight / 2 - 85, 250, 50);
	predefined1Button->setGeometry(boardWidth / 2 - 125, boardHeight / 2 - 25, 250, 50);
	predefined2Button->setGeometry(boardWidth / 2 - 125, boardHeight / 2 + 35, 250, 50);
	predefined3Button->setGeometry(boardWidth / 2 - 125, boardHeight / 2 + 95, 250, 50);

	QObject::connect(playButton, &QPushButton::clicked, this, &MainWindow::openRegularChessWidget);
	QObject::connect(customButton, &QPushButton::clicked, this, &MainWindow::openCustomChessWidget);
	QObject::connect(predefined1Button, &QPushButton::clicked, this, &MainWindow::openPredefined1ChessWidget);
	QObject::connect(predefined2Button, &QPushButton::clicked, this, &MainWindow::openPredefined2ChessWidget);
	QObject::connect(predefined3Button, &QPushButton::clicked, this, &MainWindow::openPredefined3ChessWidget);

}

void MainWindow::openRegularChessWidget()
{
	if (!chessWidget)
	{
		chessWidget = new QWidget(this);
		chessWidget->setWindowTitle("Plateau de jeu");
		QGraphicsView* view = new QGraphicsView(chessWidget);
		Chess::ChessBoard* chessBoard = new Chess::ChessBoard(view, boardWidth, boardHeight, 0);
		this->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setScene(chessBoard);
		chessWidget->show();
	}
}

void MainWindow::openCustomChessWidget()
{
	if (!chessWidget)
	{
		chessWidget = new QWidget(this);
		chessWidget->setWindowTitle("Plateau de jeu");
		QGridLayout* layout = new QGridLayout(chessWidget);

		QPushButton* playButtonWhite = new QPushButton("les blancs\n demarrent\n la\n partie", this);
		playButtonWhite->setGeometry(10, 10, 200, 50);
		QPushButton* playButtonBlack = new QPushButton("les noirs\n demarrent\n la\n partie", this);
		playButtonBlack->setGeometry(10, 10, 200, 50);
		layout->addWidget(playButtonWhite, 0, 1, Qt::AlignTop);
		layout->addWidget(playButtonBlack, 0, 1, Qt::AlignBottom);

		QGraphicsView* view = new QGraphicsView(chessWidget);
		Chess::ChessBoard* customChessBoard = new Chess::ChessBoard(view, boardWidth, boardHeight, false);
		this->setFixedSize(boardWidth + 130, boardHeight + 220);
		view->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setScene(customChessBoard);
		layout->addWidget(view, 0, 0);

		chessWidget->setLayout(layout);
		chessWidget->show();

		QObject::connect(playButtonWhite, &QPushButton::clicked, customChessBoard, &Chess::ChessBoard::startGameWhite);
		QObject::connect(playButtonBlack, &QPushButton::clicked, customChessBoard, &Chess::ChessBoard::startGameBlack);
	}
}

void MainWindow::openPredefined1ChessWidget()
{
	if (!chessWidget)
	{
		chessWidget = new QWidget(this);
		chessWidget->setWindowTitle("Plateau de jeu");
		QGraphicsView* view = new QGraphicsView(chessWidget);
		Chess::ChessBoard* chessBoard = new Chess::ChessBoard(view, boardWidth, boardHeight, 1);
		this->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setScene(chessBoard);
		chessWidget->show();
	}
}

void MainWindow::openPredefined2ChessWidget()
{
	if (!chessWidget)
	{
		chessWidget = new QWidget(this);
		chessWidget->setWindowTitle("Plateau de jeu");
		QGraphicsView* view = new QGraphicsView(chessWidget);
		Chess::ChessBoard* chessBoard = new Chess::ChessBoard(view, boardWidth, boardHeight, 2);
		this->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setScene(chessBoard);
		chessWidget->show();
	}
}

void MainWindow::openPredefined3ChessWidget()
{
	if (!chessWidget)
	{
		chessWidget = new QWidget(this);
		chessWidget->setWindowTitle("Plateau de jeu");
		QGraphicsView* view = new QGraphicsView(chessWidget);
		Chess::ChessBoard* chessBoard = new Chess::ChessBoard(view, boardWidth, boardHeight, 3);
		this->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setFixedSize(boardWidth + 10, boardHeight + 200);
		view->setScene(chessBoard);
		chessWidget->show();
	}
}