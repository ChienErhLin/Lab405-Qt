#ifndef DETAIL_H
#define DETAIL_H

#include <QDialog>

extern int cnt[24];
extern QString name[24];
extern int cost[24];

namespace Ui {
class detail;
}

class detail : public QDialog
{
    Q_OBJECT

public:
    explicit detail(QWidget *parent = 0);
    ~detail();

private slots:
    void on_pushButton_confirm_2_clicked();
    void receivedetailshow();

    void on_pushButton_order_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::detail *ui;

signals:
    void closedetail();

};

#endif // DETAIL_H
