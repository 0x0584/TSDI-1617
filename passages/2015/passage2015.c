/* Created: 04/25/2017 
 * Updated: 04/25/2017 
 ***********************************************************************
 * PASSAGE 2015:
 * ============
 ***********************************************************************
 *
 * On souhaite écrire un programme permettant de gérer l’ensemble
 * des routes nationales au Maroc. Pour cela nous allons considérer
 * la structure (*) RouteN ayant pour données:
 *
 *	+ [Nom] qui correspond au nom de la route
 *	+ [Distance] qui correspond à la longueur (en km)
 *	  de la route associée à la structure,
 *      + [VilleD]  qui correspond à la ville de départ,
 *      + [VilleA]  qui correspond à la ville d’arrivée
 *
 * On suppose que les routes sont stockées dans [un tableau les_routes] 
 * de [dimension maximale 100] et dont la [taille réelle est enregistrée
 * dans une variable n].
 *  
 * Ecrire un programme complet: 
 *
 * 1. Ce programme doit afficher au départ le  menu suivant:
 *    ******* Gestion des routes nationales ********
 *      Taper le numero de l'operation a realiser:
 *      1 ----- Ajouter
 *      2 ----- Affichier
 *      3 ----- Rechercher  
 *      4 ----- Supprimer 
 *      5 ----- Sauvegarder dans un fichier 
 *      6 ----- Quitter 
 *    **********************************************
 *    
 * 2. Ajouter une nouvelle route dont les informations sont 
 *    saisies au clavier au tableau  des routes.
 *
 * 3. Afficher les routes saisies
 *
 * 4. Afficher les routes dont la ville de départ est saisie
 *    au clavier
 *
 * 5. Supprimer du tableau  une route  dont le nom est donné
 *    par l’utilisateur
 * 
 * 6. Copier le contenu de tableau des routes dans un fichier
 *    texte dont le nom est saisi par l’utilisateur. 
 *    Chaque route est stockée dans une ligne, les champs 
 *    sont séparés par le caractère virgule 
 */

#include <stdio.h>		/* printf(), scanf(), puts(), getc() */
#include <stdlib.h>		
#include <string.h>		/* strcmp() */

#define SIZE 30
#define ROUTES_SIZE 100
#define TRUE 1
/* (*) la structure RouteN ayant pour données */
struct Route_National{
  char Nom[SIZE];		/* nom de la route */
  int Distance;  		/* Ville A ----- distance ----> Vill B */
  char VilleD[SIZE];		/* Ville depart */
  char VilleA[SIZE];		/* Ville arriver */
};		

/* definir le type RouteN */
typedef struct Route_National RouteN;

/* prototypes */
void ajouter();
void afficher();
void rechercher();
void supprimer();
void sauvgarder();

/* variables global */
RouteN les_routes[ROUTES_SIZE]; /* les routes */
int n = 0;			  /* nombre des routes dans le tableau */

int main()
{
  char c;
  
  while(TRUE){
    /* Question I: le  menu du depart (2 pts)*/
    puts("******* Gestion des routes nationales ********");
    puts("  Taper le numero de l'operation a realiser:");
    puts("  0 ----- Ajouter ");
    puts("  1 ----- Affichier les routes ");
    puts("  2 ----- Rechercher  ");
    puts("  3 ----- Supprimer ");
    puts("  4 ----- Sauvegarder dans un fichier ");
    puts("  5 ----- Quitter ");
    puts("**********************************************");
    printf("\n>  ");
    
    c = getchar();
    
    switch(c) {
    default: break;		/* si l'input du utilisateur 
				 * est un choix non valid */

      /* Question II: Ajouter une nouvelle route dont les informations
       *              sont saisies au clavier au tableau  des routes. */
    case '0': ajouter();		break;
      
      /* Question III: Afficher les routes saisies */
    case '1': afficher();		break;

      /* Question IV: Afficher les routes dont la ville de départ est saisie
       *		  au clavier */
    case '2': rechercher();		break;

      /* Question V: Supprimer du tableau  une route  dont le nom est donné
       *             par l’utilisateur */
  
    case '3': supprimer();		break;

      /*Question VI: Copier le contenu de tableau des routes dans un fichier
       *             texte dont le nom est saisi par l’utilisateur. 
       *             Chaque route est stockée dans une ligne, les champs 
       *             sont séparés par le caractère virgule 
       */
    case '4': sauvgarder();		break;
    case '5': return 0;		/* terminer le program */
    };
  }
}

void ajouter()
{
  printf("entre le nom\n>  ");
  scanf("%s",les_routes[n].Nom);

  printf("entre la distance\n>  ");
  int d;
  scanf("%d",&d);
  les_routes[n].Distance = d;

  printf("entre la ville de depart\n>  ");
  scanf("%s",les_routes[n].VilleD);

  printf("entre la ville d'arriver\n>  ");
  scanf("%s",les_routes[n].VilleA);

  ++n;				/* increment! */
}

void afficher()
{
  getchar();
  /* pour i = 0; i < nombre des routes 
   *(ATTENTION: nombre_des_routes != ROUTE_SIZE)*/
  for(int i = 0; i < n; ++i)
    printf("NOM:%s DISTANCE:%d DEPART:%s ARRIVER:%s\n----------------------\n",
	   les_routes[i].Nom,
	   les_routes[i].Distance,
	   les_routes[i].VilleD,
	   les_routes[i].VilleA);
  puts("");
}

void rechercher()
{
  char str[SIZE];
  puts("ville depart");
  scanf("%s", str);
  printf("###%s", str); 
  for(int i = 0; i < n; ++i)
    if(strcmp(str, les_routes[i].VilleD) == 0)
      {printf("%s %d %s %s\n",
	     les_routes[i].Nom,
	     les_routes[i].Distance,
	     les_routes[i].VilleD,
	     les_routes[i].VilleA);
	getchar();}
}
void supprimer()
{
  afficher();

  char str[SIZE];
  puts("selectionner une ville");
  scanf("%s", str);
  
  for(int i = 0; i < n; ++i)
    if(strcmp(str, les_routes[i].Nom) == 0)
      for(int j = i; j < n; j++){
	les_routes[j] = les_routes[j+1];
      }

  --n;				/* decrement */
}

void sauvgarder()
{
  FILE *fp = fopen("export.txt", "w+");

  for(int i = 0; i < n; i++)
    fprintf(fp, "NOM:%s DISTANCE:%d VILLEDEPART:%s VILLEARRIVER: %s",
	    les_routes[i].Nom,
	    les_routes[i].Distance,
	    les_routes[i].VilleD,
	    les_routes[i].VilleA);

  close(fp);
  
}
/* Anas Rchid <rchid.anas@gmail.com> */
