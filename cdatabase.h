#ifndef CDATABASE_H
#define CDATABASE_H
#include<QtSql/QSqlDatabase>
#include<QFile>
#include<QMessageBox>
#include<QSqlQuery>
#include<QVariant>
#include<QDebug>
class CDataBase
{
public:
    CDataBase();
    CDataBase(QString dbname);
    ~CDataBase();
public:
    bool Connect2Sqlite();
    QString Login(QString id,QString password,bool bStudent);
public://members
    QString             m_databaseName;
    QSqlDatabase m_db;

};

#endif // CDATABASE_H
