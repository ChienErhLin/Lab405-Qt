#include "detail.h"
#include "ui_detail.h"
#include <QList>
#include <QDebug>
#include <QMessageBox>

detail::detail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detail)
{
    ui->setupUi(this);
    this->setWindowTitle("點餐明細");
    //background
    this->setStyleSheet("background-color:white;");
    //Logo
    QPixmap logo(":/rec/Picture/logo.png");
    ui->label_logo->setPixmap(logo.scaled(180,180,Qt::KeepAspectRatio));
    //table
    ui->label_name->setAlignment(Qt::AlignCenter);
    ui->label_cnt->setAlignment(Qt::AlignCenter);
    ui->label_money->setAlignment(Qt::AlignCenter);
    ui->pushButton_confirm->setText("確認付款");
    ui->pushButton_order->setText("繼續點餐");
    ui->label_Pay->setAlignment(Qt::AlignCenter);
    ui->label_Pay3->setAlignment(Qt::AlignCenter);
    ui->label_Pay2->setText("");
    ui->label_Sum->setAlignment(Qt::AlignCenter);
}

//顯示點餐明細這個頁面
void detail::receivedetailshow()
{
    extern int cnt[24];
    int Sum_detail = 0;
    //呈現點餐明細
    int order_cnt = 1;
    for(int a = 0; a < 24; a++){
        if(cnt[a] > 0){
            QLabel *label_name = new QLabel();
            label_name->setText(name[a]);
            label_name->setAlignment(Qt::AlignCenter);
            ui->gridLayout_detail->addWidget(label_name,order_cnt-1,0);
            QLabel *label_cnt = new QLabel();
            label_cnt->setText(QString::number(cnt[a]));
            label_cnt->setAlignment(Qt::AlignCenter);
            ui->gridLayout_detail->addWidget(label_cnt,order_cnt-1,1);
            QLabel *label_cost = new QLabel();
            label_cost->setText(QString::number(cnt[a]*cost[a]));
            label_cost->setAlignment(Qt::AlignCenter);
            ui->gridLayout_detail->addWidget(label_cost,order_cnt-1,2);
            //QPushButton *pushButton_cancel = new QPushButton("取消餐點");
            //ui->gridLayout_detail->addWidget(pushButton_cancel,order_cnt-1,3);
            Sum_detail += cnt[a]*cost[a];
            order_cnt ++;

        }
    }
    extern bool Cash, Credit;
    if(Cash){
        ui->label_Pay->setText("現金付款");
        ui->label_Pay3->setText("-30");
        Sum_detail -= 30;
    }
    else if(Credit){
        ui->label_Pay->setText("刷卡付款");
        ui->label_Pay3->setText("-10%");
        Sum_detail = Sum_detail * 0.9;
    }
    ui->label_Sum->setText("共 " +QString::number(Sum_detail)+" 元");
    //更改大小
    this->setFixedHeight(180+order_cnt*25);
    this->show();
}


detail::~detail()
{
    delete ui;
}

void detail::on_pushButton_order_clicked()
{
    this->close();
}

void detail::on_pushButton_confirm_clicked()
{
    extern int Sum_show;
    QMessageBox::information(this,tr("確認付款"),"您此次點餐共 "+ QString::number(Sum_show) +" 元",tr("確認付款"));
    emit closedetail();
    this->close();
}
