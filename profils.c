

void modaliteAccess(char *nom,char *password,int nbJoueur,int message,char *couleur_choix_h){
    /*menu avant de joueur à la partie*/
    int choix;
    char rep;

    printf("*************Joueur %d ************\n ",nbJoueur);
    if(message==1){
        printf("Votre choix est invalide\n");
    }
    if(message==2){
        printf("Desole, vous ne pouvez pas vous connecter, vos informations sont incorrectes, verifiez votre login ou  votre password\n");
    }
    if(message==3){
        printf("Desole, ce 'login' existe deja choisissez en un autre\n");
    }
    do{

        printf("Etes vous deja membre ou voulez vous vous enregistrer?\n ");
        if(nbJoueur==2){
            printf("1) Jouer contre l'ordinateur\n ");
            printf("2) Deja membre\n ");
            printf("3) S'enregistrer\n ");
            printf("4) Menu\n ");
            printf("5) Quitter\n ");
            printf("Entrez votre choix :");
        }
        else{
            printf("1) Deja membre\n ");
            printf("2) S'enregistrer\n ");
            printf("3) Menu\n ");
            printf("4) Quitter\n ");
            printf("Entrez votre choix :");
        }






        scanf("%d",&choix);
        if(choix!=1 && choix!=2 && choix!=3 && choix!=4){
            system("cls");
            printf("saisie invalide,reesayez\n");
        }
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4);
    if(nbJoueur==2){
        choix--;
    }

    switch(choix){
        case 0:
            do{
                printf("Choisissez la couleur que vous voulez jouer (b/n) :");
                fflush(stdin);
                scanf("%c",couleur_choix_h);
            }while(*couleur_choix_h !='b' && *couleur_choix_h !='n');


            strcpy(nom,"ordinateur");
            strcpy(password,"ordinateur");
            break;
        case 1 :
            printf("Login :");
            scanf("%s",nom);
            printf("\nPassword :");
            scanf("%s",password);
            if(chekConnexion(nom,password)!=1){
                system("cls");
                modaliteAccess(nom,password,nbJoueur,2,NULL);
            }
            break;
        case 2:
            printf("Login :");
            scanf("%s",nom);
            printf("\nPassword :");
            scanf("%s",password);
            if(existJoueur("joueurs.txt",nom)){
                system("cls");
                modaliteAccess(nom,password,nbJoueur,3,NULL);
            }
            else{
                ajouterJoueur("joueurs.txt",nom);
                ajouterProfils("profiljoueurs.txt",nom,password,0,0,0);
            }
            break;
       case 3:
            jouer(0);
            break;
       case 4:
            system("cls");
            printf("voulez vous vraiment quiter (o/n)? : ");
            fflush(stdin);
            scanf("%c",&rep);
            if(rep!='n'){
                exit(0);
            }
            else{
                system("cls");
                modaliteAccess(nom,password,nbJoueur,0,NULL);
            }
            break;
        }

}
int chekConnexion(char *nom,char*password){
    /* 1 si c'est bon 0 sinon*/
    char Nom[35];char Password[35];
    int g,p,e;
    FILE *f= fopen("profiljoueurs.txt","r");
    fseek(f,0,SEEK_SET);
    while(fscanf(f,"%s %s %d %d %d",Nom,Password,&g,&p,&e)!= EOF){
        if(strcmp(Nom,nom)==0){
            if(strcmp(Password,password)==0){
                fclose(f);
                return 1;
            }
        }
    }
    fclose(f);
    return 0;
}
int existJoueur(char * fichier,char *nom){
    char Nom[35];
    FILE *f= fopen(fichier,"r");
    fseek(f,0,SEEK_SET);
    while(fscanf(f,"%s",Nom)!= EOF)
    {
        if(strcmp(Nom,nom)==0){
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}
void ajouterJoueur(char *fichier,char*nom){
    FILE *f1= fopen(fichier,"a");
    fprintf(f1,"%s\n",nom);
    fclose(f1);
}
void ajouterProfils( char *fichier,char *nom,char *password,int gagne,int perdue,int egalite){

        FILE *f1= fopen(fichier,"a");
        fprintf(f1,"%s %s %d %d %d\n",nom,password,gagne,perdue,egalite);
        fclose(f1);
}


void profil(){
    int choix ;
    system("cls");
    do{
        printf("******************Profil******************\n");
        printf("1) Voir son profil\n");
        printf("2) Voir tous les profils et leur stats\n");
        printf("3) Changer password\n");
        printf("4) S'enregistrer\n");
        printf("5) Menu\n");
        printf("Entrez votre choix : ");
        scanf("%d",&choix);
        if(choix!=1 && choix!=2 && choix !=3 && choix !=4 && choix!=5 && choix!=6){
            system("cls");
            printf("erreur saisie\n");
        }
    }while(choix!=1 && choix!=2 && choix !=3 && choix !=4 && choix!=5 && choix!=6);
    switch(choix){
        case 1:
            voirProfil();
            break;
        case 2 :
            affiche_tous_profils();
            break;
        case 3 :
            changePassword();
            break;
        case 4 :
            signin();
            break;
        case 5 :
            jouer(0);
            break;
    }
}
void voirProfil(){
    char password[35];char login[35];
    char arriere,rep,reessayer;
    printf("Entrez vos donnees de profil\n");
    printf("login : ");
    scanf("%s",login);
    printf("\npassword : ");
    scanf("%s",password);
    if(chekConnexion(login,password)!=1){
        do{
            system("cls");
            printf("*********informations de connexion incorrectes*********\n");
            printf("Reessayer (o/n)? : ");
            fflush(stdin);
            scanf("%c",&reessayer);
        }while(reessayer!='o' && reessayer!='n');
        if(reessayer=='o'){
            voirProfil();
        }
        else{
            profil();
        }
    }

    else{
        int choix;

        do{
            system("cls");
            afficherProfil(login);
            printf("\n revenir en arriere (o/n)?");
            fflush(stdin);
            scanf("%c",&arriere);
        }while(arriere!='o');


        do{
            system("cls");
            printf("\n1) Profil \n");
            printf("2) Quitter \n");
            printf("Entrez votre choix : ");
            scanf("%d",&choix);
            if(choix!=1 && choix!=2){
                system("cls");
                printf("erreur saisie\n");
            }
        }while(choix!=1 && choix!=2);
        switch(choix){
            case 1:
                profil();
                break;
            case 2 :
                system("cls");
                printf("voulez vous vraiment quiter (o/n)? : ");
                fflush(stdin);
                scanf("%c",&rep);
                if(rep!='n'){
                    exit(0);
                }
                else{
                    profil();;
                }
                break;
        }
    }
}
void afficherProfil(char *nom){
    char Nom[35];
    char Password[35];
    int g,e,p;
    FILE *f= fopen("profiljoueurs.txt","r");
    while(fscanf(f,"%s %s %d %d %d",Nom,Password,&g,&p,&e)!= EOF)
    {   if(strcmp(Nom,nom)==0)
        {
           printf("Votre login est : %s\n",nom);
           printf("Votre Password est : %s\n",Password);
           printf("vous avez gagne %d partie(s) \n",g);
           printf("vous avez perdu %d partie(s) \n",p);
           printf("Vous avez %d egalite(s)  \n",e);
        }
    }
}
void affiche_tous_profils(){
    char login[35],password[35];
    char arriere;
    int v,d,e;

    FILE *f=fopen("profiljoueurs.txt","r");
    system("cls");
    while(fscanf(f,"%s %s %d %d %d",login,password,&v,&d,&e)!=EOF){
        printf("%s a %d victoire(s), %d defaite(s) et %d nul(s)\n",login,v,d,e);
    }
    do{
        printf("\n revenir en arriere (o/n)? : ");
        fflush(stdin);
        scanf("%c",&arriere);
        if(arriere !='o'){
            system("cls");
        }
    }while(arriere !='o');
    profil();

}
void changePassword(){
    char Nom[35],Password[35],nouveau[35],ancien[35],nom [35];
    int g,e,p;
    char rep;
    system("cls");
    printf("login : ");
    scanf("%s",Nom);
    printf("\nAncien password : ");
    scanf("%s",Password);


    printf("\nNouveau password : ");
    scanf("%s",nouveau);


    if(chekConnexion(Nom,Password)!=1){
        changePassword();
    }
    else{
        FILE *f= fopen("profiljoueurs.txt","r");
        FILE *f1=fopen("temp.txt","a");

        while(fscanf(f,"%s %s %d %d %d",nom,ancien,&g,&p,&e)!= EOF){
            if(strcmp(Nom,nom)!=0){
                fprintf(f1,"%s %s %d %d %d\n",nom,ancien,g,p,e);
            }
            else{
                fprintf(f1,"%s %s %d %d %d\n",nom,nouveau,g,p,e);
            }
        }
        fclose(f);
        fclose(f1);
        remove("profiljoueurs.txt");
        rename("temp.txt","profiljoueurs.txt");
        int choix;
        system("cls");
        printf("mot de passe change avec succes\n");
        do{
            printf("1) Menu  \n");
            printf("2) Profil \n");
            printf("3) Changer mot de passe \n");
            printf("4) Quitter \n");
            printf("Entrez votre choix : ");
            scanf("%d",&choix);
            if(choix>4 || choix <1){
                system("cls");
                printf("Erreur saisie\n");
            }
        }while(choix>4 || choix <1);
        switch(choix){
            case 1:
                jouer(0);
                break;
            case 2 :
                profil();
                break;
            case 3 :
                changePassword();
                break;
            case 4 :
                system("cls");
                printf("voulez vous vraiment quiter (o/n)? : ");
                fflush(stdin);
                scanf("%c",&rep);
                if(rep!='n'){
                    exit(0);
                }
                else{
                    changePassword();
                }
                break;
        }

    }
}
void signin(){
   char nom[53],password[53];int choix;
   char rep;
   system("cls");
   printf("Login : ");
   scanf("%s",nom);
   printf("Password : ");
   scanf("%s",password);
   if(existJoueur("joueurs.txt",nom)){
        system("cls");
        printf("Ce joueur existe deja choisissez un autre nom\n");
   }
   else{
        ajouterJoueur("joueurs.txt",nom);
        ajouterProfils("profiljoueurs.txt",nom,password,0,0,0);
   }
    do{
        printf("\n1) Menu  \n");
        printf("2) Profil \n");
        printf("3) Quitter \n");
        printf("Votre choix : ");
        scanf("%d",&choix);
        if(choix<1 || choix >3){
            system("cls");
            printf("Erreur saisie\n");
        }
    }while(choix<1 || choix >3);
    switch(choix){
        case 1:
            jouer(0);
            break;
        case 2:
            profil();
            break;
        case 3:
            system("cls");
            printf("voulez vous vraiment quiter (o/n)? : ");
            fflush(stdin);
            scanf("%c",&rep);
            if(rep!='n'){
                exit(0);
            }
            else{
                profil();
            }
            break;
    }
}

