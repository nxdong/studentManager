#include "cdatabase.h"

CDataBase::CDataBase()
{
    m_databaseName = "./studentDB/grade.db";
}
CDataBase::CDataBase(QString *dbname)
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
        msg.sprintf("%s:file didn't find,please check it!",m_databaseName);
        QMessageBox::information(this,"Error",msg);
        return false;
    }
    // if database open failed ,return false;
    if(!m_db.open())
        return false;
    // the database open successfully,return true;
    return true;
}
