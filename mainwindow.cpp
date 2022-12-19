#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db"); //файл создасться в папке с программой
    if(db.open())
    {
        qDebug("open DB");
    }
    else
    {
        qDebug("no open DB");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Weighing(weight INT, date TEXT);"); //создаём sql запрос, создаём таблицу Weighing

    model = new QSqlTableModel(this, db);
    model->setTable("Weighing");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    model->insertRow(model->rowCount());

}


void MainWindow::on_pushButton_2_clicked()
{
     model->removeRow(row); // УДАЛЕНИЕ ТАБЛИЦЫ

}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

