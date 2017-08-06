#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
    void on_pushButton_Open_clicked();

    void on_pushButton_Gray_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_Invert_clicked();

    void on_pushButton_Clear_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
    QImage *Image;
    QImage *Image_save;
};

#endif // MAINWINDOW_H
