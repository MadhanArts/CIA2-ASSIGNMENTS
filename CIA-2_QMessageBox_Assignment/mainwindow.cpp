#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu* menu = new QMenu("Menu", this);
    menu->addAction("First");
    menu->addAction("Second");
    menu->addAction("Third");
    ui->menuButton->setMenu(menu);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_informationButton_clicked()
{
    QMessageBox::information(this, "MADHAN 212218104104", "THIS IS INFORMATION BOX");
}

void MainWindow::on_questionButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "MADHAN", "Do you like apples?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QMessageBox::information(this, "APPLE", "YES");
      } else {
        QMessageBox::information(this, "APPLE", "NO");
      }

}

void MainWindow::on_criticalButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Custom message", "This is custom message", QMessageBox::Yes|QMessageBox::YesToAll|QMessageBox::No|QMessageBox::NoToAll);
    if(reply == QMessageBox::YesToAll)
    {
        QMessageBox::warning(this, "Message Display", "Display the message with warning as YesToAll");
    }
    else if(reply == QMessageBox::NoToAll)
    {
        QMessageBox::warning(this, "Message Display", "Dont the message with warning as NoToAll");
    }
    else
    {
        qDebug() <<"Nothing is Display";
    }
}

void MainWindow::on_warningButton_clicked()
{
     QMessageBox::warning(this, "Critical Message", "This is warning message");
}

void MainWindow::on_switchImageButton_clicked()
{
    static int i = 0;
    i = i % 2;
    if(i%2 == 0)
    {
        QPixmap pixmap("E:/QtCreator/power_on_image.jpg");
        QIcon buttonIcon(pixmap);
        ui->switchImageButton->setIcon(buttonIcon);
        ui->switchImageButton->setIconSize(QSize(ui->switchImageButton->width(), ui->switchImageButton->height()));
        qDebug() << "Button Checked --ON--";
        i++;

    }
    else
    {
        QPixmap pixmap("E:/QtCreator/power_off_image.jpg");
        QIcon buttonIcon(pixmap);
        ui->switchImageButton->setIcon(buttonIcon);
        ui->switchImageButton->setIconSize(QSize(ui->switchImageButton->width(), ui->switchImageButton->height()));
        qDebug() << "Button Checked --OFF--";
        i++;
    }
}

void MainWindow::on_menuButton_clicked()
{

}
