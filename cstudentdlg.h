#ifndef CSTUDENTDLG_H
#define CSTUDENTDLG_H

#include <QDialog>
#include<cdatabase.h>
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>
#include<QVariant>
#include<QDebug>
#include<QStandardItemModel>
namespace Ui {
class CStudentDlg;
}

class CStudentDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CStudentDlg(QString id,CDataBase* db,QWidget *parent = 0);
    ~CStudentDlg();

private slots:
    void on_exitBtn_clicked();

    void on_showsingle_clicked();

    void on_showall_clicked();

private:
    CDataBase* m_db;
    QString         m_id;
    QStandardItemModel *model;
private:
    Ui::CStudentDlg *ui;

};

#endif // CSTUDENTDLG_H
