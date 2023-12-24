#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QList>
#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QRandomGenerator>
#include <algorithm> // Pour la fonction std::random_shuffle

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *page = new QWidget;
    QWidget *page_2 = new QWidget;

    labelMilieu = new QLabel(this);
    boutonJouer = new QPushButton("Jouer", this);
    boutonPrendre = new QPushButton("Prendre", this);
    boutonChangerType = new QPushButton("Changer Type", this);
    connect(boutonJouer, SIGNAL(clicked()), this, SLOT(jouerCarte()));
    connect(boutonPrendre, SIGNAL(clicked()), this, SLOT(prendreCarteSupplementaire()));
    connect(boutonChangerType, SIGNAL(clicked()), this, SLOT(changerTypeCarte()));
    //hady
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(labelMilieu);
    layout->addWidget(boutonJouer);
    layout->addWidget(boutonPrendre);
    layout->addWidget(boutonChangerType);
    //hta lhna
    initialiserJeu();
    distribuerCartes(2);
    joueurCourant = 0;
    cartesAPrendre = 0;
    jouerCarte();
}

void MainWindow::initialiserJeu()
{
        //load Batos
    Carte card1=creerCarte(1,"Bastos",":/../../Desktop/images/Cards/Bastos_1.jpg");
    Carte card2=creerCarte(2,"Bastos",":/../../Desktop/images/Cards/Bastos_2.jpg");
    Carte card3=creerCarte(3,"Bastos",":/../../Desktop/images/Cards/Bastos_3.jpg");
    Carte card4=creerCarte(4,"Bastos",":/../../Desktop/images/Cards/Bastos_4.jpg");
    Carte card5=creerCarte(5,"Bastos",":/../../Desktop/images/Cards/Bastos_5.jpg");
    Carte card6=creerCarte(6,"Bastos",":/../../Desktop/images/Cards/Bastos_6.jpg");
    Carte card7=creerCarte(7,"Bastos",":/../../Desktop/images/Cards/Bastos_7.jpg");
    Carte card8=creerCarte(10,"Bastos",":/../../Desktop/images/Cards/Bastos_10.jpg");
    Carte card9=creerCarte(11,"Bastos",":/../../Desktop/images/Cards/Bastos_11.jpg");
    Carte card10=creerCarte(12,"Bastos",":/../../Desktop/images/Cards/Bastos_12.jpg");
        //load Copas
    Carte card11=creerCarte(1,"Copas",":/../../Desktop/images/Cards/Copas_1.jpg");
    Carte card12=creerCarte(2,"Copas",":/../../Desktop/images/Cards/Copas_2.jpg");
    Carte card13=creerCarte(3,"Copas",":/../../Desktop/images/Cards/Copas_3.jpg");
    Carte card14=creerCarte(4,"Copas",":/../../Desktop/images/Cards/Copas_4.jpg");
    Carte card15=creerCarte(5,"Copas",":/../../Desktop/images/Cards/Copas_5.jpg");
    Carte card16=creerCarte(6,"Copas",":/../../Desktop/images/Cards/Copas_6.jpg");
    Carte card17=creerCarte(7,"Copas",":/../../Desktop/images/Cards/Copas_7.jpg");
    Carte card18=creerCarte(10,"Copas",":/../../Desktop/images/Cards/Copas_10.jpg");
    Carte card19=creerCarte(11,"Copas",":/../../Desktop/images/Cards/Copas_11.jpg");
    Carte card20=creerCarte(12,"Copas",":/../../Desktop/images/Cards/Copas_12.jpg");
        //load Espadas
    Carte card21=creerCarte(1,"Espadas",":/../../Desktop/images/Cards/Espadas_1.jpg");
    Carte card22=creerCarte(2,"Espadas",":/../../Desktop/images/Cards/Espadas_2.jpg");
    Carte card23=creerCarte(3,"Espadas",":/../../Desktop/images/Cards/Espadas_3.jpg");
    Carte card24=creerCarte(4,"Espadas",":/../../Desktop/images/Cards/Espadas_4.jpg");
    Carte card25=creerCarte(5,"Espadas",":/../../Desktop/images/Cards/Espadas_5.jpg");// 7 siofa
    Carte card26=creerCarte(6,"Espadas",":/../../Desktop/images/Cards/Espadas_6.jpg");
    Carte card27=creerCarte(7,"Espadas",":/../../Desktop/images/Cards/Espadas_7.PNG");
    Carte card28=creerCarte(10,"Espadas",":/../../Desktop/images/Cards/Espadas_10.jpg");
    Carte card29=creerCarte(11,"Espadas",":/../../Desktop/images/Cards/Espadas_11.jpg");
    Carte card30=creerCarte(12,"Espadas",":/../../Desktop/images/Cards/Espadas_12.jpg");
        //load horos
    Carte card31=creerCarte(1,"horos",":/../../Desktop/images/Cards/horos_1.jpg");
    Carte card32=creerCarte(2,"horos",":/../../Desktop/images/Cards/horos_2.jpg");
    Carte card33=creerCarte(3,"horos",":/../../Desktop/images/Cards/horos_3.jpg");
    Carte card34=creerCarte(4,"horos",":/../../Desktop/images/Cards/horos_4.jpg");
    Carte card35=creerCarte(5,"horos",":/../../Desktop/images/Cards/horos_5.jpg");
    Carte card36=creerCarte(6,"horos",":/../../Desktop/images/Cards/horos_6.jpg");
    Carte card37=creerCarte(7,"horos",":/../../Desktop/images/Cards/horos_7.jpg");
    Carte card38=creerCarte(10,"horos",":/../../Desktop/images/Cards/horos_10.jpg");
    Carte card39=creerCarte(11,"horos",":/../../Desktop/images/Cards/horos_11.jpg");
    Carte card40=creerCarte(12,"horos",":/../../Desktop/images/Cards/horos_12.jpg");

    //add Bastos to list
    carteListe.append(card1);
    carteListe.append(card2);
    carteListe.append(card3);
    carteListe.append(card4);
    carteListe.append(card5);
    carteListe.append(card6);
    carteListe.append(card7);
    carteListe.append(card8);
    carteListe.append(card9);
    carteListe.append(card10);
        //add Copas to list
    carteListe.append(card11);
    carteListe.append(card12);
    carteListe.append(card13);
    carteListe.append(card14);
    carteListe.append(card15);
    carteListe.append(card16);
    carteListe.append(card17);
    carteListe.append(card18);
    carteListe.append(card19);
    carteListe.append(card20);
        //add Espadas to list
    carteListe.append(card21);
    carteListe.append(card22);
    carteListe.append(card23);
    carteListe.append(card24);
    carteListe.append(card25);
    carteListe.append(card26);
    carteListe.append(card27);
    carteListe.append(card28);
    carteListe.append(card29);
    carteListe.append(card30);
        //add Horos to list
    carteListe.append(card31);
    carteListe.append(card32);
    carteListe.append(card33);
    carteListe.append(card34);
    carteListe.append(card35);
    carteListe.append(card36);
    carteListe.append(card37);
    carteListe.append(card38);
    carteListe.append(card39);
    carteListe.append(card40);
    std::random_shuffle(carteListe.begin(), carteListe.end());

}

Carte MainWindow::creerCarte(int numero, const QString& type, const QString& cheminImage) {
    Carte carte;
    carte.numero = numero;
    carte.type = type;
    carte.image = QPixmap(cheminImage);
    return carte;
}

void MainWindow::distribuerCartes(int nombreJoueurs)
  {
    for (int i = 0; i < nombreJoueurs; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            mainsJoueurs[i].append(carteListe.takeFirst());
        }
    }
    cartesMilieu.append(carteListe.takeFirst());
    labelMilieu->setPixmap(cartesMilieu.last().image);

 }

 void MainWindow::jouerCarte()
{
    // Vérifier si le joueur a une carte jouable
    if (carteJouable())
    {
        // Afficher la carte au milieu
        labelMilieu->setPixmap(cartesMilieu.last().image);
    }
    else
    {
        // Afficher un message indiquant que le joueur ne peut pas jouer
    }
}

void MainWindow::prendreCarteSupplementaire()
{
    // Vérifier si le joueur doit prendre une carte supplémentaire
    if (cartesAPrendre > 0)
    {
        // Distribuer une carte au joueur
        mainsJoueurs[joueurCourant].append(carteListe.takeFirst());
        // Réduire le nombre de cartes à prendre
        cartesAPrendre--;

        // Vérifier si le joueur peut maintenant jouer
        if (carteJouable())
        {
            // Afficher la carte au milieu
            labelMilieu->setPixmap(cartesMilieu.last().image);
        }
        else
        {
            // Afficher un message indiquant que le joueur ne peut pas jouer
            // ou effectuer d'autres actions nécessaires
        }
    }
}

void MainWindow::changerTypeCarte()
{
    // Vérifier si le joueur peut changer le type de carte
    if (cartesMilieu.last().numero == 7)
    {
        // Choisir un nouveau type de carte (par exemple, un type au hasard)
        QString nouveauType = QString::number(QRandomGenerator::global()->bounded(8, 11));
        // Changer le type de la carte au milieu
        cartesMilieu.last().type = nouveauType;


        // Afficher la nouvelle carte au milieu
        labelMilieu->setPixmap(cartesMilieu.last().image);
    }
    else
    {
        // Afficher un message indiquant que le joueur ne peut pas changer le type
        // ou effectuer d'autres actions nécessaires
    }
}

bool MainWindow::carteJouable()
{
    // Récupérer la carte au milieu
    const Carte& carteMilieu = cartesMilieu.last();

    for (const Carte carte  : mainsJoueurs[joueurCourant])
    {
        // Vérifier si la carte est jouable en fonction des règles du jeu
        if (carte.numero == 7 || carte.type == carteMilieu.type || carte.numero == carteMilieu.numero)
        {
            return true;
        }
    }
    return false;
};



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

