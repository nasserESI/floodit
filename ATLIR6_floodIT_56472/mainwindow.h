#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include "observer.h"
#include <QMainWindow>
#include <QWidget>
#include <QListView>
#include "boardgame.h"
#include <string>
#include <QObject>
#include <QWidget>
#include "squaregui.h"
#include "subject.h"
#include <QMouseEvent>
#include <fichier.h>
using namespace model;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow,public Observer,public QPainter
{
    Q_OBJECT
private:
    QGridLayout *gridLayout;
    Boardgame game;
    Fichier * myData_base;
public:
    /**
     * @brief MainWindow crée la fênetre principale
     * @param parent par défaut c'est un pointeur null car c'est la première fenêtre.
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief Update il apporte les mise à jour essentiel à la continuité du jeux.
     * @param subject :c'est le model
     */
    void Update(const Subject * subject)override;
    /**
     * @brief getSize getter de la taille du carrée GUI
     * @return
     */
    int getSize()const;
    /** @brief getColor getter du nombre de couleur selectionné par le user
    * @return un entier
    */
    int getColor()const;
    /**
     * @brief getData getter de l'objet qui traite le fichier
     * @return un pointeur vers l'objet
     */
    Fichier * getData()const;
private slots:
    /**
     * @brief on_startButton_clicked l'evenement qui définit le start
     */
    void on_startButton_clicked();
    /**
    * @brief MainWindow::select permet d'enclencher l'évènement
    * des règles du jeux.
    * @param carre c'est le carre du gridlayout selectionné
    */
    void select(squareGUI&);
    /**
     * @brief on_save_clicked cette méthode permet la sauvegarde du score et qui est afficher au prochain lancement du jeux.
     */
    void on_save_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
