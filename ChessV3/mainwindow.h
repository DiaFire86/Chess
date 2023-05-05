#pragma once

#include <QtWidgets/QGraphicsView>
#include <QPushButton>
#include "chessboard.h"

class MainWindow : public QWidget
{
public:
	MainWindow(int width, int height);
	~MainWindow() { if (chessWidget != nullptr) { delete chessWidget; } }

private:
	QWidget* chessWidget = nullptr;
	int boardWidth = 0;
	int boardHeight = 0;

	void openRegularChessWidget();
	void openCustomChessWidget();
	void openPredefined1ChessWidget();
	void openPredefined2ChessWidget();
	void openPredefined3ChessWidget();
};