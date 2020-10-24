/********************************************************************************
** Form generated from reading UI file 'modchoose.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODCHOOSE_H
#define UI_MODCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_modchoose
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *backbt;
    QComboBox *comboBox;
    QPushButton *backbt_2;

    void setupUi(QDialog *modchoose)
    {
        if (modchoose->objectName().isEmpty())
            modchoose->setObjectName(QStringLiteral("modchoose"));
        modchoose->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/\350\200\201\351\274\2401.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        modchoose->setWindowIcon(icon);
        modchoose->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/res/\350\203\214\346\231\2571.jpg);"));
        pushButton = new QPushButton(modchoose);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(590, 170, 131, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-image: url(:/res/\346\214\211\351\222\2561.png);\n"
"selection-background-color: rgb(176, 255, 251);\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;\n"
"\n"
""));
        pushButton_2 = new QPushButton(modchoose);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 260, 131, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-image: url(:/res/\346\214\211\351\222\2561.png);\n"
"selection-background-color: rgb(176, 255, 251);\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;\n"
"\n"
""));
        pushButton_3 = new QPushButton(modchoose);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(590, 350, 131, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-image: url(:/res/\346\214\211\351\222\2561.png);\n"
"selection-background-color: rgb(176, 255, 251);\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;\n"
"\n"
""));
        pushButton_4 = new QPushButton(modchoose);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(590, 450, 131, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-image: url(:/res/\346\214\211\351\222\2561.png);\n"
"selection-background-color: rgb(176, 255, 251);\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;\n"
"\n"
""));
        pushButton_8 = new QPushButton(modchoose);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1070, 590, 141, 71));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-image: url(:/res/\345\274\200\345\247\213\346\270\270\346\210\217 1.0.png);"));
        backbt = new QPushButton(modchoose);
        backbt->setObjectName(QStringLiteral("backbt"));
        backbt->setGeometry(QRect(80, 590, 141, 61));
        backbt->setStyleSheet(QString::fromUtf8("border-image: url(:/res/\350\277\224\345\233\236\347\225\214\351\235\242.png);"));
        comboBox = new QComboBox(modchoose);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(540, 340, 231, 51));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-image: url(:/res/\346\214\211\351\222\2561.png);\n"
"selection-background-color: rgb(176, 255, 251);\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;\n"
"\n"
"\n"
"\n"
" \n"
""));
        comboBox->setMaxVisibleItems(15);
        comboBox->setFrame(false);
        backbt_2 = new QPushButton(modchoose);
        backbt_2->setObjectName(QStringLiteral("backbt_2"));
        backbt_2->setGeometry(QRect(80, 590, 141, 61));
        backbt_2->setStyleSheet(QString::fromUtf8("border-image: url(:/res/\350\277\224\345\233\236\347\225\214\351\235\242.png);"));
        backbt_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_8->raise();
        backbt->raise();
        comboBox->raise();
        pushButton_3->raise();

        retranslateUi(modchoose);

        QMetaObject::connectSlotsByName(modchoose);
    } // setupUi

    void retranslateUi(QDialog *modchoose)
    {
        modchoose->setWindowTitle(QApplication::translate("modchoose", "\351\274\240\351\201\223\350\277\267\345\256\253", Q_NULLPTR));
        pushButton->setText(QApplication::translate("modchoose", "\347\256\200\345\215\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("modchoose", "\344\270\255\347\255\211", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("modchoose", "\345\233\260\351\232\276", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("modchoose", "\345\234\260\347\213\261", Q_NULLPTR));
        pushButton_8->setText(QString());
        backbt->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("modchoose", "<\350\257\267\351\200\211\346\213\251\346\227\266\351\227\264>", Q_NULLPTR)
         << QApplication::translate("modchoose", "1\345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("modchoose", "2\345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("modchoose", "3\345\210\206\351\222\237", Q_NULLPTR)
        );
        backbt_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class modchoose: public Ui_modchoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODCHOOSE_H
