/********************************************************************************
** Form generated from reading UI file 'chessv3.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSV3_H
#define UI_CHESSV3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessV3Class
{
public:

    void setupUi(QWidget *ChessV3Class)
    {
        if (ChessV3Class->objectName().isEmpty())
            ChessV3Class->setObjectName(QString::fromUtf8("ChessV3Class"));
        ChessV3Class->resize(600, 400);

        retranslateUi(ChessV3Class);

        QMetaObject::connectSlotsByName(ChessV3Class);
    } // setupUi

    void retranslateUi(QWidget *ChessV3Class)
    {
        ChessV3Class->setWindowTitle(QCoreApplication::translate("ChessV3Class", "ChessV3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessV3Class: public Ui_ChessV3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSV3_H
