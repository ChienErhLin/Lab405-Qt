#include "mainwindow.h"
#include <QApplication>

//Global Variables
int cnt[24];
QString name[24] = {"烤鮭魚","厚切牛排","羊小排","招牌漢堡","義大利麵","燉飯","薯條","雞塊","洋蔥圈","地瓜球","杏鮑菇","魷魚","招牌沙拉","和風沙拉","千島沙拉","雞肉沙拉","凱薩沙拉","鮭魚沙拉","紅茶","奶茶","可樂","雪碧","咖啡","啤酒"};
int cost[24] = {250,280,260,240,220,230,80,100,120,130,140,150,100,120,120,150,160,180,50,70,70,70,100,150};
bool Cash = false;
bool Credit = false;
QString Category = "Main";
int Pay = 0;
int Sum = 0;
int Sum_show = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    detail d;
    QObject::connect(&w,SIGNAL(showdetailwindow()),&d,SLOT(receivedetailshow()));
    QObject::connect(&d,SIGNAL(closedetail()),&w,SLOT(receivedetailclose()));

    return a.exec();
}
