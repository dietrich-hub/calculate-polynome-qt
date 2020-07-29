/**********************************************************************************************************
 *
 * PROJET : la mise en place d'une application qui permet d'effectuer la soustraction,
 *           la mutiplication,l'addition le factorielle et les raccines des polynome d'auplus
 *                 2 degre
 *
 * Nom de l'application : PolyWine
 *
 * Auteurs : Guemkan Dietrich Bonhoeffer Crepin et Homte Yankan Chancelle
 *               Etudiants de genie informatique-IUT-Ngaoundere-Cameroun
 *
 * Version : 1.01.2020
 *
 * Tout droit reserver aux auteurs
 *
 * Date de creation : jeudi 08 janvier 2020
 *
 *
 * Perspective du projet : faire en sorte que l'utilisateur  entrer l'equations sans mettre 1 devant les x
 *                          verifier les potentiels bugs
 *                         recuperer l'equation de l'utilisateur meme si c'est entrer en desordre
 *
 *
 * Sous la coordination :  Pr Yenke omer Blaise
 *
 * *********************************************************************************************************
*/


#include "manipulationpolynome.h"

manupPoly::manupPoly() : QWidget()
{

    setFixedSize(640,600);
    setWindowIcon(QIcon(":/new/prefix1/icones/images.png"));

    setWindowTitle("PolyWine");
    /*int c = QApplication::desktop()->availableGeometry(this).width()/2 -640;
    int j = QApplication::desktop()->availableGeometry(this).height()/2 ;
    move(j,c);*/
    setFont(QFont("arial",20));

    grille = new QGridLayout;
    grille2 = new QGridLayout;
    m_Msg = new QLabel;
    textEq1=new QLabel(" ");
    textEq2= new QLabel(" ");
    m_AffErreur=new QLabel;

    m_AffFacto= new QLabel;
     Premier = new QWidget(this);
      Deuxieme = new QWidget(this);
     Troisieme = new QWidget(this);
     m_BtnSuiv = new QPushButton("Utiliser");
     m_BtnHelp = new QPushButton;

    creationPremierInterface();
    m_Eq1 = new QLabel("0");
    m_Eq1->setCursor(Qt::IBeamCursor);

    //creationDesBtn();
  QObject::connect(m_BtnSuiv,SIGNAL(clicked()),this,SLOT(creationDesBtn()));

    //connaisseur = 0;



}
void manupPoly::LesConnecteurs()
{

     QObject::connect(m_Btn0,SIGNAL(clicked()),this,SLOT(clique0()));
     QObject::connect(m_Btn1,SIGNAL(clicked()),this,SLOT(clique1()));
     QObject::connect(m_Btn2,SIGNAL(clicked()),this,SLOT(clique2()));
     QObject::connect(m_Btn3,SIGNAL(clicked()),this,SLOT(clique3()));
     QObject::connect(m_Btn4,SIGNAL(clicked()),this,SLOT(clique4()));
     QObject::connect(m_Btn5,SIGNAL(clicked()),this,SLOT(clique5()));
     QObject::connect(m_Btn6,SIGNAL(clicked()),this,SLOT(clique6()));
     QObject::connect(m_Btn7,SIGNAL(clicked()),this,SLOT(clique7()));
     QObject::connect(m_Btn8,SIGNAL(clicked()),this,SLOT(clique8()));
     QObject::connect(m_Btn9,SIGNAL(clicked()),this,SLOT(clique9()));
     QObject::connect(m_BtnPM,SIGNAL(clicked()),this,SLOT(cliquePM()));
     QObject::connect(m_BtnAdd,SIGNAL(clicked()),this,SLOT(cliqueAdd()));
     QObject::connect(m_BtnSoustraction,SIGNAL(clicked()),this,SLOT(cliqueSous()));
     QObject::connect(m_BtnEgal,SIGNAL(clicked()),this,SLOT(cliqueEgal()));
      QObject::connect(m_BtnC,SIGNAL(clicked()),this,SLOT(cliqueC()));
     QObject::connect(m_BtnRaccine,SIGNAL(clicked()),this,SLOT(cliqueRac()));
     QObject::connect(m_BtnFactoriser,SIGNAL(clicked()),this,SLOT(cliqueFacto()));
     QObject::connect(m_BtnMulti,SIGNAL(clicked()),this,SLOT(cliqueMulipli()));
     QObject::connect(m_BtnV,SIGNAL(clicked()),this,SLOT(cliqueCE()));
     QObject::connect(m_BtnHelp,SIGNAL(clicked()),this,SLOT(creationTroisiemeInterface()));

}

void manupPoly::creationPremierInterface()
{

    QLabel *Vide = new QLabel("        ");

    m_BtnSuiv->setStyleSheet("QWidget{Background:gold;border : 1px solid gold;border-radius:5px}");
    m_BtnSuiv->setFont(QFont("arial",15));
    m_BtnSuiv->setToolTip("cliquer pour commencer les calculs");
    m_BtnSuiv->setFixedSize(110,50);
    m_BtnSuiv->setCursor(Qt::PointingHandCursor);
    QLabel *Bienvenue = new QLabel("Bienvenue a vous dans PolyWine");
    Bienvenue->setStyleSheet("QWidget{color:white}");
    Bienvenue->setFont(QFont("arial",20));
    QLabel *astuce = new QLabel("\t\tPetit Tuto(Help):\n﴿> Appuyer sur le boutton ϰ² pour mettre ϰ²\n﴿> Les bouttons + - x sont la pour les operations\n﴿> Appuyer sur x du clavier lorsque vous voulez\n\tinserer x dans l'equation a entrer\n﴿> Une equation a entrer est sous la forme\n\tax²+bx+c\n﴿> Pour mettre les signes utiliser les\n\t touches du clavier + -");
    astuce->setStyleSheet("QWidget{color:white}");
    astuce->setFont(QFont("arial",13));
    QHBoxLayout *BF = new QHBoxLayout;
    QHBoxLayout *BF2 = new QHBoxLayout;
    QHBoxLayout *BF3 = new QHBoxLayout;
    QHBoxLayout *BF4 = new QHBoxLayout;
    QVBoxLayout *BV = new QVBoxLayout;


    Premier->setFixedSize(640,600);
    //setWindowFlags(Qt::CustomizeWindowHint);
    Premier->setStyleSheet("QWidget{background: rgb(0,0,0)}");
    smille= new QLabel("☺☻",Premier);
    smille->setStyleSheet("QWidget{color:gold}");
    smille->setFont(QFont("arial",100));

    BF->addWidget(Vide);
    BF->addWidget(smille);
    BF->addWidget(Vide);

    BF2->addWidget(Vide);
    BF2->addWidget(Bienvenue);
    BF2->addWidget(Vide);

    BF3->addWidget(Vide);
    BF3->addWidget(astuce);
    BF3->addWidget(Vide);

    BF4->addWidget(Vide);
    BF4->addWidget(m_BtnSuiv);
    BF4->addWidget(Vide);

    BV->addWidget(Vide);
    BV->addLayout(BF);
    BV->addLayout(BF2);
    BV->addLayout(BF3);
    BV->addWidget(Vide);
    BV->addLayout(BF4);
    BV->addWidget(Vide);

    Premier->setLayout(BV);

}
void manupPoly::creationTroisiemeInterface()
{
   Deuxieme->setVisible(false);
   Troisieme->setVisible(true);
    QLabel *Vide = new QLabel("        ");
    QLabel *Mv = new QLabel;
    QLabel *M = new QLabel("copyright 2020 Guemkan Dietrich et \n\tYamkam Chancelle");
    Mv->setFixedHeight(150);
    M->setFont(QFont("arial",9));
      m_BtnPrev = new QPushButton;
    movie = new QMovie("a.gif");

    QLabel *Bienvenue = new QLabel("Nous vous apportons de l'aide  ici");
    //Bienvenue->setStyleSheet("QWidget{color:white}");
    Bienvenue->setFont(QFont("arial",20));
    QLabel *astuce = new QLabel("\n﴿> Appuyer sur le boutton ϰ² pour mettre ϰ²\n﴿> Les bouttons + - x sont la pour les operations\n﴿> Appuyer sur x du clavier lorsque vous voulez\n\tinserer x dans l'equation a entrer\n﴿> Une equation a entrer est sous la forme\n\tax²+bx+c\n﴿> Pour mettre les signes utiliser les\n\t touches du clavier + -"
                                "\n﴿>Lorsque votre equation est sous la forme\n\t Expl: x²+4x+1 ecrivez plutot 1x²+4x+1\n﴿>Ctrl + x pour mettre x²\n﴿>Le boutton CE pour effacer tout l'ecran"
                                "\n﴿> Le boutton C permet d'effacer l'entree d'equation\n﴿>Utiliser le bouton effacer(Backspace) pour effacer\n\tprogressivement une erreur");
   // astuce->setStyleSheet("QWidget{color:white}");
    astuce->setFont(QFont("arial",13));
    QHBoxLayout *BF = new QHBoxLayout;
    QHBoxLayout *BF2 = new QHBoxLayout;
    QHBoxLayout *BF3 = new QHBoxLayout;
    QHBoxLayout *BF4 = new QHBoxLayout;
    QVBoxLayout *BV = new QVBoxLayout;


    Troisieme->setFixedSize(640,600);
    Troisieme->setStyleSheet("QWidget{background:#fcc55e}");

  Mv->setMovie(movie);

   movie->start();

   m_BtnPrev->setText("<");
   m_BtnPrev->setFont(QFont("arial",15));
   m_BtnPrev->setStyleSheet("QWidget{border: 1px solid white} QWidget:hover{background:#1b1b1b;color:White;border:1px solid white}");
   m_BtnPrev->setFixedHeight(50);
   m_BtnPrev->setFixedWidth(50);
    BF->addWidget(m_BtnPrev);
    BF->addWidget(Vide);
    BF->addWidget(Mv);
    BF->addWidget(M);

    BF2->addWidget(Vide);
    BF2->addWidget(Bienvenue);
    BF2->addWidget(Vide);

    BF3->addWidget(Vide);
    BF3->addWidget(astuce);
    BF3->addWidget(Vide);

    BF4->addWidget(Vide);
    //BF4->addWidget(m_BtnSuiv);
    BF4->addWidget(Vide);

    //BV->addWidget(Mv);
    BV->addLayout(BF);
    BV->addLayout(BF2);
    BV->addLayout(BF3);
    //BV->addWidget(Vide);
    //BV->addLayout(BF4);
    //BV->addWidget(Vide);

    Troisieme->setLayout(BV);
QObject::connect(m_BtnPrev,SIGNAL(clicked()),this,SLOT(cliquePrev()));
}
void manupPoly::creationDesBtn()
{

    Premier->setVisible(false);
    Troisieme->setVisible(false);
    Deuxieme->setFixedSize(640,600);
    //setWindowFlags(Qt::Window);
    m_P3=NULL;
    m_P2=NULL;
    m_P = NULL;

  Deuxieme->setFont(QFont("arial",20));
    smille= new QLabel("☺☻");
    smille->setVisible(false);
    QHBoxLayout *BF = new QHBoxLayout;
    QHBoxLayout *Msg = new QHBoxLayout;
    QHBoxLayout *BFV = new QHBoxLayout;
    //QLabel *vide = new QLabel("         ");
    //QString *Menu = new QString("|||");
    //Menu->setAlignment(Qt::AlignVCenter);
    m_Resultat = new QLabel("0");
    m_Resultat->setAlignment(Qt::AlignRight);
    m_Resultat->setFrameStyle(QFrame::Panel|QFrame::Raised);
    m_Resultat->setMidLineWidth(1);
     m_Resultat->setFixedHeight(50);

    m_Resultat->setStyleSheet("QWidget{background:white}");
    m_enr = new QLabel();
   // m_enr->setAlignment(Qt::AlignRight);
    //m_enr->setFrameStyle(QFrame::Panel|QFrame::Raised);

    //m_enr->setStyleSheet("QWidget{background:white}");

         m_BtnHelp->setText(" ?\n Aide");
         m_BtnHelp->setFont(QFont("arial",15));
         m_BtnHelp->setStyleSheet("QWidget:hover{background:#1b1b1b;border:1px solid white}");
         m_BtnHelp->setFixedHeight(50);
         m_BtnHelp->setFixedWidth(50);

//Zone de saisie
   textEq1->setFixedHeight(50);
   textEq1->setFont(QFont("arial",15));
   textEq1->setAlignment(Qt::AlignRight);
   textEq2->setFixedHeight(50);
   textEq2->setFont(QFont("arial",15));
     textEq1->setStyleSheet("QWidget{color:#a5a4a4}");
    m_Eq1->setFont(QFont("arial",20));
    m_Eq1->setFixedHeight(40);
    m_Eq1->setAlignment(Qt::AlignRight);

    m_AffFacto->setFixedHeight(40);
    m_AffFacto->setFont(QFont("arial",15));
    m_AffFacto->setStyleSheet("QWidget{color:#a5a4a4}");
    m_AffErreur->setFixedHeight(40);
    m_AffErreur->setStyleSheet("QWidget{color:#a5a4a4}");
Msg->addWidget(smille);
Msg->addWidget(m_Msg);
   // grille2->addWidget(m_Eq1,1,0);
    grille2->addWidget(textEq2,1,0,1,6);
    grille2->addLayout(Msg,3,1,1,6);
    grille2->addWidget(m_AffFacto,2,0,1,6);
       grille2->addWidget(textEq1,4,0,1,7);
    m_enr->setLayout(grille2);
 //fin
    QLabel *nomLog=new QLabel("CalculatricePolynome");
    nomLog->setFixedHeight(50);
    nomLog->setFont(QFont("arial",20));
    QLabel *imgLog=new QLabel;
     imgLog->setPixmap(QPixmap("logo-logiTPEpetit.png"));
     imgLog->setFixedHeight(90);
     imgLog->setFixedWidth(90);
     QLabel *imgLog2=new QLabel;
      imgLog2->setPixmap(QPixmap("polynome.png"));
      imgLog2->setFixedHeight(90);
      imgLog2->setFixedWidth(320);
    m_Btn0 = new QPushButton("0");
    m_Btn0->setFixedHeight(60);
    m_Btn0->setFixedWidth(120);
    m_Btn0->setFont(QFont("arial",20));

    m_Btn1 = new QPushButton("1");
    m_Btn1->setFixedHeight(60);
    m_Btn1->setFixedWidth(120);
    m_Btn1->setFont(QFont("arial",20));

    m_Btn2 = new QPushButton("2");
    m_Btn2->setFixedHeight(60);
    m_Btn2->setFixedWidth(120);
    m_Btn2->setFont(QFont("arial",20));

    m_Btn3 = new QPushButton("3");
    m_Btn3->setFixedHeight(60);
    m_Btn3->setFixedWidth(120);
    m_Btn3->setFont(QFont("arial",20));

    m_Btn4 = new QPushButton("4");
    m_Btn4->setFixedHeight(60);
    m_Btn4->setFixedWidth(120);
    m_Btn4->setFont(QFont("arial",20));

    m_Btn5 = new QPushButton("5");
    m_Btn5->setFixedHeight(60);
    m_Btn5->setFixedWidth(120);
    m_Btn5->setFont(QFont("arial",20));
    m_Btn6 = new QPushButton("6");
    m_Btn6->setFixedHeight(60);
    m_Btn6->setFixedWidth(120);
    m_Btn6->setFont(QFont("arial",20));
    m_Btn7 = new QPushButton("7");
    m_Btn7->setFixedHeight(60);
    m_Btn7->setFixedWidth(120);
    m_Btn7->setFont(QFont("arial",20));
    m_Btn8 = new QPushButton("8");
    m_Btn8->setFixedHeight(60);
    m_Btn8->setFixedWidth(120);
    m_Btn8->setFont(QFont("arial",20));
    m_Btn9 = new QPushButton("9");
    m_Btn9->setFixedHeight(60);
    m_Btn9->setFixedWidth(120);
    m_Btn9->setFont(QFont("arial",20));
    m_BtnPM = new QPushButton("ϰ²");
    m_BtnPM->setFixedHeight(60);
    m_BtnPM->setFixedWidth(120);
    m_BtnPM->setFont(QFont("arial",20));
    m_BtnV = new QPushButton("CE");
    m_BtnV->setFixedHeight(60);
    m_BtnV->setFixedWidth(120);
   m_BtnV->setFont(QFont("arial",20));
    // boutton pour les operations
    m_BtnAdd = new QPushButton("+");
    m_BtnAdd->setFixedHeight(60);
    m_BtnAdd->setFixedWidth(120);

    m_BtnAdd->setFont(QFont("arial",20));
    m_BtnSoustraction = new QPushButton("-");
    m_BtnSoustraction->setFixedHeight(60);
    m_BtnSoustraction->setFixedWidth(120);
    m_BtnSoustraction->setFont(QFont("arial",20));
    m_BtnMulti = new QPushButton("×");
    m_BtnMulti->setFixedHeight(60);
    m_BtnMulti->setFixedWidth(120);
    m_BtnMulti->setFont(QFont("arial",20));
    m_BtnEgal = new QPushButton("=");
    m_BtnEgal->setFixedHeight(60);
    m_BtnEgal->setFixedWidth(120);
    m_BtnEgal->setFont(QFont("arial",20));
    m_BtnFactoriser = new QPushButton("Facto");
    m_BtnFactoriser->setFixedHeight(60);
    m_BtnFactoriser->setFixedWidth(120);
    m_BtnFactoriser->setFont(QFont("arial",20));
    m_BtnRaccine = new QPushButton("Rac");
    m_BtnRaccine->setFixedHeight(60);
    m_BtnRaccine->setFixedWidth(120);
    m_BtnRaccine->setFont(QFont("arial",20));
    m_BtnC = new QPushButton("C");
    m_BtnC->setFixedHeight(60);
    m_BtnC->setFont(QFont("arial",20));
    m_BtnEffa = new QPushButton("MC");
    m_BtnEffa->setFixedHeight(60);
    m_BtnEffa->setFont(QFont("arial",20));
    m_BtnHistor = new QPushButton("HQ");
    m_BtnHistor->setFixedHeight(60);
    m_BtnHistor->setFont(QFont("arial",20));
    m_BtnMemo = new QPushButton("M+");
    m_BtnMemo->setFixedHeight(60);
    m_BtnMemo->setFont(QFont("arial",20));

    //>>les events de survole de la souris
      m_BtnAdd->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnSoustraction->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnMulti->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnFactoriser->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnRaccine->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnEffa->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnC->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnHistor->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");
      m_BtnMemo->setStyleSheet("QPushButton:hover{background:#1b1b1b;border:1px solid white}");

    //>>fin survole souris
    m_Btn0->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn1->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn2->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn3->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn4->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn5->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn6->setStyleSheet("QWidget{background: r#1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn7->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn8->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_Btn9->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_BtnV->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                          "QPushButton:hover{background:#343434}");
    m_BtnPM->setStyleSheet("QWidget{background: #600291;border:1px solid #600291}"
                           "QPushButton:hover{background:#a805fd;border:1px solid #a805fd}");
    m_BtnEgal->setStyleSheet("QWidget{background: #114167;border:1px solid #114167}QPushButton:hover{border:1px solid white}"
                             "QPushButton:hover{background:#065a9d}");
    //fin065a9d
    BF->addWidget(m_BtnC);
    BF->addWidget(m_BtnEffa);
    BFV->addWidget(m_BtnHistor);
    BFV->addWidget(m_BtnMemo);
    grille->addWidget(m_Btn7,4,0);
    grille->addWidget(m_Btn8,4,1);
    grille->addWidget(m_Btn9,4,2);
    grille->addWidget(m_Btn4,5,0);
    grille->addWidget(m_Btn5,5,1);
    grille->addWidget(m_Btn6,5,2);
    grille->addWidget(m_Btn1,6,0);
    grille->addWidget(m_Btn2,6,1);
    grille->addWidget(m_Btn3,6,2);
    grille->addWidget(m_BtnAdd,4,3);
    grille->addWidget(m_BtnSoustraction,5,3);
    grille->addWidget(m_BtnMulti,6,3);
    grille->addWidget(m_BtnEgal,7,3);
    grille->addWidget(m_BtnFactoriser,4,4);
    grille->addWidget(m_BtnRaccine,5,4);
    grille->addLayout(BF,6,4);
    grille->addLayout(BFV,7,4);
   // grille->addWidget(vide,4,5);
    grille->addWidget(m_BtnPM,7,0);
    grille->addWidget(m_Btn0,7,1);
    grille->addWidget(m_BtnV,7,2);
    grille->addWidget(m_enr,2,0,1,6);
    grille->addWidget(m_Eq1,3,0,1,5);
    grille->addWidget(m_BtnHelp,1,0);
    grille->addWidget(imgLog,1,1);
    grille->addWidget(imgLog2,1,2);

   Deuxieme->setStyleSheet("QWidget{background: rgb(0,0,0);color:white}");
   Deuxieme->setLayout(grille);
   LesConnecteurs();



}
void manupPoly::clique0()
{
    effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="0";
    else
    nb = nb + "0";
    m_Eq1->setText(nb);

}
void manupPoly::clique1()
{
   effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="1";
    else
    nb = nb + "1";
    m_Eq1->setText(nb);
}
void manupPoly::clique2()
{
    effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="2";
    else
    nb = nb + "2";
    m_Eq1->setText(nb);
}
void manupPoly::clique3()
{
    effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="3";
    else
    nb = nb + "3";
    m_Eq1->setText(nb);
}
void manupPoly::clique4()
{
    effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="4";
    else
    nb = nb + "4";
    m_Eq1->setText(nb);
}
void manupPoly::clique5()
{
    effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="5";
    else
    nb = nb + "5";
    m_Eq1->setText(nb);
}
void manupPoly::clique6()
{
   effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="6";
    else
    nb = nb + "6";
    m_Eq1->setText(nb);
}
void manupPoly::clique7()
{
   effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="8";
    else
    nb = nb + "7";
    m_Eq1->setText(nb);
}
void manupPoly::clique8()
{
  effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="8";
    else
    nb = nb + "8";
    m_Eq1->setText(nb);
}
void manupPoly::clique9()
{
  effacementAuto();
    QString nb;
    nb =  m_Eq1->text();
    if(nb == "0")
        nb ="9";
    else
    nb = nb + "9";
    m_Eq1->setText(nb);
}
void manupPoly::cliquePrev()
{
    //movie->stop();
    Troisieme->setVisible(false);
    Deuxieme->setVisible(true);
}

void manupPoly::cliquePM()
{

   /* QString nb;
    QString n,p;
    nb =  m_Eq1->text();
   //
    if(nb.isEmpty())
    {
        nb =nb + "-";
        m_Eq1->setText(nb);
    }else{

        p = nb[nb.count()-1];
         if(p == "-")
            {
                n = "+";
                nb = nb.replace(nb.count()-1,1,n);
                m_Eq1->setText(nb);
            }
            if(p == "+")
            {
                n = "-";
                nb = nb.replace(nb.count()-1,1,n);
                m_Eq1->setText(nb);
            }
            if(p !="-" || p !="+")
            {
                nb = nb.replace(nb.count()-1,0,"+");
                m_Eq1->setText(nb);
            }*/


    QString nb;
    nb =  m_Eq1->text();
    if(nb != "0")
    nb = nb + "x²";
    else
        nb = "1x²";
    m_Eq1->setText(nb);


}
void manupPoly::cliqueCE()
{
     m_Eq1->setText("0");
     textEq1->setText(" ");
     textEq2->setText(" ");
     m_AffErreur->setText(0);
     m_AffFacto->setText(0);

     effacementAuto();
}

void manupPoly::cliqueAdd()
{
    QString nb;
    int verif;
    m_P = NULL;
    nb =  textEq1->text();
   if (nb == " ")
   {

       verif =  verification(m_Eq1->text(),0);

       if(verif == -4)
       {
           nb =m_Eq1->text()+" + ";
            textEq1->setText(nb);
           recuperationC(m_Eq1->text());

           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;

       }
       if(verif == -3)
       {
           QString test;
           int i;
           test = m_Eq1->text();
           for(i=0;i<=test.length();i++)
           {
               if(test[i] == "x")break;
           }
           if (test[i+1].isNull() == true)
           {
           nb =m_Eq1->text()+" + ";
            textEq1->setText(nb);

           recuperationB(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;
           }
       }
       if(verif == -2)
       {
           nb =m_Eq1->text()+" + ";
            textEq1->setText(nb);
           recuperationBC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;
       }

       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 1;

       }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 1;
       }
       if(verif == 2)
       {
           recuperationA(m_Eq1->text());

           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;
       }
   }

   if(nb !=" " && m_Eq1->text() != "0")
   {
       verif =verification(m_Eq1->text(),0);
       if(verif == -4)
       {
           nb =m_Eq1->text()+" + ";
            textEq1->setText(nb);
           recuperationC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;
       }
       if(verif == -3)
       {
           QString test;
           int i;
           test = m_Eq1->text();
           for(i=0;i<=test.length();i++)
           {
               if(test[i] == "x")break;
           }
           if (test[i+1].isNull() == true)
           {
           nb =m_Eq1->text()+" + ";
            textEq1->setText(nb);
           recuperationB(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;
           }
       }
       if(verif == -2)
       {
           nb =m_Eq1->text()+" + ";
            textEq1->setText(nb);
           recuperationBC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;
       }
       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 1;

       }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 1;
       }
       if(verif == 2)
       {
           recuperationA(m_Eq1->text());

           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 1;
       }
   }

}
void manupPoly::cliqueMulipli()
{
    QString nb;
    int verif;
    m_P = NULL;
    nb =  textEq1->text();
   if (nb == " ")
   {
       verif =  verification(m_Eq1->text(),2);

       if(verif == -4)
       {
           nb =m_Eq1->text()+" × ";
            textEq1->setText(nb);
           recuperationC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
       }
       if(verif == -3)
       {
           QString test;
           int i;
           test = m_Eq1->text();
           for(i=0;i<=test.length();i++)
           {
               if(test[i] == "x")break;
           }
           if (test[i+1].isNull() == true)
           {
           nb =m_Eq1->text()+" × ";
            textEq1->setText(nb);
           recuperationB(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
           }
       }
       if(verif == -2)
       {
           nb ="("+m_Eq1->text()+")"+" × ";
            textEq1->setText(nb);
           recuperationBC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
       }
       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 3;

       }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 3;

       }
       if(verif == 2)
       {
           recuperationA(m_Eq1->text());

           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
       }
   }

   if(nb !=" " && m_Eq1->text() !="0")
   {
       verif =  verification(m_Eq1->text(),2);
       if(verif == -4)
       {
           nb =m_Eq1->text()+" × ";
            textEq1->setText(nb);
           recuperationC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
       }
       if(verif == -3)
       {
           QString test;
           int i;
           test = m_Eq1->text();
           for(i=0;i<=test.length();i++)
           {
               if(test[i] == "x")break;
           }
           if (test[i+1].isNull() == true)
           {
           nb =m_Eq1->text()+" × ";
            textEq1->setText(nb);
           recuperationB(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
           }
       }
       if(verif == -2)
       {
           nb ="("+m_Eq1->text()+")"+" × ";
            textEq1->setText(nb);
           recuperationBC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
       }
       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 3;

       }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 3;

       }
       if(verif == 2)
       {
           recuperationA(m_Eq1->text());

           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 3;
       }
   }

}

void manupPoly::cliqueSous()
{
    QString nb;
    m_P = NULL;
    int verif;
    nb =  textEq1->text();
   if (nb == " ")
   {
       verif =  verification(m_Eq1->text(),3);
       if(verif == -4)
       {
           nb =m_Eq1->text()+" - ";
            textEq1->setText(nb);
           recuperationC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
       }
       if(verif == -3)
       {
           QString test;
           int i;
           test = m_Eq1->text();
           for(i=0;i<=test.length();i++)
           {
               if(test[i] == "x")break;
           }
           if (test[i+1].isNull() == true)
           {
           nb =m_Eq1->text()+" - ";
            textEq1->setText(nb);
           recuperationB(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
           }
       }

       if(verif == -2)
       {
           nb =m_Eq1->text()+" - ";
            textEq1->setText(nb);
           recuperationBC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
       }
       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 2;

       }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 2;

       }
       if(verif == 2)
       {
           recuperationA(m_Eq1->text());

           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
       }
   }

   if(nb !=" " && m_Eq1->text() != "0")
   {
       verif =  verification(m_Eq1->text(),3);
       if(verif == -4)
       {
           nb =m_Eq1->text()+" - ";
            textEq1->setText(nb);
           recuperationC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
       }
       if(verif == -3)
       {
           QString test;
           int i;
           test = m_Eq1->text();
           for(i=0;i<=test.length();i++)
           {
               if(test[i] == "x")break;
           }
           if (test[i+1].isNull() == true)
           {
           nb =m_Eq1->text()+" - ";
            textEq1->setText(nb);
           recuperationB(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
           }
       }
       if(verif == -2)
       {
           nb =m_Eq1->text()+" - ";
            textEq1->setText(nb);
           recuperationBC(m_Eq1->text());
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
       }
       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 2;

       }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           //m_P->coef = A;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           // m_P2 = m_P->suiv;
           m_Eq1->setText("0");
           connais = 2;

       }
       if(verif == 2)
       {
           recuperationA(m_Eq1->text());

           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
           m_Eq1->setText("0");
           connais = 2;
       }
   }

}
void manupPoly::cliqueRac()
{
    QString nb;
    int verif,m;
    nb =  textEq1->text();

       verif =  verification(m_Eq1->text(),5);
       if(verif == -3)
       {
           QString test;
           int i;
           test = m_Eq1->text();
           for(i=0;i<=test.length();i++)
           {
               if(test[i] == "x")break;
           }
           if (test[i+1].isNull() == true)
           {
           recuperationB(m_Eq1->text());
           m_P = NULL;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);

        textEq2->setText("ϰₒ= "+QString::number(0));
           }


   }
       if(verif == -2)
       {
           float a;

           recuperationBC(m_Eq1->text());

           m_P = NULL;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);

            a = C;
            a = (-a)/B;


                   textEq2->setText("ϰₒ= "+QString::number(a));



   }
       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           m_P = NULL;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);


           m=detRaccine(m_P->coef,m_P->suiv->coef,m_P->suiv->suiv->coef);

           if(m==1)
           {

                   textEq2->setText("ϰₒ= "+QString::number(m_x0));

           }
           if(m==2)
           {

                   textEq2->setText("ϰ1= "+QString::number(m_x1)+"\t"+"ϰ2= "+QString::number(m_x2));

           }

       if(m==0)
       {
           smille->setVisible(true);
           smille->setFont(QFont("arial",30));
           smille->setStyleSheet("QWidget{color:gold;font-weight:bold}");
           m_Msg->setText("L'equation n'a pas de solution dans R");
           m_Msg->setFont(QFont("arial",15));
       }


   }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           m_P = NULL;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);


           m=detRaccine(m_P->coef,m_P->suiv->coef,m_P->suiv->suiv->coef);
           if(m==1)
           {

                   textEq2->setText("ϰₒ= "+QString::number(m_x0));

           }
           if(m==2)
           {

                   textEq2->setText("ϰ1= "+QString::number(m_x1)+"\t"+"ϰ2= "+QString::number(m_x2));

           }

       if(m==0)
       {
           smille->setVisible(true);
           smille->setFont(QFont("arial",30));
           smille->setStyleSheet("QWidget{color:gold;font-weight:bold}");
           m_Msg->setText("L'equation n'a pas de solution dans R");
           m_Msg->setFont(QFont("arial",15));;
       }


   }
       if(verif == 2)
       {
           recuperationA(m_Eq1->text());
           m_P = NULL;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);


           m=detRaccine(m_P->coef,m_P->suiv->coef,m_P->suiv->suiv->coef);
           if(m==1)
           {

                   textEq2->setText("ϰₒ= "+QString::number(m_x0));

           }
       }
//☺ₒₒ☻

}
void manupPoly::cliqueFacto()
{
    QString nb;
    int verif,m;
    m_P = NULL;
       verif =  verification(m_Eq1->text(),5);

       if(verif == 0)
       {
           recuperationABC(m_Eq1->text());
           m_P = NULL;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
               nb = "F(ϰ)= ";
           m=detRaccine(m_P->coef,m_P->suiv->coef,m_P->suiv->suiv->coef);

           if(m==1)
           {
               if(m_x0>0)
               {
                   nb = nb +QString::number(A)+"(ϰ - "+QString::number(m_x0)+")²";
               }else
                 {
                   if(m_x0 !=0)
                   nb = nb +QString::number(A)+"(ϰ + "+QString::number(fabs(m_x0))+")²";
                   else
                      nb = nb +QString::number(A)+"ϰ²";

                  }




           }
           if(m==2)
           {
               nb = nb + QString::number(A)+"[ ";
               if(m_x1>0)
                     nb = nb +"(ϰ - "+QString::number(m_x1 )+" ) ";
               else
               {
                   if(m_x1 !=0)
                     nb = nb +"(ϰ + "+QString::number(fabs(m_x1))+" ) ";
                   if(m_x1 ==0 && m_x2 !=0)
                          nb = nb +"ϰ";
                }

               if(m_x2>0)
                   nb = nb +"(ϰ - "+QString::number(m_x2)+" ) ";
               else
                 {
                   if(m_x2 !=0)
                     nb = nb +"(ϰ + "+QString::number(fabs(m_x2))+" ) ]";
                   if(m_x1 !=0 && m_x2 ==0)
                          nb = nb +"ϰ"+" ]";
                 }
           }
           if(m==0)
           {

               float d,vt,n;


               d=B;
               d= d/A;
               //d=d/2;
               n=C;
               n= n/A;
               vt = -pow(d/2,2)+n;

               if(vt>0)
               nb = nb + QString::number(A)+"[ "+"(ϰ"+" +"+QString::number(d/2)+")²"+" + "+QString::number(vt)+" ]";
               else
                  if(vt!=0)
                      nb = nb + QString::number(A)+"[ "+"(ϰ"+" +"+QString::number(d)+")²"+QString::number(vt)+" ]";
           }

      m_AffFacto->setText(nb);


   }
       if(verif == 1)
       {
           recuperationAC(m_Eq1->text());
           m_P = NULL;
           m_P=insertionPolySimp(m_P,A,2);
           m_P=insertionPolySimp(m_P,B,1);
           m_P=insertionPolySimp(m_P,C,0);
               nb = "F(ϰ)= ";
           m=detRaccine(m_P->coef,m_P->suiv->coef,m_P->suiv->suiv->coef);

           if(m==1)
           {
               if(m_x0>0)
               {
                   nb = nb +QString::number(A)+"(ϰ - "+QString::number(m_x0)+")²";
               }else
                 {
                   if(m_x0 !=0)
                   nb = nb +QString::number(A)+"(ϰ + "+QString::number(fabs(m_x0))+")²";
                   else
                      nb = nb +QString::number(A)+"ϰ²";

                  }



           }
           if(m==2)
           {
               if(m_x1>0)
                     nb = nb +"(ϰ - "+QString::number(m_x1 )+" ) ";
               else

                     nb = nb +"(ϰ + "+QString::number(fabs(m_x1))+" ) ";

               if(m_x2>0)
                   nb = nb +"(ϰ - "+QString::number(m_x2)+" ) ";
               else

                 nb = nb +"(ϰ + "+QString::number(fabs(m_x2))+" ) ";


           }
           if(m==0)
           {


               float d,vt,c;
               d=B;
               d= d/A;
               c = C;
               d=d/2;
               c = c/A;
               vt = -pow(B/2,2)+c;


             if(d !=0)
             {
               if(vt>0)
               nb = nb + QString::number(A)+"[ "+"(ϰ"+" +"+QString::number(d)+")²"+" + "+QString::number(vt)+" ]";
               else
               {
                  if(vt!=0)
                      nb = nb + QString::number(A)+"[ "+"(ϰ"+" +"+QString::number(d)+")²"+QString::number(vt)+" ]";


               }
             }else
             {
                 if(vt>0)
                 nb = nb + QString::number(A)+"[ "+"(ϰ"+")²"+"+"+QString::number(vt)+" ]";
                 else
                 {
                     if(vt!=0)
                     nb = nb + QString::number(A)+"[ "+"(ϰ"+")²"+QString::number(vt)+" ]";
                 }
             }
           }
            m_AffFacto->setText(nb);
   }
           if(verif == 2)
           {
               recuperationA(m_Eq1->text());
               m_P = NULL;
               m_P=insertionPolySimp(m_P,A,2);
               m_P=insertionPolySimp(m_P,B,1);
               m_P=insertionPolySimp(m_P,C,0);
                   nb = "F(ϰ)= ";
               m=detRaccine(m_P->coef,m_P->suiv->coef,m_P->suiv->suiv->coef);
               if(m==1)
               {
                   if(m_x0>0)
                   {
                       nb = nb +QString::number(A)+"(ϰ - "+QString::number(m_x0)+")²";
                   }else
                     {
                       if(m_x0 !=0)
                       nb = nb +QString::number(A)+"(ϰ + "+QString::number(fabs(m_x0))+")²";
                       else
                          nb = nb +QString::number(A)+"ϰ²";

                      }



               }
               if(m==2)
               {
                   if(m_x1>0)
                         nb = nb +"(ϰ - "+QString::number(m_x1 )+" ) ";
                   else

                         nb = nb +"(ϰ + "+QString::number(fabs(m_x1))+" ) ";

                   if(m_x2>0)
                       nb = nb +"(ϰ - "+QString::number(m_x2)+" ) ";
                   else

                     nb = nb +"(ϰ + "+QString::number(fabs(m_x2))+" ) ";


               }
               if(m==0)
               {
                   int vt,v,c;
                   v=B;
                   c = C;
                   v= v/A;
                   c = c/A;
                   vt = -pow(B/2,2)+c;
                   if(vt>0)
                   nb = nb + QString::number(A)+"[ "+"(ϰ"+" +"+QString::number(v/2)+")²"+" + "+QString::number(vt)+" ]";
                   else
                      if(vt!=0)
                          nb = nb + QString::number(A)+"[ "+"(ϰ"+" +"+QString::number(v/2)+")²"+QString::number(vt)+" ]";
               }


      m_AffFacto->setText(nb);


   }
}
void manupPoly::cliqueEgal()
{

  m_P2 = NULL;
    int verif;

    verif =  verification(m_Eq1->text(),5);
    //m_Btn5->setText(QString::number(verif));

    if(verif == 0 && connais !=0)
    {
        if(connais == 2)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais == 3)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais !=2 && connais !=3)
        textEq1->setText(textEq1->text()+m_Eq1->text());

        textEq1->setText(textEq1->text()+" =");
    if(connais == 1)
    {
        recuperationABC(m_Eq1->text());
        //m_P->coef = A;
        m_P=Addition(m_P,A,2);
        m_P=Addition(m_P,B,1);
        m_P=Addition(m_P,C,0);
          connais = 0;
       Affichage(1);
    }
    if(connais == 2)
    {
        recuperationABC(m_Eq1->text());
        //m_P->coef = A;
        m_P=Soustraction(m_P,A,2);
        m_P=Soustraction(m_P,B,1);
        m_P=Soustraction(m_P,C,0);
        connais = 0;
       Affichage(3);
    }
    if(connais == 3)
    {
        recuperationABC(m_Eq1->text());
        //m_P->coef = A;
        m_P2=Addition(m_P2,A,2);
        m_P2=Addition(m_P2,B,1);
        m_P2=Addition(m_P2,C,0);
        multiplication(m_P,m_P2);
        connais = 0;
        Affichage(2);

    }

    }
    if(verif == 1 && connais !=0)
    {
        if(connais == 2)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais == 3)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais !=2 && connais !=3)
        textEq1->setText(textEq1->text()+m_Eq1->text());

        textEq1->setText(textEq1->text()+" =");
    if(connais == 1)
    {
        recuperationAC(m_Eq1->text());
        //m_P->coef = A;
        m_P=Addition(m_P,A,2);
        m_P=Addition(m_P,B,1);
        m_P=Addition(m_P,C,0);
          connais = 0;
       Affichage(1);
    }
    if(connais == 2)
    {
        recuperationAC(m_Eq1->text());
        //m_P->coef = A;
        m_P=Soustraction(m_P,A,2);
        m_P=Soustraction(m_P,B,1);
        m_P=Soustraction(m_P,C,0);
        connais = 0;
       Affichage(3);
    }
    if(connais == 3)
    {
        recuperationAC(m_Eq1->text());
        //m_P->coef = A;
        m_P2=Addition(m_P2,A,2);
        m_P2=Addition(m_P2,B,1);
        m_P2=Addition(m_P2,C,0);
        multiplication(m_P,m_P2);
        connais = 0;
        Affichage(2);

    }

    }

    if(verif == 2 && connais !=0)
    {
        if(connais == 2)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais == 3)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais !=2 && connais !=3)
        textEq1->setText(textEq1->text()+m_Eq1->text());

        textEq1->setText(textEq1->text()+" =");
    if(connais == 1)
    {
        recuperationA(m_Eq1->text());
        //m_P->coef = A;
        m_P=Addition(m_P,A,2);
        m_P=Addition(m_P,B,1);
        m_P=Addition(m_P,C,0);
          connais = 0;
       Affichage(1);
    }
    if(connais == 2)
    {
        recuperationA(m_Eq1->text());
        //m_P->coef = A;
        m_P=Soustraction(m_P,A,2);
        m_P=Soustraction(m_P,B,1);
        m_P=Soustraction(m_P,C,0);
        connais = 0;
       Affichage(3);
    }
    if(connais == 3)
    {
        recuperationA(m_Eq1->text());
        //m_P->coef = A;
        m_P2=Addition(m_P2,A,2);
        m_P2=Addition(m_P2,B,1);
        m_P2=Addition(m_P2,C,0);
        multiplication(m_P,m_P2);
        connais = 0;
        Affichage(2);

    }

    }
    if(verif == -2 && connais !=0)
    {
        if(connais == 2)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais == 3)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais !=2 && connais !=3)
        textEq1->setText(textEq1->text()+m_Eq1->text());

         //textEq1->setText(textEq1->text()+m_Eq1->text());
        textEq1->setText(textEq1->text()+" =");
    if(connais == 1)
    {
        recuperationBC(m_Eq1->text());
        //m_P->coef = A;
        m_P=Addition(m_P,A,2);
        m_P=Addition(m_P,B,1);
        m_P=Addition(m_P,C,0);
          connais = 0;
       Affichage(1);
    }
    if(connais == 2)
    {
        recuperationBC(m_Eq1->text());
        //m_P->coef = A;
        m_P=Soustraction(m_P,A,2);
        m_P=Soustraction(m_P,B,1);
        m_P=Soustraction(m_P,C,0);
        connais = 0;
       Affichage(3);
    }
    if(connais == 3)
    {
        recuperationBC(m_Eq1->text());
        //m_P->coef = A;
        m_P2=Addition(m_P2,A,2);
        m_P2=Addition(m_P2,B,1);
        m_P2=Addition(m_P2,C,0);
        multiplication(m_P,m_P2);
        connais = 0;
        Affichage(2);

    }

    }
    if(verif == -3 && connais !=0)
    {
        QString test;
        int i;
        test = m_Eq1->text();
        for(i=0;i<=test.length();i++)
        {
            if(test[i] == "x")break;
        }
        if (test[i+1].isNull() == true)
        {
        if(connais == 2)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais == 3)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais !=2 && connais !=3)
        textEq1->setText(textEq1->text()+m_Eq1->text());

         //textEq1->setText(textEq1->text()+m_Eq1->text());
        textEq1->setText(textEq1->text()+" =");
    if(connais == 1)
    {
        recuperationB(m_Eq1->text());
        //m_P->coef = A;
        m_P=Addition(m_P,A,2);
        m_P=Addition(m_P,B,1);
        m_P=Addition(m_P,C,0);
          connais = 0;
       Affichage(1);
    }
    if(connais == 2)
    {

        recuperationB(m_Eq1->text());
        //m_P->coef = A;
        m_P=Soustraction(m_P,A,2);
        m_P=Soustraction(m_P,B,1);
        m_P=Soustraction(m_P,C,0);
        connais = 0;
       Affichage(3);
    }
    if(connais == 3)
    {
        recuperationB(m_Eq1->text());
        //m_P->coef = A;
        m_P2=Addition(m_P2,A,2);
        m_P2=Addition(m_P2,B,1);
        m_P2=Addition(m_P2,C,0);
        multiplication(m_P,m_P2);
        connais = 0;
        Affichage(2);

    }
}
    }
    if(verif == -4 && connais !=0)
    {
        if(connais == 2)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais == 3)
            textEq1->setText(textEq1->text()+"("+m_Eq1->text()+")");
        if(connais !=2 && connais !=3)
        textEq1->setText(textEq1->text()+m_Eq1->text());

         //textEq1->setText(textEq1->text()+m_Eq1->text());
        textEq1->setText(textEq1->text()+" =");
    if(connais == 1)
    {
        recuperationC(m_Eq1->text());
        //m_P->coef = A;

        m_P=Addition(m_P,A,2);
        m_P=Addition(m_P,B,1);
        m_P=Addition(m_P,C,0);
          connais = 0;
       Affichage(1);
    }
    if(connais == 2)
    {

        recuperationC(m_Eq1->text());
        //m_P->coef = A;
        m_P=Soustraction(m_P,A,2);
        m_P=Soustraction(m_P,B,1);
        m_P=Soustraction(m_P,C,0);
        connais = 0;
       Affichage(4);
    }
    if(connais == 3)
    {

        recuperationC(m_Eq1->text());
        //m_P->coef = A;
        m_P2=Addition(m_P2,A,2);
        m_P2=Addition(m_P2,B,1);
        m_P2=Addition(m_P2,C,0);
        multiplication(m_P,m_P2);
        connais = 0;
        Affichage(2);

    }

    }

}
void manupPoly::cliqueC()
{
   textEq1->setText(" ");
   m_Eq1->setText("0");
}
void manupPoly::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == 0x30)
    {
        m_Btn0->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");

    }

    if(event->key() == Qt::Key_X)
    {

            m_BtnPM->setStyleSheet("QWidget{background:#600291;border:1px solid #600291}"
                                   "QPushButton:hover{background:#a805fd;border:1px solid #a805fd}");

    }


    if(event->key() == 0x31)
    {
        m_Btn1->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_2)
    {
        m_Btn2->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_3)
    {
        m_Btn3->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_4)
    {
        m_Btn4->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_5)
    {
        m_Btn5->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_6)
    {
        m_Btn6->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_7)
    {
        m_Btn7->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_8)
    {
        m_Btn8->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
    if(event->key() == Qt::Key_9)
    {
        m_Btn9->setStyleSheet("QWidget{background: #1b1b1b;border:1px solid #1b1b1b;color:white}"
                              "QPushButton:hover{background:#343434}");
    }
}

void manupPoly::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == 0x30)
    {
        effacementAuto();
        m_Btn0->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="0";
        else
        nb = nb + "0";
        m_Eq1->setText(nb);
    }
    if(event->key() == 0x58)
    {
        effacementAuto();
        QString nb;
        nb =  m_Eq1->text();
        if(pi==0)
        {
        if(nb == "0")
            nb ="1x";
        else
        nb = nb + "x";
        }
        if(pi == 1)
        {
            effacementAuto();
            m_BtnPM->setStyleSheet("QWidget{background: #a805fd;border:1px solid white}");
            if(nb == "0")
                nb ="1x²";
            else
            nb = nb + "x²";
            pi = 0;
        }
        m_Eq1->setText(nb);
    }
    if(event->key() == 0x31)
    {
        effacementAuto();
        m_Btn1->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="1";
        else
        nb = nb + "1";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_2)
    {
        effacementAuto();
        m_Btn2->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="2";
        else
        nb = nb + "2";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_3)
    {
        effacementAuto();
        m_Btn3->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="3";
        else
        nb = nb + "3";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_4)
    {
        effacementAuto();
        m_Btn4->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="4";
        else
        nb = nb + "4";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_5)
    {
        effacementAuto();
        m_Btn5->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="5";
        else
        nb = nb + "5";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_6)
    {
        effacementAuto();
        m_Btn6->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="6";
        else
        nb = nb + "6";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_7)
    {
        effacementAuto();
        m_Btn7->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="7";
        else
        nb = nb + "7";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_8)
    {
        effacementAuto();
        m_Btn8->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="8";
        else
        nb = nb + "8";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_9)
    {
        effacementAuto();
        m_Btn9->setStyleSheet("QWidget{background:#343434;border:1px solid #1b1b1b}");
        QString nb;
        nb =  m_Eq1->text();
        if(nb == "0")
            nb ="9";
        else
        nb = nb + "9";
        m_Eq1->setText(nb);
    }
    if( event->key() == Qt::Key_Control )
    {

        pi = 1;
    }
    if(event->key() == Qt::Key_Backspace)
    {
        QString nb;
        nb =  m_Eq1->text();
        if(nb != "0")
         nb.chop(1);
        if(nb.isEmpty())
            nb="0";
        m_Eq1->setText(nb);
    }
    if(event->key() == Qt::Key_Plus)
      {
        effacementAuto();
        QString nb;
            nb =  m_Eq1->text();
            if (nb != "0")
            nb = nb + "+";
            m_Eq1->setText(nb);
        }
    if(event->key() == 0x2D)
    {
        effacementAuto();
        QString nb;
            nb =  m_Eq1->text();
            if(nb != "-")
            {
            if(nb == "0")
                nb ="-";
            else
            nb = nb + "-";
            m_Eq1->setText(nb);
            }
    }
    QWidget::keyPressEvent(event);
}
void manupPoly::recuperationC(QString text)
{
    int j;
    QString c;
    bool ok;
   A = 0;
   B = 0;

    for(j=0;j<text.length();j++)c = c + text[j];
    C = c.toInt(&ok,10);


}
void manupPoly::recuperationB(QString text)
{
    int i=0,j;
    QString b;
    bool ok;
    A = 0;
    C = 0;
    while (1) {
        if(text[i] == "x")
        {
            break;
        }
        i++;
    }

    for(j=0;j<i;j++)b = b + text[j];
   B = b.toInt(&ok,10);


}
void manupPoly::recuperationBC(QString text)
{
    int i=0,j,n;
    QString b,c;
    bool ok;
    A = 0;
    while (1) {
        if(text[i] == "x")
        {
            break;
        }
        i++;
    }

    for(j=0;j<i;j++)b = b + text[j];
   B = b.toInt(&ok,10);
    n = i + 1;

    for(j=n;j<text.length();j++)c = c + text[j];
    C = c.toInt(&ok,10);


}
void manupPoly::recuperationA(QString text)
{
    int i=0,j;
    QString a;
    bool ok;
    while (1) {
        if(text[i] == "x")
        {
            break;
        }
        i++;
    }
    for(j=0;j<i;j++)a = a + text[j];
   A = a.toInt(&ok,10);
    B=0;
    C=0;

}
void manupPoly::recuperationAC(QString text)
{
    int i=0,j,k;
    QString a,b,c;
    bool ok;
    while (1) {
        if(text[i] == "x")
        {
            break;
        }
        i++;
    }
    for(j=0;j<i;j++)a = a + text[j];
   A = a.toInt(&ok,10);
    B=0;
    k = i + 2;
    for(j=k;j<text.length();j++)c = c + text[j];
    C = c.toInt(&ok,10);

}

void manupPoly::recuperationABC(QString text)
{
    int i=0,j,n,k;
    QString a,b,c;
    bool ok;
    while (1) {
        if(text[i] == "x")
        {
            break;
        }
        i++;
    }

    for(j=0;j<i;j++)a = a + text[j];
   A = a.toInt(&ok,10);
    n = i + 2;
    i= i +2;
    while (1) {
        if(text[i] == "x")
        {
            break;
        }
        i++;
    }
    for(j=n;j<i;j++)b = b + text[j];
    B = b.toInt(&ok,10);
    k = i + 1;
    for(j=k;j<text.length();j++)c = c + text[j];
    C = c.toInt(&ok,10);

}
int manupPoly::verification(QString text,int y)
{
    int i,g=0,j=0,k=0,r=0,b=0,p=0,l=0,m=0,nbT2=0,nbS=0,nbSD=0,conX=0;
    QString nb;
    int position[2];
       position[0] = 0;
       position[1] = 0;



       for(i=0;i<text.length();i++)
       {
           if(text[i]=="x" )
           {

               j = j+1;

           }
       }
       if(j<=2)
       {
    for(i=0;i<text.length();i++)
    {
        if(text[i]== "²" )
        {

            b = b + 1;
        }
        if(text[i]== "²" && (text[i+1] == "-" || text[i+1] == "+" ))
        {

           l = 1;
        }
        if(text[i]== "x" && text[i+1] != "²" && (text[i+1] != "-" || text[i+1] != "+" ))
        {

           m = m+1;
        }
        if(text[i]=="x")
        {
            position[r] = i;
            //j = j+1;
            g=g+1;
            r = r + 1;
        }
        if(((text[i] == "+") || (text[i] == "-")) && (i==0) && ((text[i+1] != "+") || (text[i+1] != "-")))
        {
            k = k +1;
        }
        if(((text[i] == "+") || (text[i] == "-")) && ((text[i+1] == "+") || (text[i+1] == "-")))
        {
            p = 1;
        }
        if((text[i] == "+") || (text[i] == "-"))
        {
            nbS = nbS + 1;
        }
        if((text[0] != "-") && ((text[i] == "+")|| (text[i] == "-")))
        {
            nbSD = nbSD + 1;
        }
        if(text[position[0]-1] =="+" ||text[position[0]-1] =="-")
        {
            conX = 1;
        }
    }
    //ici on verifie s'il y'a ke C dans la valeur entrer
    if(position[0] == 0&&position[1] == 0 )
    {
        return -4;
    }
 //ici on verifie s'il y'a ke A dans la valeur entrer
    if(text[position[0] + 2].isNull())
    {
        nbT2 = 1;
    }
   if(nbT2==1 && conX == 0)
   {
       if(text[position[0]+1] == "²")
       {
          // m_Btn7->setText(QString::number(nbT2));
           if(y == 0)
           {
               nb =text+" + ";
                textEq1->setText(nb);
           }
           if(y == 1)
            {

               nb =  textEq1->text();
               nb =nb + text ;
               textEq1->setText(nb);
              }
           if(y == 2)
           {
               nb ="("+text+")"+" × ";
                textEq1->setText(nb);
           }
           if(y == 3)
           {
               nb =text+" - ";
                textEq1->setText(nb);
           }
           return 2;
       }

   }else
   {

  //on entre ici dans le cas ou A B C existe
       //k compte le nombre de signe dans l'equation
       //j vois le nombre de x dans l'equation
       // b verifie qu'il y'a k1 x²
       //g se rassure kil existe ke 2 x
       //p verifie ke les signes ne soient pas entrer 2 fois a la suite
       //l se rassure qu'apres x² c'est + ou - ki viennent
       //nbSD verifie k'il ait ke 2 signe dans l'equation apres x²
       //nbS se rassure kon ne trouve ke 3 signe au plus dans l'equation


    if(j != 0 && k<=3 && b==1 && g<3 && p == 0 && l==1  && nbS <= 3 && nbSD <= 2 )
    {
        //on verifie qu'effectivement apres le premier x on trouve ²

        if(text[position[0]+1] == "²"  )
        {



            //affichage du signe apres un click sur ls operations
            if(y == 0)
            {
                nb =text+" + ";
                 textEq1->setText(nb);
            }
            if(y == 1)
             {

                nb =  textEq1->text();
                nb =nb + text ;
                textEq1->setText(nb);
               }
            if(y == 2)
            {
                nb ="("+text+")"+" × ";
                 textEq1->setText(nb);
            }
            if(y == 3)
            {
                nb =text+" - ";
                 textEq1->setText(nb);
            }
          // on retourne 0 si on trouve 2 x dans l'equation entree
           if(g==2)
            return 0;
           // on retourne 1 si on trouve 1 x dans l'equation entree
           if(g==1)
               return 1;



        }
        else
            return -1;
    }
    // on retourne -2 si c'est une equation sous la forme ax+b
    else
        return -2;
       }
       }
    //on retourne -3 si ce n'est pas une equation

return -3;

}
Poly *manupPoly::Addition(Poly *p, int cf, int dg)
{
    if(p==NULL)
    {
        p = (Poly*)malloc(sizeof(Poly));
        p->coef = cf;
        p->deg = dg;
        p->suiv = NULL;
    }else
    {
     if(p->deg == dg)
     {
         p->coef = p->coef + cf;
     }else
         p->suiv = Addition(p->suiv,cf,dg);
    }
    return p;
}
Poly *manupPoly::Soustraction(Poly *p, int cf, int dg)
{
    if(p==NULL)
    {
        p = (Poly*)malloc(sizeof(Poly));
        p->coef = cf;
        p->deg = dg;
        p->suiv = NULL;
    }else
    {
     if(p->deg == dg)
     {
         p->coef = p->coef - cf;
     }else
         p->suiv = Soustraction(p->suiv,cf,dg);
    }
    return p;
}
Poly *manupPoly::insertionPolySimp(Poly *p, int cf, int dg)
{
    if(p==NULL)
    {
        p = (Poly*)malloc(sizeof(Poly));
        p->coef = cf;
        p->deg = dg;
        p->suiv = NULL;
    }else
    {

         p->suiv = insertionPolySimp(p->suiv,cf,dg);
    }
    return p;
}
int manupPoly::detRaccine(int a,int b,int c)
{
    int delta;

    delta = pow(b,2) - (4*a*c);
    if(delta<0)
    {
        return 0;
    }
    if(delta == 0)
    {
        float v;
        v= 2*a;
        v = -b/v;
        m_x0 = v;
         //m_Btn7->setText(QString::number(m_x0));
        return 1;
    }
    if(delta>0)
    {
        m_x1 = (-b + sqrt(delta))/(2*a);
        m_x2 = (-b - sqrt(delta))/(2*a);
        return 2;
    }
    return -1;
}
void manupPoly::Affichage(int a)
{
     QString nb;
      if(a == 1)
      {
          if(m_P->coef !=0)
             nb = QString::number(m_P->coef)+"x²";
      if(m_P->suiv->coef>0)
      {
          if(m_P->coef ==0)
          nb = nb +QString::number(m_P->suiv->coef)+"x";
          else
             nb = nb + "+"+QString::number(m_P->suiv->coef)+"x";
      }else
      {
          if(m_P->coef ==0)
          nb = nb +QString::number(m_P->suiv->coef)+"x";
          if(m_P->suiv->coef!=0)
          nb = nb +QString::number(m_P->suiv->coef)+"x";
      }
      if(m_P->suiv->suiv->coef>0)
      {

          if(m_P->suiv->coef==0 && m_P->coef ==0)
              nb =  QString::number(m_P->suiv->suiv->coef);
          else
             nb = nb+"+"+QString::number(m_P->suiv->suiv->coef);
      }
      else
      {
          if(m_P->suiv->coef==0 && m_P->coef ==0)
            nb = nb+QString::number(m_P->suiv->suiv->coef);
          if(m_P->suiv->suiv->coef!=0)
           nb = nb+QString::number(m_P->suiv->suiv->coef);
      }
      }
      if(a == 2)
      {
          Poly *q,*p;
          int i=0;

          p = m_P3;
          while (p!=NULL) {

              i = i+1;

             p = p->suiv;
          }
          if(m_P3->coef ==0 && m_P3->suiv->coef != 0)
          {
              nb = nb+monteurDeP(m_P3->suiv->deg,m_P3->suiv->coef);
              q = m_P3->suiv->suiv;
              while (q!=NULL) {


                  if(q->coef>0)
                  {
                      nb = nb + "+"+monteurDeP(q->deg,q->coef);
                  }else
                  {
                      if(q->coef !=0)
                      nb = nb +monteurDeP(q->deg,q->coef);
                  }
                 q = q->suiv;
              }
          }
          if(m_P3->coef ==0 && m_P3->suiv->coef == 0 && m_P3->suiv->suiv->coef !=0)
          {
              nb = nb+monteurDeP(m_P3->suiv->suiv->deg,m_P3->suiv->suiv->coef);
              q = m_P3->suiv->suiv->suiv;
              while (q!=NULL) {


                  if(q->coef>0)
                  {
                      nb = nb + "+"+monteurDeP(q->deg,q->coef);
                  }else
                  {
                      if(q->coef !=0)
                      nb = nb +monteurDeP(q->deg,q->coef);
                  }
                 q = q->suiv;
              }
          }
          if(m_P3->coef ==0 && m_P3->suiv->coef == 0 && m_P3->suiv->suiv->coef == 0 && m_P3->suiv->suiv->suiv->coef !=0)
          {
              nb = nb+monteurDeP(m_P3->suiv->suiv->suiv->deg,m_P3->suiv->suiv->suiv->coef);
              q = m_P3->suiv->suiv->suiv->suiv;
              while (q!=NULL) {


                  if(q->coef>0)
                  {
                      nb = nb + "+"+monteurDeP(q->deg,q->coef);
                  }else
                  {
                      if(q->coef !=0)
                      nb = nb +monteurDeP(q->deg,q->coef);
                  }
                 q = q->suiv;
              }
          }
          if(m_P3->coef ==0 && m_P3->suiv->coef == 0 && m_P3->suiv->suiv->coef == 0 && m_P3->suiv->suiv->suiv->coef ==0)
          {
              nb = nb+monteurDeP(m_P3->suiv->suiv->suiv->suiv->deg,m_P3->suiv->suiv->suiv->suiv->coef);
              q = m_P3->suiv->suiv->suiv->suiv->suiv;
              while (q!=NULL) {


                  if(q->coef>0)
                  {
                      nb = nb + "+"+monteurDeP(q->deg,q->coef);
                  }else
                  {
                      if(q->coef !=0)
                      nb = nb +monteurDeP(q->deg,q->coef);
                  }
                 q = q->suiv;
              }
          }

          /*if(m_P3->coef ==0 && m_P3->suiv->coef == 0 && m_P3->suiv->suiv->coef == 0 && m_P3->suiv->suiv->suiv->coef ==0 && m_P3->suiv->suiv->suiv->suiv->coef == 0)
          {
              nb = nb+monteurDeP(m_P3->suiv->suiv->suiv->suiv->suiv->deg,m_P3->suiv->suiv->suiv->suiv->suiv->coef);

          }*/
         // m_Btn7->setText(QString::number(i));
          if(m_P3->coef !=0)
         {
          nb = nb+monteurDeP(m_P3->deg,m_P3->coef);
          q = m_P3->suiv;
          while (q!=NULL) {


              if(q->coef>0)
              {
                  nb = nb + "+"+monteurDeP(q->deg,q->coef);
              }else
              {
                  if(q->coef !=0)
                  nb = nb +monteurDeP(q->deg,q->coef);
              }
             q = q->suiv;
          }
          }
          //°¹²³⁴⁵⁶⁷⁸⁹

      }
      if(a == 3)
      {
          if(m_P->coef !=0)
          nb = QString::number(m_P->coef)+"x²";
            if(m_P->suiv->coef>0)
            {
                if(m_P->coef ==0)
                nb = nb +QString::number(m_P->suiv->coef)+"x";
                else
                    nb = nb + "+"+QString::number(m_P->suiv->coef)+"x";
            }else
            {
                if(m_P->suiv->coef !=0)
                nb = nb +QString::number(m_P->suiv->coef)+"x";
                else {
                   if(m_P->coef ==0 && m_P->suiv->suiv->coef == 0 )
                       nb = "0";
                }
             }

            if(m_P->suiv->suiv->coef>0)
                  nb = nb+"+"+QString::number(m_P->suiv->suiv->coef);
            else{
                if(m_P->suiv->suiv->coef !=0)
                 nb = nb+QString::number(m_P->suiv->suiv->coef);
            }
      }
      if(a == 4)
      {
          if(m_P->coef !=0)
          nb = QString::number(m_P->coef)+"x²";
            if(m_P->suiv->coef>0)
            {
                if(m_P->coef ==0)
                nb = nb +QString::number(m_P->suiv->coef)+"x";
                else
                    nb = nb + "+"+QString::number(m_P->suiv->coef)+"x";
            }else
            {
                if(m_P->suiv->coef !=0)
                nb = nb +QString::number(m_P->suiv->coef)+"x";
                else {
                   if(m_P->coef ==0 && m_P->suiv->suiv->coef == 0 )
                       nb = "0";
                }
             }

            if(m_P->suiv->suiv->coef>0)
                  nb = nb+QString::number(m_P->suiv->suiv->coef);
            else{
                if(m_P->suiv->suiv->coef !=0)
                 nb = nb+QString::number(m_P->suiv->suiv->coef);
            }
      }
    m_Eq1->setText(nb);
}
void manupPoly::multiplication(Poly *p,Poly *p2)
{
    Poly *q,*r;
    int cf,dg;
    m_P3 = NULL;
    q = p;
    r = p2;
    while(q !=NULL )
    {
        //cf = q->coef * r;
        while(r!=NULL)
        {
            cf = q->coef * r->coef;
            dg = q->deg + r->deg;
            m_P3 = Addition(m_P3,cf,dg);
            r = r->suiv;
        }
        r = p2;
        q = q->suiv;
    }
}
QString manupPoly::monteurDeP(int a,int b)
{
     QString nb;
    switch (a) {
    case 1:
         nb = QString::number(b)+"x";
        break;
    case 2:
         nb = QString::number(b)+"x²";
        break;
     case 3:
        nb = QString::number(b)+"x³";
        break;
    case 4:
       nb = QString::number(b)+"x⁴";
       break;
    case 5:
       nb = QString::number(b)+"x⁵";
       break;
    case 6:
       nb = QString::number(b)+"x⁶";
       break;
    case 7:
       nb = QString::number(b)+"x⁷";
       break;
    case 8:
       nb = QString::number(b)+"x⁸";
       break;
    case 9:
       nb = QString::number(b)+"x⁹";
       break;
    default:
        nb = QString::number(b);
        break;
    }
    return nb;
}
void manupPoly::effacementAuto()
{
    m_AffFacto->setText(0);
    //textEq1->setText(" ");
    textEq2->setText(" ");
    smille->setVisible(false);
    m_Msg->setText(0);
}
void manupPoly::manupFichier(QLabel *Affch)
{

    ifstream fic("aide.txt");
    if(fic)
    {

        string ligne;
        QString f;

            while (getline(fic,ligne))
            {
                f = QString::fromStdString(ligne);
               Affch->setText(Affch->text()+f+"\n");
            }


    }
}
