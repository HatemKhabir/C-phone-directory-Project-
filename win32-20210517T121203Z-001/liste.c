#include <stdio.h>
#include "liste.h"
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <assert.h>
#include <myconio.h>
void creer_liste_vide(struct liste *l)
{
    l->premier=NULL;
    l->dernier=NULL;
}

unsigned verif_num(char* ch)
{unsigned i;
if (strlen(ch)!=8)
    return 0;
for (i=0;i<strlen(ch);i++)
    if (isdigit(ch[i])==0)
        return 0;
return 1;
}
unsigned verif_num2(char* ch)
{unsigned i;
if (strlen(ch)!=2)
    return 0;
for (i=0;i<strlen(ch);i++)
    if (isdigit(ch[i])==0)
        return 0;
return 1;
}
unsigned exist_num(char* p,struct liste *l)
{struct cellule* q=l->premier;
while(q)
{
    if (strcmp(p,q->info.numero_telephone)!=0)
       {textcolor(RED);
           printf("le numero que vous avez entrer existe deja dans le repertoire !! ");

           return 0;
    q=q->suivant;
}
  return 1;
}
}

unsigned verif_nom(char* ch)
{unsigned i;
for (i=0;i<strlen(ch);i++)
    if (isalpha(ch[i])==0)
        return 0;
return 1;
}

unsigned verif_date(char date[11])
{char j[3];
char m[3];
char a[5];
strncpy(j,date,2);
date+=3;
strncpy(m,date,2);
date+=3;
strcpy(a,date);
 if(atoi(a)>=1900 && atoi(a)<=2021)
{
        if(atoi(m)>=1 && atoi(m)<=12)
        {
            //check days
            if((atoi(j)>=1 && atoi(j)<=31) && (atoi(m)==1 || atoi(m)==3 || atoi(m)==5 || atoi(m)==7 || atoi(m)==8 || atoi(m)==10 || atoi(m)==12))
                return 1;
            else if((atoi(j)>=1 && atoi(j)<=30) && (atoi(m)==4 || atoi(m)==6 || atoi(m)==9 || atoi(m)==11))
                return 1;
            else if((atoi(j)>=1 && atoi(j)<=28) && (atoi(m)==2))
                return 1;
            else if(atoi(j)==29 && atoi(m)==2 && (atoi(a)%400==0 ||(atoi(a)%4==0 && atoi(a)%100!=0)))
                return 1;
            else
                return 0;
        }
        else
            return 0;
}
return 0;
}

unsigned verif_email(char email[40])
{int i,pos_at=0,pos_dot=0,ok=0;
for(i=0;i<strlen(email);i++)
if (email[i]=='@')
pos_at=i;
else if (email[i]=='.')
pos_dot=i;
if (pos_dot-pos_at>0)
    ok=1;
return ok;
}
int liste_vide(struct liste l)
{
    return (l.dernier==l.premier);

}
persone saisie_personne()
{
    persone p;
      do
        {textcolor(13);
        printf("Donner le num telephone  :");
        textcolor(0);
        scanf("%s",p.numero_telephone);
        }while (!verif_num(p.numero_telephone));
         do
        {textcolor(13);
            printf("Donner le nom :");
            textcolor(0);
        scanf("%s",p.nom);
        }while (!verif_nom(p.nom));
           do
        {textcolor(13);
            printf("Donner le prenom :");
            textcolor(0);
        scanf("%s",p.prenom);
        }while(!verif_nom(p.prenom));
         do
        {textcolor(13);
            printf("Donner la date de naissence jj/mm/aaaa :");
        textcolor(0);
        scanf("%s",p.date_naissence);
        }while (!verif_date(p.date_naissence));
        do
        {textcolor(13);
            printf ("donner l 'email :\n");
textcolor(0);
        scanf ("%s",p.email)    ;
        }while (!verif_email(p.email));
        textcolor(13);
        printf ("donner la rue :  ");
           textcolor(0);
           scanf ("%s",p.rue);
           do{
           textcolor(13);
           printf ("donner la ville  :  ");
           textcolor(0);
           scanf ("%s",p.ville);
           }while (!verif_nom(p.ville));
           do
           {
           textcolor(13);
           printf ("donner la code postale :  ");
           textcolor(0);
           scanf ("%d",&p.code_postale);
           }while (!(p.code_postale > 0 && p.code_postale<9999));
    return p;

}

void remplir_liste(struct liste *l)
{
    int rep;
    struct cellule *q ;
    do
    {
        q=(struct cellule*)malloc(sizeof(struct cellule));
        q->info=saisie_personne();
        q->suivant=NULL;
        if(l->dernier==NULL)
            l->premier=q;
        else
            l->dernier->suivant=q;
        l->dernier=q;


        do
        {textcolor(6);
            printf("Voulez vous ajouter une autre piste 1/0(0:Non,1:Oui):");
            scanf("%d",&rep);
        }while(!(rep==1 || rep==0));
    }while(rep);
textcolor(4);
printf("\n ----------------------------------Numero Ajoute avec Succees !!----------------------------------\n");

}


int taille_liste_rep(struct liste l)
{   struct cellule *e=l.premier;

    int taille_liste=0;
while (e)
{

taille_liste++;
   e=e->suivant;

}
return taille_liste;
}
void inserer_queue_tel(struct liste * l)
{
   struct cellule *q ;
    q=(struct cellule*)malloc(sizeof(struct cellule));
    q->info=saisie_personne();
    q->suivant=NULL;
    l->dernier->suivant=q;
    l->dernier=q;
}
void inserer_tete_tel(struct liste * l)
{
    struct cellule *q ;
    assert(!liste_vide(*l));
    q=(struct cellule*)malloc(sizeof(struct cellule));
    q->info=saisie_personne() ;
    q->suivant=l->premier;
    l->premier=q;
}
void insere_pos_tel(struct liste *l)
{
    int i=2;
    struct cellule *q;
    int pos;
    struct cellule *prec;
    struct cellule *p=l->premier;
    do
    {
        printf("donner position : ");
        scanf("%d",&pos);
    }while (pos>taille_liste_rep(*l));

    if (pos==1)
    inserer_tete_tel(l);
    else
        if (pos-1==taille_liste_rep(*l))
        inserer_queue_tel(l);
    else
    {

        while (i<=pos)
    {
        prec =p;
        p=p->suivant;
        i++;
    }
        q=(struct cellule*)malloc(sizeof(struct cellule));
        q->info=saisie_personne();
         q->suivant=prec->suivant;
         prec->suivant=q;
    }

}

void affichage(struct liste l)
{struct cellule *p;
unsigned i ;
p=l.premier;
textcolor(4);
cprintf("  NUMERO  |     NOM     |    PRENOM   |DATE DE NAISSANCE|    RUE       |      VILLE      | CODE(P) |     EMAIL\n" );
textcolor(0);
for(i=0;i<110;i++)
cprintf("\xC4");
cprintf("\n");
if(liste_vide(l))
   {printf("                                vide                        \n ");}
else{
while (p){
afficher_pers(p->info);
p=p->suivant;}
};
}
void afficher_pers(persone p)
{unsigned x,i;
//printf("|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s \n",p.numero,p.nom,p.prenom,p.datn,p.ville,p.code,p.email);
cprintf(" %s  ",p.numero_telephone);
cprintf("|%s",p.nom);
x=strlen(p.nom);if(x<13)
{
for(i=0;i<13-x;i++)
cprintf(" ");}
cprintf("|%s",p.prenom);
x=strlen(p.prenom);
if(x<13)
    {
for(i=0;i<13-x;i++)
cprintf(" ");}
cprintf("|%s",p.date_naissence);
for(i=0;i<7;i++)
cprintf(" ");
cprintf("|%s",p.rue);
x=strlen(p.rue);
if(x<13)
{
for(i=0;i<13-x;i=i+2)
cprintf("  ");
}
cprintf("|%s",p.ville);
x=strlen(p.ville);
if(x<13)
{
for(i=0;i<13-x;i=i+2)
cprintf("  ");
}

cprintf("|%d",p.code_postale);
for(i=0;i<5;i=i+2)
cprintf("  ");
cprintf("|%s",p.email);
x=strlen(p.email);
if(x<13){
for(i=0;i<13-x;i++)
cprintf(" ");}
cprintf("\n");
for(i=0;i<110;i++)
cprintf("\xC4");
cprintf("\n");
}

void supprimer_tete_tel(struct liste*l)
{
struct cellule*q=l->premier;
if (q==l->dernier)
    {l->dernier=NULL;
     l->premier=NULL;
    }
    else
    {l->premier=q->suivant;
    free(q);
    }

}
void supprimer_queue_tel(struct liste* l)
{struct cellule*q=l->premier;
if (q==l->dernier)
    supprimer_tete_tel(l);
else
{while (q->suivant!=l->dernier)
    q=q->suivant;
q->suivant=NULL;
free(l->dernier);
l->dernier=q;
}
}

void suppression_pos_tel(struct liste* l,int pos)
{

  int i=1;
  struct cellule *q=l->premier;
  struct cellule *prec=NULL;


     while (i<pos)
     {

         prec=q;
         q=q->suivant;
         i++;
     }
     if (prec==NULL)
        l->premier=q->suivant;
     else
     {
         prec->suivant=q->suivant;
         if (l->dernier=q)
            l->dernier=prec;
     }
     free(q);
}

void suppression_tel_donne(struct liste* l)
{struct cellule* q=l->premier;
int i=1,ok=0;
char num_tel[9];
do{
        textcolor(13);
printf("donner numero a supprimer : ");
textcolor(0);
scanf("%s",num_tel);
}while (!verif_num(num_tel));

    while (q)
    {
        if (strcmp(num_tel,q->info.numero_telephone)==0)
        {ok=1;
            if(q == l->premier)
                {
				supprimer_tete_tel(l);
			}
			else if(q == l->dernier)
                {
				supprimer_queue_tel(l);
			}
			else
			{
				suppression_pos_tel(l,i);
			}
			 textcolor(4);
                printf("\n ----------------------------------Numero Supprime Avec Succes---------------------------------- \n");
		}
		else
            {
			i++;
		}
		q = q->suivant;
    }
if (!ok)
    textcolor(RED);
    printf("le numero n'existe pas \n");
}
void recuperer (struct liste *l)
{struct cellule* q;
unsigned i=0;
char texte[255];
FILE * fic=fopen("sauvgarder.txt","r") ;
creer_liste_vide(l);
while (!feof(fic))
    {
q=(struct cellule*) malloc (sizeof(struct cellule));

fscanf(fic,"%s |%s | %s | %s  |  %s  |  %s   |   %d    |   %s  \n",q->info.numero_telephone,q->info.nom,q->info.prenom,q->info.date_naissence,q->info.rue,q->info.ville,&q->info.code_postale,q->info.email);
    if(i==0)
    {q->suivant =NULL;
l->premier=q;
l->dernier=q;
}else
    {
        q->suivant =NULL;

l->dernier->suivant=q;
l->dernier=q;
    }i++;
    }
    fclose ( fic ) ;

    }


void enregister(struct liste *l)
{struct cellule* q=l->premier;
    FILE * fic = fopen ( "sauvgarder.txt" , "w" ) ;
    while(q)
    {
fprintf(fic,"%s |%s | %s | %s  |  %s  |  %s   |   %d    |   %s  \n",q->info.numero_telephone,q->info.nom,q->info.prenom,q->info.date_naissence,q->info.rue,q->info.ville,q->info.code_postale,q->info.email);
   q=q->suivant;}fclose ( fic );
   }

void suppression_ville_donne(struct liste*l)
{struct cellule* q=l->premier;
int i=1,ok=0;
char ville[20];
do{
        textcolor(13);
printf("donner la ville a supprimer : ");
textcolor(0);
scanf("%s",ville);
}while (!verif_nom(ville));
    while (q)
    {
        if (strcmp(ville,q->info.ville)==0)
        {ok=1;
            if(q == l->premier)
                {
				supprimer_tete_tel(l);
			}
			else if(q == l->dernier)
                {
				supprimer_queue_tel(l);
			}
			else
			{
				suppression_pos_tel(l,i);
			}
			 textcolor(4);
                printf("\n ----------------------------------Numero Supprime Avec Succes---------------------------------- \n");
		}
		else
            {
			i++;
		}
		q = q->suivant;
    }
if (!ok)
    {textcolor(RED);
    printf("il n'y aucun contact qui habite dans cette ville  \n");
}
}

void suppression_indicatif_donne(struct liste*l)
{struct cellule* q=l->premier;
int i=1,ok=0;
char indicatif[3];
char extraire[3]="";
do{
        textcolor(13);
printf("donner l'indicatif a supprimer (9*/2*/5*/7*/3*/4*/ : ");
textcolor(0);
scanf("%s",indicatif);
}while (!verif_num2(indicatif));
    while (q)
    {strncpy(extraire,q->info.numero_telephone,2);
        if (strcmp(indicatif,extraire)==0)
        {ok=1;
            if(q == l->premier)
                {
				supprimer_tete_tel(l);
			}
			else if(q == l->dernier)
                {
				supprimer_queue_tel(l);
			}
			else
			{
				suppression_pos_tel(l,i);
			}
			 textcolor(4);
            printf("\n ----------------------------------Numero Supprime Avec Succes---------------------------------- \n");
		}
		else
            {
			i++;
		}
		q = q->suivant;
    }
if (!ok)
    {textcolor(RED);
    printf("Il n'y a aucun contact avec cet indicatif \n");
}
}
//--------------------------------------------Modification-------------------------------------------

void modifier_num(struct liste* l)
{char num[9];
struct cellule* q= l->premier;
int ok=0;
do
{textcolor(13);
    printf("donner le numero a modifier : ");
textcolor(0);
scanf("%s",num);
}while (!verif_num(num));
while (q)
{if (strcmp(num,q->info.numero_telephone)==0)
    {ok=1;
        do
    {textcolor(13);
    printf("donner le noveau numero : ");
    textcolor(0);
    scanf("%s",q->info.numero_telephone);
    }while (!verif_num(num));

    }
q=q->suivant;
}
  if (ok)
  {textcolor(4);
printf("\n ----------------------------------Numero Modifie Avec Succes---------------------------------- \n");
  }else printf("\n ----------------------------------Numero n'existe pas---------------------------------- \n");

}

/*modification adresse */

void modifier_address(struct liste* l)
{
struct cellule* q= l->premier;
 char rue[30];
char ville [20];
char num[9];
int ok=0;
do
{textcolor(13);
    printf("donner le numero de contact pour modifier son adresse : ");
textcolor(0);
scanf("%s",num);
}while (!verif_num(num));
while (q)
{if (strcmp(num,q->info.numero_telephone)==0)
    {ok=1;
        textcolor(13);
    printf("donner la nouvelle rue : ");
    textcolor(0);
    scanf("%s",q->info.rue);
    do
    {textcolor(13);
    printf("donner la nouvelle adresse : ");
    textcolor(0);
    scanf("%s",q->info.ville);
    }while (!verif_nom(q->info.ville));
 do
    {textcolor(13);
    printf("donner le nouveau code postal  : ");
    textcolor(0);
    scanf("%d",&q->info.code_postale);
    }while(!(q->info.code_postale > 0 && q->info.code_postale<9999));

    }
q=q->suivant;
}
  if (ok)
  {textcolor(4);
printf("\n ----------------------------------Numero Modifie Avec Succes---------------------------------- \n");
  }else printf("\n ----------------------------------Numero n'existe pas---------------------------------- \n");

}



//---------------------------------------------RECHEEERCCHEEE--------------------------------------------
void recherche_numero(struct liste l)
{struct cellule*q=l.premier;
char num[9];
int ok=0;
do
{textcolor(13);
    printf("donner le numero de contact a rechercher : ");
textcolor(0);
scanf("%s",num);
}while (!verif_num(num));
while (q)
{if (strcmp(num,q->info.numero_telephone)==0)
       {printf("%s\t%s\t %s\t %s\t%s\t    %d\t    %s\t    %s\t\n",q->info.numero_telephone,q->info.nom,q->info.prenom,q->info.rue,q->info.ville,q->info.code_postale,q->info.date_naissence,q->info.email);
       ok=1;
       }
q=q->suivant;
}
    if (!ok)
    {textcolor(RED);
    printf("Il n'y a aucun contact avec ce numero \n");

    }

}
void recherche_indicatif(struct liste l)
{struct cellule* q=l.premier;
int i=1,ok=0;
char indicatif[3];
char extraire[3]="";
do{
        textcolor(13);
printf("donner l'indicatif a rechercher (9*/2*/5*/7*/3*/4*/ : ");
textcolor(0);
scanf("%s",indicatif);
}while (!verif_num2(indicatif));
    while (q)
    {strncpy(extraire,q->info.numero_telephone,2);
        if (strcmp(indicatif,extraire)==0)
        {ok=1;
        printf("%s\t%s\t %s\t %s\t%s\t    %d\t    %s\t    %s\t\n",q->info.numero_telephone,q->info.nom,q->info.prenom,q->info.rue,q->info.ville,q->info.code_postale,q->info.date_naissence,q->info.email);
       }
q=q->suivant;
}
    if (!ok)
    {textcolor(RED);
    printf("Il n'y a aucun contact avec ce numero \n");

    }

}
void recherche_nom(struct liste l)
{struct cellule*q=l.premier;
char nom[20];
int ok=0;
do
{textcolor(13);
    printf("donner le nom de contact a rechercher : ");
textcolor(0);
scanf("%s",nom);
}while (!verif_nom(nom));
while (q)
{if (strcmp(nom,q->info.nom)==0)
       {printf("%s\t%s\t %s\t %s\t%s\t    %d\t    %s\t    %s\t\n",q->info.numero_telephone,q->info.nom,q->info.prenom,q->info.rue,q->info.ville,q->info.code_postale,q->info.date_naissence,q->info.email);
       ok=1;
       }
q=q->suivant;
}
    if (!ok)
    {textcolor(RED);
    printf("Il n'y a aucun contact qui s'appelle %s  \n",nom);

    }

}
void recherche_ville(struct liste l)
{struct cellule*q=l.premier;
char ville[9];
int ok=0;
do
{textcolor(13);
    printf("donner la ville de contact a rechercher : ");
textcolor(0);
scanf("%s",ville);
}while (!verif_nom(ville));
while (q)
{if (strcmp(ville,q->info.ville)==0)
       {printf("%s\t%s\t %s\t %s\t%s\t    %d\t    %s\t    %s\t\n",q->info.numero_telephone,q->info.nom,q->info.prenom,q->info.rue,q->info.ville,q->info.code_postale,q->info.date_naissence,q->info.email);
       ok=1;
       }
q=q->suivant;
}
    if (!ok)
    {textcolor(RED);
    printf("Il n'y a aucun contact dans cette ville \n");

    }

}
void getmincellule(struct liste l,struct cellule **p,unsigned *pos)
  {
      struct cellule *q=l.premier;
     char x[9]="";
      unsigned i;
      i=1;
  strcpy(x,q->info.numero_telephone);
      *pos=1;
      *p=q;

      while (q)
      {
          if(strcmp(x,q->info.numero_telephone)>0)
          {
              *p=q;
              *pos=i;
          }
          i++;
          q=q->suivant;
      }

  }
  void tricroi (struct liste *l)
{unsigned x;
    struct liste l2;
    struct cellule *p;
    struct cellule * q;
persone info;
unsigned i,y ;
unsigned pos=0;
y=taille_liste_rep(*l);
    for(i=1;i<=y;i++)
    {

        getmincellule(*l,&p,&pos);
        if(i==1)
        {
info=p->info;

q=(struct cellule*) malloc (sizeof(struct cellule));
strcpy(q->info.numero_telephone,info.numero_telephone);
strcpy(q->info.nom,info.nom);
strcpy(q->info.date_naissence,info.date_naissence);
strcpy(q->info.prenom,info.prenom);
q->info.code_postale=info.code_postale;
strcpy(q->info.ville,info.ville);
strcpy(q->info.email,info.email);
q->suivant=NULL;
l2.dernier=q;
 l2.premier=q;
        }else {

info=p->info;
q=(struct cellule*) malloc (sizeof(struct cellule));
strcpy(q->info.numero_telephone,info.numero_telephone);
strcpy(q->info.nom,info.nom);
strcpy(q->info.date_naissence,info.date_naissence);
strcpy(q->info.prenom,info.prenom);
q->info.code_postale=info.code_postale;
strcpy(q->info.ville,info.ville);
strcpy(q->info.email,info.email);
q->suivant=NULL;
l2.dernier->suivant =q;
l2.dernier =q;
    }
 suppression_pos_tel(l,pos);
    };

    affichage(l2);
//enregister(&l2);

}
void tri (struct liste *l)
{unsigned x;
    struct liste l2;
    struct cellule *p;
    struct cellule * q;
persone info;
unsigned i,y ;
unsigned pos=0;
y=taille_liste_rep(*l);
    for(i=1;i<=y;i++)
    {

        getmincellule(*l,&p,&pos);
        if(i==1)
        {
info=p->info;

q=(struct cellule*) malloc (sizeof(struct cellule));
strcpy(q->info.numero_telephone,info.numero_telephone);
strcpy(q->info.nom,info.nom);
strcpy(q->info.date_naissence,info.date_naissence);
strcpy(q->info.prenom,info.prenom);
q->info.code_postale=info.code_postale;
strcpy(q->info.ville,info.ville);
strcpy(q->info.email,info.email);
q->suivant=NULL;
l2.dernier=q;
 l2.premier=q;

        }else {

info=p->info;

q=(struct cellule*) malloc (sizeof(struct cellule));
strcpy(q->info.numero_telephone,info.numero_telephone);
strcpy(q->info.nom,info.nom);
strcpy(q->info.date_naissence,info.date_naissence);
strcpy(q->info.prenom,info.prenom);
q->info.code_postale=info.code_postale;
strcpy(q->info.ville,info.ville);
strcpy(q->info.email,info.email);
q->suivant=NULL;
l2.dernier->suivant =q;
l2.dernier =q;
    }
 suppression_pos_tel(l,pos);
    };

    affichage(l2);
//enregister(&l2);

}
