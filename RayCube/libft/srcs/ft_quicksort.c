/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_quicksort.c            		                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:45:39 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:49:02 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Partitions needed for quicksort function */
static int	partition(int *array, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot_value)
		{
			ft_swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	ft_swap(&array[i], &array[high]);
	return (i);
}

/* Quicksort function */
void	ft_quicksort(int *array, int low, int high)
{
	int	pivot_index;

	if (low > high)
		return ;
	pivot_index = partition(array, low, high);
	ft_quicksort(array, low, pivot_index - 1);
	ft_quicksort(array, pivot_index + 1, high);
}