#include "cstudentdlg.h"
#include "ui_cstudentdlg.h"

CStudentDlg::CStudentDlg(QString id,CDataBase* db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CStudentDlg)
{
    m_id =id;
    m_db = db;
    ui->setupUi(this);
    this->setWindowFlags(windowFlags()|Qt::WindowCloseButtonHint);
    model = new QStandardItemModel(0,6);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, tr("操作系统"));
    model->setHeaderData(3, Qt::Horizontal, tr("汇编语言"));
    model->setHeaderData(4, Qt::Horizontal, tr("数值分析"));
    model->setHeaderData(5, Qt::Horizontal, tr("计算机组成"));
     ui->tableView->setColumnWidth(0,110);
     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

CStudentDlg::~CStudentDlg()
{
    delete ui;
}

void CStudentDlg::on_exitBtn_clicked()
{
    exit(0);
}

void CStudentDlg::on_showsingle_clicked()
{
    QSqlQuery query;
    QString sql;
    QString sqlGet[6];
    sql = "select * from grade where id ==" + m_id;
    model->removeRows(0,model->rowCount());
    qDebug()<<sql;
    query.exec(sql);
    while(query.next())                                                         //query.next()指向查找到的第一条记录，然后每次后移一条记录
    {
               sqlGet[0]          = query.value(0).toString();      //query.value(0)是id的值
               sqlGet[1]          = query.value(1).toString();
               sqlGet[2]          = query.value(2).toString();
               sqlGet[3]          = query.value(3).toString();
               sqlGet[4]          = query.value(4).toString();
               sqlGet[5]          = query.value(5).toString();
               ui->id->setText(sqlGet[0]);
               ui->name->setText(sqlGet[1]);
               for(int column =0;column < 6;column++)
               {
                           model->setItem(0,column,  new QStandardItem(sqlGet[column]));
               }
               qDebug()<<sqlGet[0]<<sqlGet[1]<<sqlGet[2]<<sqlGet[3]<<sqlGet[4]<<sqlGet[5];//输出值
      }
}

void CStudentDlg::on_showall_clicked()
{
    model->removeRows(0,model->rowCount());
    QSqlQuery query;
    QString sql;
    QString sqlGet[6];
    sql = "select * from grade ";
    qDebug()<<sql;
    query.exec(sql);
    ui->id->setText("11060342");
    ui->name->setText("class grade");
    int i = 0;
    while(query.next())                                                         //query.next()指向查找到的第一条记录，然后每次后移一条记录
    {
               sqlGet[0]          = query.value(0).toString();      //query.value(0)是id的值
               sqlGet[1]          = query.value(1).toString();
               sqlGet[2]          = query.value(2).toString();
               sqlGet[3]          = query.value(3).toString();
               sqlGet[4]          = query.value(4).toString();
               sqlGet[5]          = query.value(5).toString();

               for(int column =0;column < 6;column++)
               {
                           model->setItem(i,column,  new QStandardItem(sqlGet[column]));
               }
               qDebug()<<sqlGet[0]<<sqlGet[1]<<sqlGet[2]<<sqlGet[3]<<sqlGet[4]<<sqlGet[5];//输出值
               i++;
      }

}
