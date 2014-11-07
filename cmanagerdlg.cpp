#include "cmanagerdlg.h"
#include "ui_cmanagerdlg.h"

CManagerDlg::CManagerDlg(QString id, CDataBase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CManagerDlg)
{
    m_id = id;
    m_db = db;
    ui->setupUi(this);
    model = new QSqlTableModel(NULL, m_db->m_db);
    model->setTable("grade");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
   // model->removeColumn(0); // don't show the ID
    model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, tr("操作系统"));
    model->setHeaderData(3, Qt::Horizontal, tr("汇编语言"));
    model->setHeaderData(4, Qt::Horizontal, tr("数值分析"));
    model->setHeaderData(5, Qt::Horizontal, tr("计算机组成"));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,110);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

CManagerDlg::~CManagerDlg()
{
    delete ui;
}

//  change button
void CManagerDlg::on_pushButton_2_clicked()
{
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}
// submit change
void CManagerDlg::on_pushButton_3_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) // 提交所有被修改的数据到数据库中
    {
        model->database().commit(); //提交成功，事务将真正修改数据库数据
    } else {
        model->database().rollback();  //提交失败，事务回滚
        QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(model->lastError().text()));
    }
        model->revertAll(); //撤销修改
}

void CManagerDlg::on_pushButton_clicked()
{
    exit(0);
}
