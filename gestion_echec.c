
int test_echec(int Plateau[][8],int couleur){/*fonction qui prend en entree la couleur du joueur qui doit jouer et retourne 1 si le roi de cette couleur
    est en echec 0 sinon*/
    int abscisse_roi,ordonnee_roi,i,j,echec=0,val_roi,couleur_adverse;
    int tab_tempo[2];
    Liste_possibilitees *liste=NULL;
    val_roi = 100*couleur + 61;
    Recherche_piece(tab_tempo,val_roi,Plateau);
    abscisse_roi =tab_tempo[0];
    ordonnee_roi =tab_tempo[1];
    if(couleur==1){
        couleur_adverse=2;
    }
    else{
        couleur_adverse=1;
    }
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if((int)Plateau[i][j]/100 ==couleur_adverse){
                liste=Possibilite_modifie(Plateau,j,i,liste);/*ici très important détail, on utilise la fonction Possibilite_modifie et non Posibilite
                                                               pourquoi? Car dans Possibilite on utilise la fonction test_echec ce qui impliquerait une boucle
                                                               = plantage */
                while(liste !=NULL){
                    if(liste->abscisse == abscisse_roi && liste->ordonnee == ordonnee_roi){
                        echec = 1;
                    }
                    liste=liste->suivant;
                }
            }
        }
    }
    return echec;
}

void gestion_echec(int *couleur,int Plateau[][8],int *continuer,int *heure1,int *minute1,int *seconde1,int *heure2,int *minute2,int *seconde2,int *bg,int *ng,int *e,char *nom1,char *nom2,Pile **pile_depart,Pile **pile_fin,char couleur_choix_h,int n_Partie){
    int i,j,echec_mat=1,bonne_piece=1,erreur=1,nombre_piece=-1,valeur1=1,valeur2=1,echec=1;
    int tab_position_piece[2];
    Liste_possibilitees *liste=NULL;
    char piece[5],case_entree[3],*case_piece;
    Liste_possibilitees *liste3=NULL;
    int p_e_p;
    char sortie;
    char chaine_save[4];
    char *chgmt_pion;
    int X,Y;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if((int)Plateau[i][j]/100 == *couleur){
                liste=Possibilite(Plateau,j,i,liste,*couleur,*pile_depart,*pile_fin,&p_e_p);
                if(liste!=NULL){
                    echec_mat=0;
                }

            }
        }
    }
    p_e_p=0;
    int indice_ia=0;
    int couleur_ia=0;
    if(strcmp(nom2,"ordinateur")==0){
        indice_ia=1;
        if(couleur_choix_h=='b'){
            couleur_ia=2;
        }
        else{
            couleur_ia=1;
        }

    }



    /*jusqu'ici on enregistre la valeur en int des pieces qui peuvent empecher l'echec dans le tableau "tab_piece" ainsi, le joueur ne
    peut deplacer que certaines pieces. De plus on enregistre les cases qui empechent l'echec dans la liste "liste2",on peut avoir des doublons
    style : D2  D2  ... on n'a pas besoin de savoir quelle case vient de quelle piece, ce n'est pas necessaire pour le bon fonctionnement. Dernier
    point, si on a "tab_piece" qui n'a comme valeur que des 0, c'est un echec et mat, utile pour la suite.*/


    if(echec_mat==0){
        do{
            if(indice_ia==0 || (indice_ia==1 && *couleur!=couleur_ia)){
                while(valeur1){
                    counter(&valeur1,piece,*couleur,1,heure1,minute1,seconde1,heure2,minute2,seconde2,liste,Plateau,echec);
                }
            }
            if(indice_ia==1 && *couleur==couleur_ia){
                piece_et_case_aleatoire(case_entree,piece,Plateau,*couleur);

            }
            if(strcmpi(piece,"Q")==0){
                printf("Partie %d sauvegarde avec success\nEtes vous sur de vouloir quitter ?(o/n) : ",n_Partie);
                fflush(stdin);
                scanf("%c",&sortie);
                if(sortie=='o' || sortie =='O'){
                    jouer(0);
                }
                raffraichissemente_ecran(Plateau,nom1,nom2,*couleur,1,n_Partie);
            }
            else{
                nombre_piece = Traducteur_Inv(piece);
                Recherche_piece(tab_position_piece,nombre_piece,Plateau);
                X=tab_position_piece[0];
                Y=tab_position_piece[1];
                case_piece=Coord_to_Nom(tab_position_piece[0],tab_position_piece[1]);
                liste3 = Possibilite(Plateau,tab_position_piece[0],tab_position_piece[1],liste3,*couleur,*pile_depart,*pile_fin,&p_e_p);
                if((int)nombre_piece/100 == *couleur){
                    if(liste3!=NULL){
                        *pile_depart = empiler(*pile_depart,case_piece);
                        if(indice_ia==0 || (indice_ia==1 && *couleur!=couleur_ia)){
                            while(valeur2){
                                counter(&valeur2,case_entree,*couleur,2,heure1,minute1,seconde1,heure2,minute2,seconde2,liste3,Plateau,echec);
                            }
                        }
                        valeur2=1;
                        do{
                            char *case_coord;
                            case_coord=Coord_to_Nom(liste3->abscisse,liste3->ordonnee);//modif liste->4 en liste->3
                            if(strcmp(case_entree,case_coord)==0){
                                *pile_fin=empiler(*pile_fin,case_entree);
                                Remplacer(Plateau,case_entree,case_piece);
                                erreur=0;
                                break;
                            }
                            liste3=liste3->suivant;
                        }while(liste3!=NULL);
                        if(erreur){
                            raffraichissemente_ecran(Plateau,nom1,nom2,*couleur,1,n_Partie);
                            printf("\ncase invalide");
                        }
                        else{/*prise en passant */
                            Sauvegarde(n_Partie,strcat(piece,case_entree));
                            if(p_e_p==1){
                                Plateau[Y][X+1]=0;
                                strcpy(chaine_save,"DPP");
                                Sauvegarde(n_Partie,strcat(chaine_save,Coord_to_Nom(X,Y)));
                            }
                            else if(p_e_p==-1){
                                Plateau[Y][X-1]=0;
                                strcpy(chaine_save,"GPP");
                                Sauvegarde(n_Partie,strcat(chaine_save,Coord_to_Nom(X,Y)));
                            }

                            *couleur = changement_couleur(*couleur);
                            raffraichissemente_ecran(Plateau,nom1,nom2,*couleur,1,n_Partie);
                            chgmt_pion = Changement_Pion(Plateau,indice_ia,*couleur,couleur_ia);
                            if(chgmt_pion!=NULL){
                                Sauvegarde(n_Partie,chgmt_pion);
                            }


                        }
                        bonne_piece=0;
                    }
                    else{
                        raffraichissemente_ecran(Plateau,nom1,nom2,*couleur,1,n_Partie);
                        printf("\nVous ne pouvez pas jouez cette piece");
                    }
                }
                else{
                    raffraichissemente_ecran(Plateau,nom1,nom2,*couleur,1,n_Partie);
                    if(*couleur ==1){
                        printf("\nc'est au tour des blancs !");
                    }
                    else{
                        printf("\nc'est au tour des noirs !");
                    }
                }

            }
            valeur1=1;
        }while(bonne_piece);
    }
    else{                                          /*si condition echec et mat valide, on vient ici*/
        raffraichissemente_ecran(Plateau,nom1,nom2,*couleur,0,n_Partie);
        printf("\nECHEC ET MAT");

        if(*couleur==1){
            *ng=1;
            printf("\tLes noirs ont gagne\n");
        }
        else{
            *bg=1;
            printf("\tLes blancs ont gagne\n");
        }
        *continuer =0;
    }
}
