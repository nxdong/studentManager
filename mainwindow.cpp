#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_bStudent = true;  //set login user default student
    ui->radioBtn_student->setChecked(true);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::SetDatabasePointer(CDataBase *db)
{
    m_pDB =db;
}

void MainWindow::on_radioBtn_student_clicked()
{
    m_bStudent = true;
    ui->radioBtn_student->setChecked(true);
}
void MainWindow::on_radioBtn_manager_clicked()
{
    m_bStudent = false;
    ui->radioBtn_manager->setChecked(true);
}

void MainWindow::on_Login_OK_clicked()
{
    QString id,password;
    id = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    QString nameget;
    nameget = m_pDB->Login(id,password,m_bStudent);
    if(nameget =="Error")
    {
        QString msg;
        msg = "Your username or password were invalidation.Please check it";
        QMessageBox::information(NULL,"Error",msg,QMessageBox::Yes , QMessageBox::Yes);
        return;
    }
    qDebug()<<nameget;
    if(m_bStudent)
    {
    CStudentDlg * pStuDlg;
    pStuDlg = new CStudentDlg(id,m_pDB);
    pStuDlg->show();
    this->close();
    }
    else{
        //todo:add mananger dialog
    }
}

void MainWindow::on_Login_CANCEL_clicked()
{
    exit(0);
}
