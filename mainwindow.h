#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QRandomGenerator>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

struct Carte {
    int numero;
    QString type;
    QPixmap image;    // Vous pouvez stocker l'image directement dans la structure si nécessaire
    //QList  image;
};

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QPixmap> carteListe;


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void initialiserJeu();
    void distribuerCartes(int nombreJoueurs);
    void jouerCarte();
    void prendreCarteSupplementaire();
    void changerTypeCarte();
    bool carteJouable();


private:
    Ui::MainWindow *ui;
    //QList<QList> carteListe;

    QList<Carte> mainsJoueurs[2];  // Max 2 joueurs
    QList<Carte> cartesMilieu;
    QList<QPixmap> carteListe;
    //QList<Carte> cartesMilieu;
    //QList<Carte> carteListe;

    Carte creerCarte(int numero, const QString& type, const QString& cheminImage);
    //creerCarte(int numero, const QString& type, const QString& cheminImage);
    int joueurCourant;
    int cartesAPrendre;
    QLabel *labelMilieu;
    QPushButton *boutonJouer;
    QPushButton *boutonPrendre;
    QPushButton *boutonChangerType;
};
#endif // MAINWINDOW_H
