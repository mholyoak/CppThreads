#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CThreadTest.h"
#include <QDebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_countButton_clicked()
{
    qDebug() << "Running Threads to Count";

    CThreadTest myThreadTest;

    myThreadTest.RunThreadCounters(ui->mutexCheckBox->checkState() == Qt::CheckState::Checked);

    ui->listWidget->clear();

    for(int i = 0; i < myThreadTest.GetNumbersCounted(); i++)
    {
        std::string newItem;
        newItem = std::to_string(myThreadTest.GetNumber(i)) + "\t" + std::to_string(myThreadTest.GetThreadNumber(i));

        ui->listWidget->addItem(newItem.c_str());
    }
}

