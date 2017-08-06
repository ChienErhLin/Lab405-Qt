#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("NTU Fodd Map");
    ui->label_title->setText("NTU Food Map");
    ui->label_Info->setText(tr(""));
    QPixmap back("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/ntumap.png");
    ui->label_background->setPixmap(back.scaled(ui->label_background->width(),ui->label_background->height(),Qt::KeepAspectRatio));
    ui->label_Image->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->pushButton_back->setVisible(false);
    ui->pushButton_1->setStyleSheet("background-color: steelblue; color: white");
    ui->pushButton_1->setGeometry(625,480,80,30);  //活大
    ui->pushButton_2->setStyleSheet("background-color: steelblue; color: white");
    ui->pushButton_2->setGeometry(530,450,80,30);  //小福
    ui->pushButton_3->setStyleSheet("background-color: steelblue; color: white");
    ui->pushButton_3->setGeometry(420,590,80,30);  //大一女
    ui->pushButton_4->setStyleSheet("background-color: steelblue; color: white");
    ui->pushButton_4->setGeometry(750,270,80,30);  //118
    ui->pushButton_5->setStyleSheet("background-color: steelblue; color: white");
    ui->pushButton_5->setGeometry(330,400,80,30);  //公館
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_back_clicked()
{
    //重設
    ui->label_Image->setVisible(false);
    ui->textEdit->setText("");
    ui->textEdit->setVisible(false);
    ui->pushButton_back->setVisible(false);
    ui->pushButton_1->setVisible(true);
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(true);
}

void MainWindow::basic_step(QPixmap img, QString TextPath)
{
    //routine while button click

    //show image
    ui->label_Image->setPixmap(img.scaled(ui->label_Image->width(),ui->label_Image->height(),Qt::KeepAspectRatio));
    //show text
    QFile inputFile(TextPath);
    if(inputFile.exists()){
        if(inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            while(!in.atEnd()){
                QString line = in.readLine();
                ui->textEdit->append(line);
            }
        }
        inputFile.close();
    }
    else
        QMessageBox::warning(0, 0, "NO TEXT FILE FOUND!!");
    //show & hide button
    ui->pushButton_back->setVisible(true);
    ui->pushButton_1->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->label_Image->setVisible(true);
}

void MainWindow::on_pushButton_1_clicked()
{
    //image path
    QPixmap img("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/img1.jpg");
    //text path
    QString TextPath("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/text1.txt");
    basic_step(img, TextPath);
}

void MainWindow::on_pushButton_2_clicked()
{
    //image path
    QPixmap img("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/img2.jpg");
    //text path
    QString TextPath("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/text2.txt");
    basic_step(img, TextPath);
}

void MainWindow::on_pushButton_3_clicked()
{
    //image path
    QPixmap img("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/img3.jpg");
    //text path
    QString TextPath("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/text3.txt");
    basic_step(img, TextPath);
}

void MainWindow::on_pushButton_4_clicked()
{
    //image path
    QPixmap img("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/img4.jpg");
    //text path
    QString TextPath("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/text4.txt");
    basic_step(img, TextPath);
}

void MainWindow::on_pushButton_5_clicked()
{
    //image path
    QPixmap img("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/img5.jpg");
    //text path
    QString TextPath("C:/Users/admin/Desktop/cel/Qt/Mini_Wiki/text5.txt");
    basic_step(img, TextPath);
}

