#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>
#include <QFile>
#include <QGroupBox>
#include "detail.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

extern int cnt[24], Sum;
extern QString Str_Category, Category;
extern int Sum_show;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Detail_clicked();

    void on_pushButton_Pay_clicked();

    void on_pushButton_Cancel_clicked();

    void on_listWidget_Category_clicked();

    void showMain();

    void showFried();

    void showSalad();

    void showDrink();

    void on_spinBox_1_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg2);

    void on_spinBox_3_valueChanged(int arg3);

    void on_spinBox_4_valueChanged(int arg4);

    void on_spinBox_5_valueChanged(int arg5);

    void on_spinBox_6_valueChanged(int arg6);

    void on_radioButton_Cash_clicked();

    void on_radioButton_Credit_clicked();

    void checkSum();

    void cancel();

    void receivedetailclose();

signals:
    void showdetailwindow();

private:
    Ui::MainWindow *ui;
    detail detail;
};

#endif // MAINWINDOW_H
