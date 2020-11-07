#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include <time.h>
#include<conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
  /*liste chainee; chaque element de la liste enregistre une position precise(abscisse+ordonnee)*/
struct Liste_possibilitees
{
    int abscisse;
    int ordonnee;
    struct Liste_possibilitees *suivant;
};
typedef struct Liste_possibilitees Liste_possibilitees;
Liste_possibilitees *suppression(Liste_possibilitees *liste,Liste_possibilitees *transfert);
Liste_possibilitees *insertion(Liste_possibilitees *liste,int abscisse,int ordonnee);
void Affiche_possibilite(Liste_possibilitees *liste);
int taille_liste(Liste_possibilitees *liste);
void vider_liste(Liste_possibilitees *liste);
#include "liste.h"
#include "outil.h"
#include "pile.h"
#include "deplacement.h"
#include "gestion_echec.h"
#include "gestion_ia.h"
#include "gestion_parties.h"
#include "jeu.h"
#include "profils.h"
#include "règles_secondaires.h"
#include "timer.h"


#include "deplacement.c"
#include "gestion_echec.c"
#include "gestion_ia.c"
#include "gestion_parties.c"
#include "jeu.c"
#include "liste.c"
#include "outil.c"
#include "pile.c"
#include "profils.c"
#include "règles_secondaires.c"
#include "timer.c"



#endif // LISTE_H_INCLUDED
