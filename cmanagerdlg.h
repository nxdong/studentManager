#ifndef CMANAGERDLG_H
#define CMANAGERDLG_H

#include <QDialog>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include <QTableView>
#include<QMessageBox>
#include <QSqlError>
#include <QInputDialog>
#include"cdatabase.h"
namespace Ui {
class CManagerDlg;
}

class CManagerDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CManagerDlg(QString id,CDataBase* db,QWidget *parent = 0);
    ~CManagerDlg();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    QSqlTableModel *model;
    CDataBase           *m_db;
    QString                 m_id;
private:
    Ui::CManagerDlg *ui;
};

#endif // CMANAGERDLG_H
