#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
void Menu(int *choix);
void actualiser_stats(char *Nom,int bg,int ng,int eq,int joueur);
void actualiser_statut(int n_Partie);
void jouer(int message);
void regle(char *joueur1,char *joueur2);
void nouvellePartie();
void deroulement_jeu(int Plateau[][8],int *bg,int *ng,int *e,char *nom1,char *nom2,char couleur_choix_h,int n_Partie,int couleur_debut);
void aide();
#endif // JEU_H_INCLUDED
