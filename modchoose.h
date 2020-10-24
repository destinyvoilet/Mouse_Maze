#ifndef MODCHOOSE_H
#define MODCHOOSE_H

#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QWidget>
#include <QLabel>

#include "bigmap.h"



namespace Ui {
class modchoose;
}

class modchoose : public QDialog
{
    Q_OBJECT

public:
    explicit modchoose(QWidget *parent = nullptr);
    ~modchoose();
    int hardnum,timelong;
    void paintEvent(QPaintEvent *event);//绘图事件
    void timerEvent(QTimerEvent *event);


private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void btshow();
    void p8show();
    void backstart();
    void pushshow();
    void p8hide();


private:
    Ui::modchoose *ui;
    BigMap World;

    QLabel *go_Label;
    QMovie *go_Movie;
    QSound *go_Sound;

    int times;



};

#endif // MODCHOOSE_H
