#ifndef MANIPULATIONPOLYNOME_H
#define MANIPULATIONPOLYNOME_H
#include <QWidget>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <string>
#include <QLineEdit>
#include <QObject>
#include <QFont>
#include <QMovie>
#include <QKeyEvent>
#include <math.h>
#include <fstream>
typedef struct Polynome
{
    int coef;
    int deg;
    struct Polynome *suiv;

}Poly;
using namespace std;
class manupPoly: public QWidget

{
    Q_OBJECT
public:
    manupPoly() ;
   void keyPressEvent(QKeyEvent *event);
   void keyReleaseEvent(QKeyEvent *event);
   Poly *Addition(Poly*p,int cf, int dg);
   Poly *Soustraction(Poly*p,int cf, int dg);
   Poly *insertionPolySimp(Poly*p, int cf, int dg);
   void multiplication(Poly *p, Poly *p2);
   void Affichage(int a);
   int detRaccine(int a,int b,int c);
private slots:
    /* void Enregistrement();
     void Additionner();
     void Factoriser();
     void DetRaccine();
     void Multiplier();
     void Soustraire();*/
    void clique0();
    void clique1();
    void clique2();
    void clique3();
    void clique4();
    void clique5();
    void clique6();
    void clique7();
    void clique8();
    void clique9();
    void cliqueAdd();
    void cliqueSous();
    void cliquePM();
    void cliqueEgal();
    void cliqueMulipli();
    void cliqueC();
    void cliqueRac();
    void cliqueFacto();
    void cliqueCE();
    void cliquePrev();
    void creationPremierInterface();
    void creationTroisiemeInterface();
    void creationDesBtn();
private:
    void manupFichier(QLabel *Affch);
    void effacementAuto();
    void LesConnecteurs();
    void recuperationABC(QString text);
    void recuperationAC(QString text);
    void recuperationA(QString text);
    void recuperationBC(QString text);
    void recuperationB(QString text);
    void recuperationC(QString text);
    int verification(QString text, int y);
    QString monteurDeP(int, int b);

    QPushButton *m_BtnFactoriser;
    QPushButton *m_BtnRaccine;
    QPushButton *m_BtnAdd;
    QPushButton *m_BtnMulti;
    QPushButton *m_BtnSoustraction;
    QPushButton *m_Btn1;
    QPushButton *m_Btn2;
    QPushButton *m_Btn3;
    QPushButton *m_Btn4;
    QPushButton *m_Btn5;
    QPushButton *m_Btn6;
    QPushButton *m_Btn7;
    QPushButton *m_Btn8;
    QPushButton *m_Btn9;
    QPushButton *m_Btn0;
    QPushButton *m_BtnPM;
    QPushButton *m_BtnV;
    QPushButton *m_BtnMenu;
    QPushButton *m_BtnEgal;
    QPushButton *m_BtnC;
    QPushButton *m_BtnEffa;
    QPushButton *m_BtnHistor;
    QPushButton *m_BtnMemo;
    QPushButton *m_BtnSuiv;
    QPushButton *m_BtnHelp;
    QPushButton *m_BtnPrev;
    QWidget *Premier;
    QWidget *Deuxieme;
    QWidget *Troisieme;
    QLabel *m_enr;
    QLabel *m_AffFacto;
    QGridLayout *grille;
    QGridLayout *grille2;
    QLabel *m_Resultat;
    QLabel *m_Eq1;
     QLabel *m_AffErreur;
     QLabel *smille;
     QLabel *textEq1;
     QLabel *textEq2;
     int A,B,C,pi=0,connais=0;
     QLabel *m_Msg;
     QMovie *movie;
     float m_x1,m_x2,m_x0;
      Poly *m_P3;
     Poly *m_P2;
     Poly *m_P;

    //int connaisseur;
};
#endif // MANIPULATIONPOLYNOME_H
