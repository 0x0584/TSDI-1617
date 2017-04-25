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

#ifndef LIB_H
#define LIB_H

#define SIZE 10				/* defining a SIZE macro as 10 */

/* Boolean logic */
#define TRUE 1
#define FALSE 0

/* --- prototypes --- */

/* our standard IO library */
#include <stdio.h>

/* our standard library */
#include <stdlib.h>			/* malloc */

/* allocate memory dynamically of a one-dimension array using malloc */
int *onedim_mem_alloc(unsigned int __size);

/* allocate memory dynamically of two-dimension array using malloc */
int **twodim_mem_alloc(unsigned int __rows, unsigned int __columns);

int *arrcpy(int *__output, const int *__input, size_t __size);

void swap(int *__element1, int *__element2);

int *bubblesort(const int *__src, size_t __size);
/* if you think C is weak just because it's old, or it's less powerful
 * then this is an array of 5 pointers to functions returning pointers
 * to arrays of 3 ints */ 
int (*(*foofunc[5])(void))[3];

#endif
