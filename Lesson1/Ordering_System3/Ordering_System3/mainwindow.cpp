#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QtMath>
#include "detail.h"

QString Str_Category = "Main";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //background
    this->setWindowTitle("NTU Ordering System 點餐系統");
    ui->centralWidget->setStyleSheet("background-color: white");
    //Logo
    QPixmap logo(":/rec/Picture/logo.png");
    ui->label_Logo->setPixmap(logo.scaled(180,180,Qt::KeepAspectRatio));
    //List
    QListWidgetItem *Category1 = new QListWidgetItem(QIcon(":/rec/Picture/Burger.png"), "主餐");
    ui->listWidget_Category->addItem(Category1);
    QListWidgetItem *Category2 = new QListWidgetItem(QIcon(":/rec/Picture/FrenchFries.png"), "炸物");
    ui->listWidget_Category->addItem(Category2);
    QListWidgetItem *Category3 = new QListWidgetItem(QIcon(":/rec/Picture/Salad.png"), "沙拉");
    ui->listWidget_Category->addItem(Category3);
    QListWidgetItem *Category4 = new QListWidgetItem(QIcon(":/rec/Picture/CocaCola.png"), "飲料");
    ui->listWidget_Category->addItem(Category4);
    Category1->setSizeHint(QSize(Category1->sizeHint().width(), 40));
    Category2->setSizeHint(QSize(Category2->sizeHint().width(), 40));
    Category3->setSizeHint(QSize(Category3->sizeHint().width(), 40));
    Category4->setSizeHint(QSize(Category4->sizeHint().width(), 40));
    ui->listWidget_Category->setIconSize(QSize(45,45));
    ui->listWidget_Category->setStyleSheet("font: 12pt;");
    //右上角
    ui->label_Sum->setText("共 0 元");
    ui->label_Sum->setAlignment(Qt::AlignCenter);
    ui->pushButton_Detail->setText("點餐明細");
    //ui->pushButton_Detail->setStyleSheet("background-color: rgb(92, 151, 191);");
    ui->pushButton_Pay->setText("確認付款");
    //ui->pushButton_Pay->setStyleSheet("background-color: rgb(92, 151, 191);");
    ui->pushButton_Cancel->setText("全部取消");
    //ui->pushButton_Cancel->setStyleSheet("background-color: rgb(92, 151, 191);");
    //右下角
    showMain();
    ui->spinBox_1->setSuffix(" 份");
    ui->spinBox_2->setSuffix(" 份");
    ui->spinBox_3->setSuffix(" 份");
    ui->spinBox_4->setSuffix(" 份");
    ui->spinBox_5->setSuffix(" 份");
    ui->spinBox_6->setSuffix(" 份");
    ui->label_Main->setText("請點選所需餐點數量，並選擇付款方式，可在上方「點餐明細」確認所有餐點。");
    ui->label_Main->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Detail_clicked()
{
    if(ui->radioButton_Cash->isChecked() || ui->radioButton_Credit->isChecked()){
        emit showdetailwindow();
    }
    else{
        QMessageBox::warning(this,tr("尚未選擇付款方式"),tr("請您先選擇付款方式"));
    }
}

void MainWindow::on_pushButton_Pay_clicked()
{
    if(ui->radioButton_Cash->isChecked() || ui->radioButton_Credit->isChecked()){
        QMessageBox::information(this,tr("確認付款"),"您此次點餐共 "+ QString::number(Sum_show) +" 元",tr("確認付款"));
        cancel();
    }
    else{
        QMessageBox::warning(this,tr("尚未選擇付款方式"),tr("請您先選擇付款方式"));
    }
}

void MainWindow::on_pushButton_Cancel_clicked()
{
    //全部取消
    cancel();
}

void MainWindow::on_listWidget_Category_clicked()
{
    //依據客人選擇的餐點分類，顯示不同的菜單
    //點哪一個
    Str_Category = ui->listWidget_Category->currentItem()->text();
    if(Str_Category == "主餐"){
        Category = "Main";
        showMain();
    }
    else if(Str_Category == "炸物"){
        Category = "Fried";
        showFried();
    }
    else if(Str_Category == "沙拉"){
        Category = "Salad";
        showSalad();
    }
    else if(Str_Category == "飲料"){
        Category = "Drink";
        showDrink();
    }
    else{
        Category = "Main";
        showMain();
    }
}

void MainWindow::on_spinBox_1_valueChanged(int arg1)
{

    if(Category == "Main"){
        int change = arg1 - cnt[0];
        Sum += change * 250;
        cnt[0]= arg1;
    }
    else if(Category == "Fried"){
        int change = arg1 - cnt[6];
        Sum += change * 80;
        cnt[6]= arg1;
    }
    else if(Category == "Salad"){
        int change = arg1 - cnt[12];
        Sum += change * 100;
        cnt[12]= arg1;
    }
    else if(Category == "Drink"){
        int change = arg1 - cnt[18];
        Sum += change * 50;
        cnt[18]= arg1;
    }
    checkSum();

}

void MainWindow::on_spinBox_2_valueChanged(int arg2)
{
    if(Category == "Main"){
        int change = (arg2) - cnt[1];
        Sum += change * 280;
        cnt[1]= arg2;
    }
    else if(Category == "Fried"){
        int change = arg2 - cnt[7];
        Sum += change * 100;
        cnt[7]= arg2;
    }
    else if(Category == "Salad"){
        int change = arg2 - cnt[13];
        Sum += change * 120;
        cnt[13]= arg2;
    }
    else if(Category == "Drink"){
        int change = arg2 - cnt[19];
        Sum += change * 70;
        cnt[19]= arg2;
    }
    checkSum();
}

void MainWindow::on_spinBox_3_valueChanged(int arg3)
{
    if(Category == "Main"){
        int change = arg3 - cnt[2];
        Sum += change * 260;
        cnt[2]= arg3;
    }
    else if(Category == "Fried"){
        int change = arg3 - cnt[8];
        Sum += change * 120;
        cnt[8]= arg3;
    }
    else if(Category == "Salad"){
        int change = arg3 - cnt[14];
        Sum += change * 120;
        cnt[14]= arg3;
    }
    else if(Category == "Drink"){
        int change = arg3 - cnt[20];
        Sum += change * 70;
        cnt[20]= arg3;
    }
    checkSum();
}

void MainWindow::on_spinBox_4_valueChanged(int arg4)
{
    if(Category == "Main"){
        int change = arg4 - cnt[3];
        Sum += change * 240;
        cnt[3]= arg4;
    }
    else if(Category == "Fried"){
        int change = arg4 - cnt[9];
        Sum += change * 130;
        cnt[9]= arg4;
    }
    else if(Category == "Salad"){
        int change = arg4 - cnt[15];
        Sum += change * 150;
        cnt[15]= arg4;
    }
    else if(Category == "Drink"){
        int change = arg4 - cnt[21];
        Sum += change * 70;
        cnt[21]= arg4;
    }
    checkSum();
}

void MainWindow::on_spinBox_5_valueChanged(int arg5)
{
    if(Category == "Main"){
        int change = arg5 - cnt[4];
        Sum += change * 220;
        cnt[4]= arg5;
    }
    else if(Category == "Fried"){
        int change = arg5 - cnt[10];
        Sum += change * 140;
        cnt[10]= arg5;
    }
    else if(Category == "Salad"){
        int change = arg5 - cnt[16];
        Sum += change * 160;
        cnt[16]= arg5;
    }
    else if(Category == "Drink"){
        int change = arg5 - cnt[22];
        Sum += change * 100;
        cnt[22]= arg5;
    }
    checkSum();
}

void MainWindow::on_spinBox_6_valueChanged(int arg6)
{
    if(Category == "Main"){
        int change = arg6 - cnt[5];
        Sum += change * 230;
        cnt[5]= arg6;
    }
    else if(Category == "Fried"){
        int change = arg6 - cnt[11];
        Sum += change * 150;
        cnt[11]= arg6;
    }
    else if(Category == "Salad"){
        int change = arg6 - cnt[17];
        Sum += change * 180;
        cnt[17]= arg6;
    }
    else if(Category == "Drink"){
        int change = arg6 - cnt[23];
        Sum += change * 150;
        cnt[23]= arg6;
    }
    checkSum();
}

void MainWindow::showMain()
{
    QPixmap p1(":/rec/Picture/Salmon.png");
    ui->label_p1->setPixmap(p1.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n1->setText(" 烤鮭魚 $250");
    ui->spinBox_1->setValue(cnt[0]);
    QPixmap p2(":/rec/Picture/Steak.jpg");
    ui->label_p2->setPixmap(p2.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n2->setText(" 厚切牛排 $280");
    ui->spinBox_2->setValue(cnt[1]);
    QPixmap p3(":/rec/Picture/lamb.jpg");
    ui->label_p3->setPixmap(p3.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n3->setText(" 羊小排 $260");
    ui->spinBox_3->setValue(cnt[2]);
    QPixmap p4(":/rec/Picture/Burger.png");
    ui->label_p4->setPixmap(p4.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n4->setText(" 招牌漢堡 $240");
    ui->spinBox_4->setValue(cnt[3]);
    QPixmap p5(":/rec/Picture/pasta.jpg");
    ui->label_p5->setPixmap(p5.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n5->setText(" 義大利麵 $220");
    ui->spinBox_5->setValue(cnt[4]);
    QPixmap p6(":/rec/Picture/Risotto.jpg");
    ui->label_p6->setPixmap(p6.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n6->setText(" 燉飯 $230");
    ui->spinBox_6->setValue(cnt[5]);
}
void MainWindow::showFried()
{
    QPixmap p1(":/rec/Picture/FrenchFries.png");
    ui->label_p1->setPixmap(p1.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n1->setText(" 薯條 $80");
    ui->spinBox_1->setValue(cnt[6]);
    QPixmap p2(":/rec/Picture/Chicken.jpg");
    ui->label_p2->setPixmap(p2.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n2->setText(" 雞塊 $100");
    ui->spinBox_2->setValue(cnt[7]);
    QPixmap p3(":/rec/Picture/Onion.jpg");
    ui->label_p3->setPixmap(p3.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n3->setText(" 洋蔥圈 $120");
    ui->spinBox_3->setValue(cnt[8]);
    QPixmap p4(":/rec/Picture/Ball.jpg");
    ui->label_p4->setPixmap(p4.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n4->setText(" 地瓜球 $130");
    ui->spinBox_4->setValue(cnt[9]);
    QPixmap p5(":/rec/Picture/mushroom.jpg");
    ui->label_p5->setPixmap(p5.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n5->setText(" 杏鮑菇 $140");
    ui->spinBox_5->setValue(cnt[10]);
    QPixmap p6(":/rec/Picture/Risotto.jpg");
    ui->label_p6->setPixmap(p6.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n6->setText(" 魷魚 $150");
    ui->spinBox_6->setValue(cnt[11]);
}

void MainWindow::showSalad()
{
    QPixmap p1(":/rec/Picture/salad1.jpg");
    ui->label_p1->setPixmap(p1.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n1->setText(" 招牌沙拉 $100");
    ui->spinBox_1->setValue(cnt[12]);
    QPixmap p2(":/rec/Picture/salad2.jpg");
    ui->label_p2->setPixmap(p2.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n2->setText(" 和風沙拉 $120");
    ui->spinBox_2->setValue(cnt[13]);
    QPixmap p3(":/rec/Picture/salad3.jpg");
    ui->label_p3->setPixmap(p3.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n3->setText(" 千島沙拉 $120");
    ui->spinBox_3->setValue(cnt[14]);
    QPixmap p4(":/rec/Picture/salad4.jpg");
    ui->label_p4->setPixmap(p4.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n4->setText(" 雞肉沙拉 $150");
    ui->spinBox_4->setValue(cnt[15]);
    QPixmap p5(":/rec/Picture/salad5.jpg");
    ui->label_p5->setPixmap(p5.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n5->setText(" 凱薩沙拉 $160");
    ui->spinBox_5->setValue(cnt[16]);
    QPixmap p6(":/rec/Picture/salad6.jpg");
    ui->label_p6->setPixmap(p6.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n6->setText(" 鮭魚沙拉 $180");
    ui->spinBox_6->setValue(cnt[17]);
}

void MainWindow::showDrink()
{
    QPixmap p1(":/rec/Picture/tea.jpg");
    ui->label_p1->setPixmap(p1.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n1->setText(" 紅茶 $50");
    ui->spinBox_1->setValue(cnt[18]);
    QPixmap p2(":/rec/Picture/milktea.jpg");
    ui->label_p2->setPixmap(p2.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n2->setText(" 奶茶 $70");
    ui->spinBox_2->setValue(cnt[19]);
    QPixmap p3(":/rec/Picture/CocaCola.png");
    ui->label_p3->setPixmap(p3.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n3->setText(" 可樂 $70");
    ui->spinBox_3->setValue(cnt[20]);
    QPixmap p4(":/rec/Picture/sprite.jpg");
    ui->label_p4->setPixmap(p4.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n4->setText(" 雪碧 $70");
    ui->spinBox_4->setValue(cnt[21]);
    QPixmap p5(":/rec/Picture/coffee.jpg");
    ui->label_p5->setPixmap(p5.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n5->setText(" 咖啡 $100");
    ui->spinBox_5->setValue(cnt[22]);
    QPixmap p6(":/rec/Picture/bear.jpg");
    ui->label_p6->setPixmap(p6.scaled(130,130,Qt::KeepAspectRatio));
    ui->label_n6->setText(" 啤酒 $150");
    ui->spinBox_6->setValue(cnt[23]);
}

void MainWindow::on_radioButton_Cash_clicked()
{
    checkSum();
    extern bool Cash, Credit;
    Cash = true;
    Credit = false;
}

void MainWindow::on_radioButton_Credit_clicked()
{
    checkSum();
    extern bool Cash, Credit;
    Credit = true;
    Cash = false;
}

//計算金額
void MainWindow::checkSum()
{
    if(ui->radioButton_Cash->isChecked()){
        if(Sum!=0) Sum_show = Sum - 30;
    }
    else if(ui->radioButton_Credit->isChecked()){
        Sum_show = Sum * 0.9;
    }
    else{
        Sum_show = Sum;
    }
    ui->label_Sum->setText("共 "+QString::number(Sum_show)+" 元");
}

void MainWindow::cancel(){
    ui->spinBox_1->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->spinBox_5->setValue(0);
    ui->spinBox_6->setValue(0);
    ui->radioButton_Cash->setAutoExclusive(false);
    ui->radioButton_Credit->setAutoExclusive(false);
    ui->radioButton_Cash->setChecked(false);
    ui->radioButton_Credit->setChecked(false);
    ui->radioButton_Cash->setAutoExclusive(true);
    ui->radioButton_Credit->setAutoExclusive(true);
    for (int i = 0; i<24 ; i++){
        cnt[i] = 0;
    }
    Sum = 0;
    ui->label_Sum->setText("共 0 元");


}

void MainWindow::receivedetailclose(){
    cancel();
}
