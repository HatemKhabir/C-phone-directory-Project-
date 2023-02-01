
#include <stdio.h>


typedef struct
{
 char numero_telephone[9];
 char nom[20];
 char date_naissence[11];
 char prenom[20];
 char email[40];
 char rue[30];
char ville [20];
int  code_postale;
}persone;

struct cellule
{
  persone info ;
struct cellule *suivant;
};

struct liste
{struct cellule* premier;
struct cellule* dernier;
};
void creer_liste_vide(struct liste *);
int liste_vide(struct liste);
void initialiser_liste(struct liste *  );
void inserer_queue_tel(struct liste *);
void inserer_tete_tel(struct liste * );
void remplir_liste(struct liste *);
void insere_pos_tel(struct liste *);
persone saisie_personne();
void affichage (struct liste );
int taille_liste_rep(struct liste );
void supprimer_queue_tel(struct liste *);
void supprimer_tete_tel(struct liste *);
void suppression_pos_tel(struct liste *,int);
void suppression_tel_donne(struct liste*);
void suppression_ville_donne(struct liste*);
void suppression_indicatif_donne(struct liste*);
void enregister(struct liste *);
void recuperer(struct liste *);
void modifier_address(struct liste*);
void modifier_num(struct liste*);
void tri(struct liste* );
void invertion(struct cellule* ,struct cellule* );
void modifier_num(struct liste* );
void modifierDonnerCelluleAdr(struct liste* l);
void recherche_numero(struct liste l);
void recherche_indicatif(struct liste );
void recherche_nom(struct liste );
void recherche_ville(struct liste );
void tri(struct liste* );
void invertion(struct cellule* ,struct cellule* );
void afficher_pers(persone );
void getminnoeud(struct liste ,struct cellule **,unsigned *);
