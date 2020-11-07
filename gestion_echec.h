#ifndef GESTION_ECHEC_H_INCLUDED
#define GESTION_ECHEC_H_INCLUDED


int test_echec(int Plateau[][8],int couleur);
void gestion_echec(int *couleur,int Plateau[][8],int *continuer,int *heure1,int *minute1,int *seconde1,int *heure2,int *minute2,int *seconde2,int *bg,int *ng,int *e,char *nom1,char *nom2,Pile **pile_depart,Pile **pile_fin,char couleur_choix_h,int n_Partie);


#endif // GESTION_ECHEC_H_INCLUDED
