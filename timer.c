
void printData(int joueur,int heure1,int minute1,int seconde1,int heure2,int minute2,int seconde2,int Plateau[][8]){
    if(joueur==1){
        SCC_GotoXY(0,39);
        printf("%.2d : %.2d : %.2d",heure1,minute1,seconde1);/*fonction qui permet d'afficher le chrono et qui a chaque �crase le chrono de la seconde
                                                                    pr�c�dente grace � la fonction SCC_GotoXY*/
    }
    if(joueur==2){
        SCC_GotoXY(0,39);
        printf("%.2d : %.2d : %.2d",heure2,minute2,seconde2);
    }
}

void delay(int ms){      //fait un delay, une pause dans le programme
    clock_t timeDelay = ms+clock();
    while(timeDelay>clock());

}
void counter(int *valeur,char *nom,int joueur,int caseoupiece,int *heure1,int *minute1,int *seconde1,int *heure2,int *minute2,int *seconde2,Liste_possibilitees *liste,int Plateau[][8],int echec){
    /* kbhit() est une fonctionnalit� de windows.h qui vaut 1 si l'on entre quelquechose au clavier 0 sinon, permet de stopper la boucle d�s que l'utilisateur
    a d�cid� de jouer et qu'il entre le nom de la pi�ce*/
    if(joueur==1){
            while(!kbhit()){

                if(*minute1<0){
                    *minute1=59;
                    *heure1-=1;
                }
                if(*seconde1<0){
                    *seconde1=59;
                    *minute1-=1;
                }
                printData(joueur,*heure1,*minute1,*seconde1,*heure2,*minute2,*seconde2,Plateau);
                if(caseoupiece==2){/* caseoupiece depend de o� se situe la fonction dans le main si elle est autour d'un enregistrement de case
                                      c'est 2 sinon c'est 1 car pour la saisie de case il faut affficher les possibilit�s d'abord donc deux cas diff�rents*/
                    printf("\n");
                    if(echec){/* lorsqu'on entre dans la branche o� on est en �chec c'est 1 sinon 0*/
                        printf("ECHEC");
                    }
                    printf("\n");
                    SCC_GotoXY(0,44);
                    Affiche_possibilite(liste);

                    printf("\nEntrez le nom de la case : ");
                }
                else{
                    if(echec){
                        printf("\nECHEC");
                    }
                    SCC_GotoXY(0,40);
                    printf("\nEntrez le nom de la piece : ");
                }
                delay(910);
                *seconde1-=1;
                gagner_perdu(joueur,*heure1,*minute1,*seconde1,*heure2,*minute2,*seconde2);
            }
            selection(valeur,nom);/* enregistre la case ou la piece pas d'allocation m�moire dans cette fonction c 'est fait avant l'appel de la fonction*/
    }
    else{
        while(!kbhit()){

                if(*minute2<0){
                    *minute2=59;
                    *heure2-=1;
                }
                if(*seconde2<0){
                    *seconde2=59;
                    *minute2-=1;
                }
                printData(joueur,*heure1,*minute1,*seconde1,*heure2,*minute2,*seconde2,Plateau);
                if(caseoupiece==2){
                    printf("\n");
                    if(echec){
                        printf("ECHEC");
                    }
                    printf("\n");
                    SCC_GotoXY(0,44);
                    Affiche_possibilite(liste);

                    printf("\nEntrez le nom de la case : ");
                }
                else{
                    if(echec){
                        printf("\nECHEC");
                    }
                    SCC_GotoXY(0,40);
                    printf("\nEntrez le nom de la piece : ");
                }
                delay(910);
                *seconde2-=1;
                gagner_perdu(joueur,*heure1,*minute1,*seconde1,*heure2,*minute2,*seconde2);
            }
            selection(valeur,nom);
    }


}

void selection(int *valeur,char *nom){

    scanf("%s",nom);
    printf("\n");
    *valeur=0;


}

void gagner_perdu(int joueur,int heure1,int minute1,int seconde1,int heure2,int minute2,int seconde2){/*detecte lorsque le chrono est � 0 et met fin � la partie*/
    if(joueur==1){
            if(heure1==0){
                if(minute1==0){
                    if(seconde1 ==0){
                        printf("\n\tles blancs ont perdu !");
                        exit(0);
                    }
                }
            }
    }
    else{
            if(heure2==0){
                if(minute2==0){
                    if(seconde2 ==0){
                        printf("\n\tles noirs en perdu !");
                        exit(0);
                    }
                }
            }
    }

}
void SCC_GotoXY(int x, int y){

    /* fonction qui d�place le curseur virtuel de la console � une abscisse et une ordonn�e pr�cise
                                il est utilis� pour �craser la valeur du chrono sans toucher au reste c'est ce qui m'a permis
                                de garder le chrono car sans �a j'utilisais la commande system("cls") qui faisait clignoter tout
                                ce qui �tait � l'�cran, tr�s d�sagr�able pour jouer*/



    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X = x;
    C.Y = y;
    SetConsoleCursorPosition(H, C);
}
void setup_chrono(int *heure,int *minute,int Plateau[][8],char *nom1,char *nom2,int couleur,int n_Partie){ /* demande le nombre de minutes que les joueurs s'accordent pour leur partie*/
    printf("\n\nChoisissez une duree de partie entre 5 heures et 1 minute soit une plage en minute de 1 a 300 : ");
    int min;
    do{
        scanf("%d",&min);
        if((int)min <1 || (int)min >300){
            printf("\n\t\tvaleur hors plage, reessayer : ");
        }
    }while((int)min <1 || (int)min >300);
    *heure = (int)min/60;
    *minute = (int)min%60;
    system("cls");
    Afficher(Plateau,nom1,nom2,couleur,1,n_Partie);
}
