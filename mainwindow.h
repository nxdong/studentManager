#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"cdatabase.h"
#include"cstudentdlg.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    CDataBase* m_pDB;
    // if the user is student,the bool value is true.the mananger is false.
    bool              m_bStudent;
public:
    void SetDatabasePointer(CDataBase* db);
private slots:
    void on_radioBtn_student_clicked();

    void on_radioBtn_manager_clicked();

    void on_Login_OK_clicked();

    void on_Login_CANCEL_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
