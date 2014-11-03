#include "cdatabase.h"

CDataBase::CDataBase()
{
    m_databaseName = "./studentDB/grade.db";
}
CDataBase::CDataBase(QString dbname)
{
    m_databaseName = dbname;
}
bool CDataBase::Connect2Sqlite()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_databaseName);
    //check if the database file was exist,send error message to user.
    if(!QFile::exists(m_databaseName))
    {
        QString msg;
        msg = m_databaseName + ":file didn't find,please check it!";
        QMessageBox::information(NULL,"Error",msg,QMessageBox::Yes , QMessageBox::Yes);
        return false;
    }
    // if database open failed ,return false;
    if(!m_db.open())
        return false;
    // the database open successfully,return true;
    return true;
}
QString CDataBase::Login(QString id, QString password, bool bStudent)
{
    QSqlQuery query;
    QString sql;
    QString idGet,passGet,nameGet;
    // the bStudent value defines which table will be query.
    if(bStudent){
        sql = "select id,password,name from studentlog where id ==" + id;
        qDebug()<<sql;
    }
    else{
         sql = "select id,password,name from managerlog where id ==\""+ id +"\"";
         qDebug()<<sql;
    }
     query.exec(sql);
    while(query.next())//query.next()指向查找到的第一条记录，然后每次后移一条记录
    {
               idGet            = query.value(0).toString();//query.value(0)是id的值
               passGet       = query.value(1).toString();
               nameGet      = query.value(2).toString();
               qDebug()<< idGet << passGet <<nameGet;//输出值
      }
    // if username and password was right return user name
    if(password == passGet)
        return nameGet;
    // the id or password was wrong , return string "Error"
    return "Error";
}
