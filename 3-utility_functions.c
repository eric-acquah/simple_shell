#include "main.h"

/**
 *_calloc - allocate memory sapce for an array
 *@nmemb: number of array elements
 *@size: size of each array element
 *Return: pointer to array
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	unsigned int capacity;
	void *allo;
	unsigned char *init;

	if (nmemb == 0 || size == 0)/*check if arg values are zero*/
		return (NULL);

	capacity = nmemb * size;

	allo = malloc(capacity);/*allocate memory to the void pointer*/

	if (allo == NULL)/*check if malloc failed or not*/
		return (NULL);

	/*typecast void pointer to enable the initialization of memory*/
	init = (unsigned char *)allo;

	for (i = 0; i < capacity; i++)
		init[i] = 0;/*initialize memory blocks with zero*/

	return (allo); /*return void pointer*/
}
