#include <stdio.h>		/* printf(), scanf(), putchar() */

int main()
{
  /***********************/
  /*** PART I: Tableux ***/
  /***********************/
  puts("PART I: Tableux\n-----\n");
  /* Macro pour definir la taille du tableau */
#define SIZE 8

  /* declare un tableux-int (taille SIZE) */
  int tab[SIZE];

  for(int i = 0; i < SIZE; ++i /* ou i++ */ )
    /* remplire le tableau avec des valeurs */
    tab[i] = i;

  puts("Les elements du tab");
  for(int i = 0; i < SIZE; i++)
    printf("%d ", tab[i]);
  puts("\n");

  /**************************/
  /*** PART II: Pointeurs ***/
  /**************************/
  puts("PART II: Pointeurs\n------\n");
  /* variable de type `int` */
  int i = 15;
  /* pointeur sur un `int` qui pointe sur NULL (no address) */
  int *p_int = NULL;
  /* assigne l'address du `i` au `p_int` */
  p_int = &i;
  /*      ^> Symbole de reference: return l'address du variable) */
  int j = *(p_int);
  /*      ^> Symbole de de-reference: return l'valeur qui existe 
   *	    dans l'address sur la quelle le pointeur pointe 
   *
   *	p_int: address X  i: address A
   *	v                 v
   *	+-----------+-----+-------------+
   *	| address A | ... | Valueur: 15 |
   *	+-----------+-----+-------------+
   *			  ^
   *			  *(p_int) 
   */
  printf("valeur i: \t%d | valeur *(p_int):\t%d\n\n", i, j);

  /***************************************/
  /*** PART III: Tableaux && Pointeurs ***/
  /***************************************/
  puts("PART III: Tableaux && Pointeurs\n-----\n");
  /* pointer sur un `int` qui pointe sur NULL (no address) */
  int *p_tab = NULL;
  /* un tableau est aussi un pointeur qui pointe sur le premier element 
   * dans le tableau (&tab[0] - l'address/reference du premier element
   * dans le tableau)
   * 
   *	tab: address H		    H+2		  H+3
   *	v                           v		  v
   *  --+-------------+-------------+-------------+-----+------------+
   *	|  valeur:50  |  valeur:12  |  valeur:50  | ... | valeur: -1 |
   *  --+-------------+-------------+-------------+-----+-------------
   *	^             ^		    ^		        ^
   *	0: add H+0    1: H+1	    2: H+2          ... (SIZE-1): H+(SIZE-1)
   */  
  p_tab = tab;
  /*
   * donc on peux stocke l'address du tableau dans un pointeur 
   * de meme type (int dans ce example) 
   *	tab: address H				        p_tab: address X
   *	v					        v
   *  --+-------------+----------+------------+---------+------------+--
   *	|  valeur:50  |   ...    | valeur: -1 |   ...   | address: H |
   *  --+-------------+----------+------------+---------+------------+--
   *	^             ^	         ^		      
   *	tab[0]:H+0  tab[1]: H+1  tab[(SIZE-1)]: H+(SIZE-1)  
   *
   */
  for(int i = 0; i < SIZE; ++i)
    printf("tab[%d]: \t%d \t|\t *(p_tab + %d):\t%d\n", i, tab[i], i, *(p_tab + i));
  putchar('\n');
  
  /* un tableau de meme taille que`tab[]` */
  int tab2[SIZE];

  puts("\nbefore changing the values\n-----------");
  for(int i = 0; i < SIZE; ++i) {
    tab2[i] = tab[i];
    printf("tab: \t%d \t|\t tab2: \t%d\n", tab[i], tab2[i]);
  }

  /* modifier tab apartir du pointeur p_tab */
  for(int i = 0; i < SIZE; ++i)
    *(p_tab + i) = tab2[i]*i;
  
  puts("\nafter changing the values\n-----------");  
  for(int i = 0; i < SIZE; ++i) {
    printf("tab: \t%d \t|\t tab2: \t%d\n", tab[i], tab2[i]);
  }
  
  return 0;
}
/* Anas Rchid <rchid.anas@gmail.com> */
