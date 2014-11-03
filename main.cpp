#include "mainwindow.h"
#include"cdatabase.h"
#include <QApplication>
#include<QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString  strDBName = "./studentDB/grade.db";
    CDataBase *db = new CDataBase(strDBName);
    db->Connect2Sqlite();
    MainWindow w;
    w.SetDatabasePointer(db);
    w.show();

    return a.exec();
}
