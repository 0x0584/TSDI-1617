#include <stdio.h>
#define SIZE 30
#define CLASS_SIZE 2

/* Declaration d'une structure */
struct Person {
  /* les champs */
  char name[SIZE];
  int age;
  int tall;			/* taille en cm */
};

/* definir le type `person_t` */
typedef struct Person person_t;

/* variable de type `person_t` */
/*             v--------v */
void afficher(person_t p);

/* pointeur sur un variable de type `person_t` */
/*            v---------v */
void remplir(person_t *p);

int main()
{
  /* declarer (1) et initialiser un variable de tpe `person_t` */
  person_t p1 = { "foo", 22, 178 };
  afficher(p1);
  
  /* declaration (2) */
  struct Person p2;
  remplir(&p2);			/* <--- reference de p2 */
  afficher(p2);

  /* tableau des persons de taille CLASS_SIZE */
  person_t tsdi[CLASS_SIZE];

  for(int i = 0; i < CLASS_SIZE; ++i) {
    printf("entre les info du person %d\n", i + 1);
    remplir(&tsdi[i]);		/* <--- reference de chaque element de `tsdi` */
  }

  for(int i = 0; i < CLASS_SIZE; ++i) {
    printf("info du person %d\n", i + 1);
    afficher(tsdi[i]);
  }

  return 0;
}

void afficher(person_t p)
{
  printf("name:\t%s\nage:\t%d\ntall:\t%d\n", p.name, p.age, p.tall);
}

void remplir(person_t *p)
{
  puts("entrer le nom");
  /* le variable `name` est un tableau de taille SIZE des chars.
   * donc name est aussi un pointeur! pour cette raison on pass
   * just le nom du tableau comme parametre de scanf() */
  scanf("%s", p->name);
  /*          ^^^^^^^ */
  /* p->name == *(p.name) I */
  
  puts("entre l'age");
  scanf("%d", &(p->age));
  /*          ^^^^^^^^ */
  /* address du champ `age` II */

  puts("entre la taille");
  scanf("%d", &(p->tall));
}

/* Anas Rchid <rchid.anas@gmail.com> */
