/* passage 2015:
 * ============
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
 * On suppose que les routes sont stockées dans un tableau les_routes 
 * de dimension maximale 100 et dont la taille réelle est enregistrée
 * dans une variable n.
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

#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

/* (*) la structure RouteN ayant pour données */
typedef struct Route_National{
  char Nom[SIZE];
  
} RouteN;


int main()
{
  /* Question I: le  menu du depart (2 pts)*/
  puts("******* Gestion des routes nationales ********");
  puts("  Taper le numero de l'operation a realiser:");
  puts("  1 ----- Ajouter ");
  puts("  2 ----- Affichier  ");
  puts("  3 ----- Rechercher  ");
  puts("  4 ----- Supprimer ");
  puts("  5 ----- Sauvegarder dans un fichier ");
  puts("  6 ----- Quitter ");
  puts("**********************************************");

  /* Question II: Ajouter une nouvelle route dont les informations
   *              sont saisies au clavier au tableau  des routes. */

  /* Question III: Afficher les routes saisies */
  
  /* Question IV: Afficher les routes dont la ville de départ est saisie
   *		  au clavier */

  /* Question V: Supprimer du tableau  une route  dont le nom est donné
   *             par l’utilisateur */
  
  /*Question VI: Copier le contenu de tableau des routes dans un fichier
   *             texte dont le nom est saisi par l’utilisateur. 
   *             Chaque route est stockée dans une ligne, les champs 
   *             sont séparés par le caractère virgule 
   */
}

/* Anas Rchid <rchid.anas@gmail.com> */
/* Created: 04/25/2017 */
/* Updated: 04/25/2017 */
