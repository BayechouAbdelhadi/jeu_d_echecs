#ifndef PROFILS_H_INCLUDED
#define PROFILS_H_INCLUDED
int existJoueur(char * fichier,char *nom);
void modaliteAccess(char *nom,char *password,int nbJoueur,int message,char *couleur_choix_h);
int chekConnexion(char *nom,char*password);
void ajouterJoueur(char *fichier,char*nom);
void ajouterProfils( char *fichier,char *nom,char *password,int gagne,int perdue,int egalite);
void afficherProfil(char *nom);
void profil();
void voirProfil();

void affiche_tous_profils();
void changePassword();
void signin();

void actualiser_stats(char *Nom,int bg,int ng,int eq,int joueur);
void actualiser_statut(int n_Partie);
void jouer(int message);
void regle(char *joueur1,char *joueur2);
void nouvellePartie();
#endif // PROFILS_H_INCLUDED
