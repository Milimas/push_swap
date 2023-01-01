/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:49:35 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/13 17:11:18 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = *(arr + high);
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (*(arr + j) < pivot)
			swap_num(arr + ++i, arr + j);
		else
			if (*(arr + j) == pivot)
				exit_on_error(1, "Invalid input, Duplicate number");
		j++;
	}
	swap_num(arr + i + 1, arr + high);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}
