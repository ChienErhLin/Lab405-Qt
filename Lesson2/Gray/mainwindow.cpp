#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_Original->setText("");
    ui->label_Processed->setText("");
    Image_save = new QImage;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Open_clicked()
{
    QString ImagePath = QFileDialog::getOpenFileName(this,tr("Open Image"),"",tr("Image (*.*)"));
    Image->load(ImagePath);
    pixmap = QPixmap::fromImage(*Image);
    ui->label_Original->setPixmap(pixmap.scaled(ui->label_Original->width(),ui->label_Original->height(),Qt::KeepAspectRatio));
    ui->label_Processed->clear();
}

void MainWindow::on_pushButton_Gray_clicked()
{
    QImage test = *Image;
    QRgb val;
    QColor oldColor;
    for(int x = 0; x < test.width(); x++){
        for(int y=0; y<test.height(); y++){
            oldColor = QColor(test.pixel(x,y));
            int ave = (oldColor.red()+oldColor.green()+oldColor.blue())/3;
            val = qRgb(ave,ave,ave);
            test.setPixel(x,y,val);

        }
    }
    pixmap = QPixmap::fromImage(test);
    ui->label_Processed->setPixmap(QPixmap::fromImage(test).scaled(400,300,Qt::KeepAspectRatio));
}

void MainWindow::on_pushButton_Invert_clicked()
{
    QImage test = *Image;
    QRgb val;
    QColor oldColor;
    for(int x = 0; x < test.width(); x++){
        for(int y=0; y<test.height(); y++){
            oldColor = QColor(test.pixel(x,y));
            val = qRgb(255-oldColor.red(),255-oldColor.green(),255-oldColor.blue());
            test.setPixel(x,y,val);

        }
    }
    pixmap = QPixmap::fromImage(test);
    ui->label_Processed->setPixmap(QPixmap::fromImage(test).scaled(400,300,Qt::KeepAspectRatio));
}

void MainWindow::on_pushButton_Save_clicked()
{

    QString ImagePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "/", tr("JPG (*.jpg);;PNG (*png)"));
    *Image_save = pixmap.toImage();
    Image_save->save(ImagePath);
}


void MainWindow::on_pushButton_Clear_clicked()
{
    ui->label_Original->clear();
    ui->label_Processed->clear();
}
