#include "main.h"

/**
 *num_to_str - convert integer values to strings
 *@num: number to be converted and printed
 *Return: pointer to array of the converted strings
 */
char *num_to_str(int num)
{
	char *num_array;
	char *num_array1;
	int idx, lent, num_siz, mod, size = 5;
	char tmp;

	num_array = (char *)malloc(sizeof(char) * size);
	if (num_array == NULL)
		return (NULL);

	num_siz = 0;
	do {
		mod = num % 10;
		num_array[num_siz] = mod + '0';
		num = num / 10;
		num_siz++;
	} while (num != 0);

	num_array[num_siz] = '\0';
	if (size > num_siz)
		num_array1 = _realloc(num_array, size, sizeof(char) * (num_siz + 1));

	lent = num_siz - 1;
	for (idx = 0; idx < lent; idx++)/*reorder reversed string*/
	{
		tmp = num_array1[idx];
		num_array1[idx] = num_array1[lent];
		num_array1[lent] = tmp;
		lent--;
	}

	return (num_array1);
}
