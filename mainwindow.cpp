#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iomanip>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long double number1=0, number2=0, activeNumber=1, maxNumber=92233720368540, minNumber=-92233720368540, addition=0, subtraction=0, division=0, multiplication=0;

void MainWindow::overFlowError(){
    ui->label->setText("OverFlow Error");
}

int MainWindow::factorial(int x){
    for(int i = x-1; i > 0; i--){
        x *= i;
    }
    return x;
}

std::string MainWindow::decimallogic(std::string x)
{
    int d = x.size();
    for(int i = x.size()-1; i >= 0; i--){
        if(x[i] == '.'){
               x.erase(x.begin()+(d-(d-i)));
               return x;
        }else if(x[i] != '0'){
               return x;
        }else if(x[i] == '0'){
            x.erase(x.begin()+(d-(d-i)));
        }
    }
    return x;
}

void MainWindow::numberfunction(int x){
    if(activeNumber==1){
        if(maxNumber/10 < number1*10+x){
            overFlowError();
            return;
        }
            number1=(number1*10) + x;
            std::string string = std::to_string(number1);
            QString stringy = QString::fromStdString(decimallogic(string));
            ui->label->setText(stringy);

    }else if(activeNumber==2){
        if(maxNumber/10 < number2*10 + x){
            overFlowError();
            return;
        }
            number2=(number2*10) + x;
            std::string string = std::to_string(number2);
            QString stringy = QString::fromStdString(decimallogic(string));
            ui->label->setText(stringy);
    }
}


void MainWindow::on_pushButton_22_pressed()
{
    //The Sqaure Root Button
    ui->pushButton_22->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    if(activeNumber==1){
        number1 = sqrt(number1);
        std::string string = std::to_string(number1);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
    }else if(activeNumber==2){
        number2 = sqrt(number2);
        std::string string = std::to_string(number2);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
    }
}
void MainWindow::on_pushButton_22_released()
{
    ui->pushButton_22->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}
void MainWindow::on_pushButton_23_clicked()
{
    ui->pushButton_23->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    MainWindow::close();
}

void MainWindow::on_pushButton_21_pressed()
{
    //The Factorial Button
    ui->pushButton_21->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    if(activeNumber==1){
        number1=factorial(number1);
        if(number1/100000 > maxNumber/100000){
            overFlowError();
        }else{
            std::string string = std::to_string(number1);
            QString stringy = QString::fromStdString(decimallogic(string));
            ui->label->setText(stringy);
        }

    }else if(activeNumber==2){
        number2=factorial(number2);
        if(number2/100000 > maxNumber/100000){
            overFlowError();
        }else{
            std::string string = std::to_string(number2);
            QString stringy = QString::fromStdString(decimallogic(string));
            ui->label->setText(stringy);
        }

    }
}

void MainWindow::on_pushButton_25_pressed()
{
    //The Clear Button
    ui->pushButton_25->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    if(activeNumber==1){
        number1=0;
        std::string string = std::to_string(number1);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
    }else if(activeNumber==2){
        number2=0;
        std::string string = std::to_string(number2);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
    }
}

void MainWindow::on_pushButton_4_pressed()
{
    //The 4 Button
    ui->pushButton_4->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(4);
}

void MainWindow::on_pushButton_3_pressed()
{
    //The 5 Button
    ui->pushButton_3->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(5);
}

void MainWindow::on_pushButton_17_pressed()
{
    //The 6 Button
    ui->pushButton_17->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(6);
}

void MainWindow::on_pushButton_15_pressed()
{
    //The Division Button
    ui->pushButton_15->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    activeNumber=2;
    division=1;
}

void MainWindow::on_pushButton_5_pressed()
{
    //The 7 Button
    ui->pushButton_5->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(7);
}

void MainWindow::on_pushButton_2_pressed()
{
    //The 8 Button
    ui->pushButton_2->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(8);
}

void MainWindow::on_pushButton_18_pressed()
{
    //The 9 Button
    ui->pushButton_18->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black; background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(9);
}

void MainWindow::on_pushButton_19_pressed()
{
    //The Multiplication Button
    ui->pushButton_19->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    multiplication=1;
    activeNumber=2;
}

void MainWindow::on_pushButton_8_pressed()
{
    //The 1 Button
    ui->pushButton_8->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px;  border-color: black; background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(1);

}

void MainWindow::on_pushButton_9_pressed()
{
    //The 2 Button
    ui->pushButton_9->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px;  border-color: black; background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(2);
}

void MainWindow::on_pushButton_13_pressed()
{
    //The 3 Button
    ui->pushButton_13->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(3);
}

void MainWindow::on_pushButton_14_pressed()
{
    //The subtraction Button
    ui->pushButton_14->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    subtraction=1;
    activeNumber=2;
}

void MainWindow::on_pushButton_11_pressed()
{
    //The 0 Button
    ui->pushButton_11->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    numberfunction(0);
}

void MainWindow::on_pushButton_12_pressed()
{
    //The equals Button
    ui->pushButton_12->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    if(addition){
        number1 = number1+number2;
        std::string string = std::to_string(number1);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
        addition=0;
        number2=0;
        activeNumber=1;
    }else if(multiplication){
        number1 = number1*number2;
        std::string string = std::to_string(number1);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
        multiplication=0;
        number2=0;
        activeNumber=1;
    }else if(subtraction){
        number1 = number1-number2;
        std::string string = std::to_string(number1);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
        subtraction=0;
        number2=0;
        activeNumber=1;
    }else if(division){
        number1 = number1/number2;
        std::string string = std::to_string(number1);
        QString stringy = QString::fromStdString(decimallogic(string));
        ui->label->setText(stringy);
        subtraction=0;
        number2=0;
    }
}

void MainWindow::on_pushButton_16_pressed()
{
    //The Clear Button
    ui->pushButton_16->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    number1=0, number2=0, activeNumber=1;
    std::string string = std::to_string(number1);
    QString stringy = QString::fromStdString(decimallogic(string));
    ui->label->setText(stringy);
}

void MainWindow::on_pushButton_20_pressed()
{
    //The Addition Button
    ui->pushButton_20->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #A9A9A9; height: 60%; width: 50%; font-size: 20px;");
    addition=1;
    activeNumber=2;
}

void MainWindow::on_pushButton_21_released()
{
    ui->pushButton_21->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_25_released()
{
    ui->pushButton_25->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_5_released()
{
    ui->pushButton_5->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px;  border-color: black; background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_18_released()
{
    ui->pushButton_18->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_19_released()
{
    ui->pushButton_19->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px;  border-color: black; background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_4_released()
{
    ui->pushButton_4->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_3_released()
{
    ui->pushButton_3->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_17_released()
{
    ui->pushButton_17->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_15_released()
{
    ui->pushButton_15->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px;  border-color: black; background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_8_released()
{
    ui->pushButton_8->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px;  border-color: black; background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_9_released()
{
    ui->pushButton_9->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_13_released()
{
    ui->pushButton_13->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_14_released()
{
    ui->pushButton_14->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_11_released()
{
    ui->pushButton_11->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_12_released()
{
    ui->pushButton_12->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_16_released()
{
    ui->pushButton_16->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}

void MainWindow::on_pushButton_20_released()
{
    ui->pushButton_20->setStyleSheet("border: solid #A9A9A9; border-width: 1px; border-radius: 8px; border-color: black;  background-color: #D3D3D3; height: 60%; width: 50%; font-size: 20px;");
}
