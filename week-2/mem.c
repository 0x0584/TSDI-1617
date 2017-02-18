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

#include "lab.h"

int *
onedim_mem_alloc(unsigned int sz)
{
  /* this funtion allocate memory as much as we need for 1dim.
   * so the total space is: sz. */

  int *array;		    /* declare a pointer on int (or our array) */

  /* allocate memory for the pointer
   * we have to cast because malloc retrun a (void *) */
  array = (int *) malloc(sz * sizeof(int));

  /* or, int this case, we can use this simple line:

     (int *) malloc(sz * sizeof(int)) */

  return array;		    /* return the pointer (array) */
}

int **
twodim_mem_alloc(unsigned int rows, unsigned int cols)
{
  /* this funtion allocate memory as much as we need for 2dim.
   * so the total space is: (the # of columns) * (the # of rows). */

  int **array;			/* our 2dim array */
  unsigned int i;


  /* first, how much we need to allocate memory for the rows.
   * in other words, allocate an array of rows (array of pointers to int)
   * so the total needed space is:
   * (# rows) x (sizeof pointer on at int)
   *
   * why casting as a (int **)??
   * simple, we allocate memory as much as rows we needm each row
   * is a pointer to an int, which means each row point to an array
   * so the whole set gives us a two dim array
   *
   * 
   * how things look like in memory
   *  array (the pointer)
   *    |
   *    v
   *    +------------+------------+------------+-------+------------+
   *    |    row 0   |   row 1 	  |   row 2    |  ...  |   row n    |
   *    +------------+------------+------------+-------+------------+
   *       array[0]     array[1]     array[2]             array[n]
   */
  array = (int **) malloc(rows * sizeof(int *));

  /* then, allocate memory to the colums, each column is an int
   * so we'll need to allocate an array of columns, 
   * total size: (# columns) x (sizeof int)
   * 
   *
   * note: we cast using (int *)
   *
   * how things look like in memory
   *
   *            [0]            [1]          [2]        ...       [n]
   *     +--------------+
   *     |+------------+| +------------+------------+-------+------------+
   *     ||    row 0   || |   row 1    |   row 2    |  ...  |   row n    |
   *     |+------+-----+| +-----+------+-----+------+-------+-----+------+
   *	 |       |      |       |	     |			  |
   *     |+------v-----+| +-----v------+-----v------+-------+-----v------+
   * [0] ||   col 0    || |   col 0    |    col 0   |  ...  |   col 0    |
   *     |+------------+| +------------+------------+-------+------------+
   * [1] ||   col 1    || |   col 1    |    col 1   |  ...  |   col 1    |
   *     |+------------+| +------------+------------+-------+------------+
   * [2] ||   col 2    || |   col 2    |    col 2   |  ...  |   col 2    |
   *     |+------------+| +------------+------------+-------+------------+
   * ... ||    ...     || |    ...     |    ...     |  ...  |    ...     |
   *     |+------------+| +------------+------------+-------+------------+
   * [m] ||   col m    || |   col m    |    col m   |  ...  |   col m    |
   *     |+------------+| +------------+------------+-------+------------+
   *  	 +--------------+
   *
   */
  for(i = 0; i < rows; ++i)
    *array = (int *) malloc(cols * sizeof(int));

  /* note: this also could be done int one line usnig:

    (int **) malloc(rows*sizeof(int *) + rows*colums*sizeof(int))) */

  return array;
}

void
swap(int *e1, int *e2)
{
  int foo = *e1;

  *e1 = *e2;
  *e2 = foo;
}

int *
arrcpy(int *out, const int *in, size_t sz)
{
  size_t i;

  if(out == NULL) out = onedim_mem_alloc(sz);
  
  for(i = 0; i < sz; ++i, ++out, ++in)
    *out = *in;

  return out;
}
