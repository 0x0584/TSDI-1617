/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Should you need to contact me, the author, you can do so by
 * e-mail - mail your message to <rchid.anas@gmail.com>.
 */

/* our little library; which would grow by time */
#include "lab.h"

int
main(int argc, char **argv)
{
  /* --- typical declaration of a fixed size array --- */

  /* an array is a collection of variables which 
   * we could access using an index which indicates
   * the place of element, teh first element is 0 
   */
  
  /* note: to declare all these variables at once

     int d1[SIZE], d2[SIZE][SIZE],
     d3[] = {1, 2, 3, 5, 8, 13}, d4[SIZE + 10] = { -1 },
     d5[7] = {},
     d6[][3] = {
     {0, 1},
     {4, 2, 4},
     {4}
     }, *food1,**food2; */

  int d1[SIZE], d2[SIZE][SIZE];	  /* standard way to declare an array */

  int d3[] = {1, 2, 3, 5, 8, 13}; /* this is also a valid array declaration.
				   * the size will be parsed by the compiler
				   * basic of the number of the passed
				   * elements at compilation time, then 
				   * the compiler initialize the array with
				   * the passed elements
				   */

  int d4[SIZE + 10] = { -1 };	  /* declare an array whit a fixed size &&
				   * initialize all its variables with
				   * the same value it may also be an
				   * expression that gives an integer 
				   * (e.g. MAX_VALUE + 11)
				   */

  int d5[7] = {},		  /* wait, really? */
    d6[][3] = {
    {0, 1},
    {4, 2, 4},
    {4}
  };

  /* declaration of a dynamic array using a variable  */

  int some_int = 15;

  int d7[some_int];		/* but the limitation is that we could not 
				 * initialize it now like fixed size arrays
				 * also, in addition, we have to check 
				 * whether the passed variable is positive
				 * or negative */

  some_int = -11;

  /* this enough, isn't it? */
  int d8[abs(some_int)];
  
  /* note:
   *
   * the name of the array is actually a pointer 
   * which points on its first element */
  
  int *food1,			   /* `food1` is a pointer on an int-type variable
				    * which would be our dynamite array later on */
    **food2;			   /* `food2` is a pointer on pointer on an
				    * int-type variable which would be our second
				    * dynamic array too */


  /* --- allocation of the dynamique arrays --- */

  /* allocating memory using malloc (stands for memory allocation) */

  food1 = onedim_mem_alloc(SIZE);

  food2 = twodim_mem_alloc(SIZE, SIZE);

  /* the price of dynamique allocation */
  //free(food1);
  free(food2);

  food1 = bubblesort(d3, 6);
  
  return 0;
}
