#include "stdafx.h"
#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    int boardWidth = 720;
    int boardHeight = 720;

    MainWindow mainWindow(boardWidth, boardHeight);

    mainWindow.show();

    return application.exec();
}