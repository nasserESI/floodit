#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QObject>
#include "fichier.h"
#include <QListView>
#include <QStandardItemModel>
#include <QApplication>
#include <vector>
#include <string.h>
#include <QListWidgetItem>
#include <QIODevice>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->frame->setLayout(this->ui->frame->layout());
   /* this->ui->listView= new QListView(this->ui->centralwidget);
    this->ui->listView->setGeometry(550,130,321,491);
    this->ui->listView->setLineWidth(50);
    this->ui->listView->setLayout(this->ui->listView->layout());*/
    QObject::connect(this->ui->demarrage, SIGNAL(clicked()),this,SLOT(on_startButton_clicked()));

}
    int MainWindow::getSize()const{
        return this->ui->size->value();
}
    int MainWindow::getColor()const{
    return this->ui->color->value();
}


void MainWindow::on_startButton_clicked(){
    if(this->getSize()>0 && this->getColor()>0){
        this->ui->listWidget->clear();
        this->layout()->removeWidget(this->ui->frame);
        delete this->ui->frame;
        this->ui->frame = new QFrame(this);
        this->layout()->addWidget(this->ui->frame);
        this->game = Boardgame(this->ui->size->value(),this->ui->color->value());
        game.registerObserver(this);
        this->gridLayout = new QGridLayout(this->ui->frame);
        gridLayout->setSpacing(0);
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(0);
        this->ui->frame->setGeometry(60,130,25*this->getSize(),25*this->getSize());
        this->ui->frame->setFrameStyle(QFrame::Panel | QFrame::Raised);
        this->ui->frame->setLineWidth(10);

        this->myData_base = new Fichier();
        for(int x = 0; x < this->getData()->getList().size();x++ ){
            this->ui->listWidget->addItem(QString::fromStdString(this->getData()->getList().at(x)));
        }

        for(int row = 0; row < this->game.getBoard()[0].size(); row++){
            for(int column = 0; column < this->game.getBoard()[0].size(); column++){
                squareGUI* square = new squareGUI(this->game.getBoard()[row][column].getColor(),Position(row,column));
                QObject::connect(square,SIGNAL(clicked()),square,SLOT(mouseClick()));
                QObject::connect(square,SIGNAL(click(squareGUI&)),this,SLOT(select(squareGUI&)));
                gridLayout->addWidget(square,row,column);
            }
        }
        QPainter::end();
        this->ui->progres->setText(QString::fromStdString(game.getNumberOfAttempt()));
    }
}
MainWindow::~MainWindow()
{
    delete ui;
    delete this->ui->listWidget;
    delete this->ui->frame;
    delete this->ui->centralwidget;
    delete this->myData_base;
}

Fichier * MainWindow::getData()const{
    return this->myData_base;
}
/**
 * @brief MainWindow::Update met à jours le jeux
 * @param subject c'esst le sujet d'observation donc
 * le model et dans ce cas ci c'est la class Boardgame.
 */
void MainWindow::Update(const Subject * subject){
    for(int row = 0; row < this->game.getBoard()[0].size(); row++){
        for(int column = 0; column < this->game.getBoard()[0].size(); column++){
            squareGUI *square = new squareGUI(this->game.getBoard()[row][column].getColor(),Position(row,column));
            QObject::connect(square,SIGNAL(clicked()),square,SLOT(mouseClick()));
            QObject::connect(square,SIGNAL(click(squareGUI&)),this,SLOT(select(squareGUI&)));
            gridLayout->addWidget(square,row,column);
        }
    }
    this->ui->progres->setText(QString::fromStdString(game.getNumberOfAttempt()));
}
/**
 * @brief MainWindow::select permet d'enclencher l'évènement
 * des règles du jeux.
 * @param carre c'est le carre du gridlayout selectionné
 */
void MainWindow::select(squareGUI & carre){
    Position *pos = new Position(carre.getPos());
    this->game.updateBoard(pos);
    delete pos;
}


void MainWindow::on_save_clicked()
{
    //this->myData_base->getList().push_back(this->game.getNumberOfAttempt());
    this->getData()->writeFile(this->game.getNumberOfAttempt());
}

