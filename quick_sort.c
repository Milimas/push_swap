/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:49:35 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/27 09:50:27 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int low, int high)
{
  
  int pivot = *(arr + high);
  int i = (low - 1);
  int j = low;

  while(j < high)
  {
	if (*(arr + j) < pivot)
		swap_num(arr + ++i, arr + j);
	else
	if (*(arr + j) == pivot)
		ft_error(arr);
  	j++;
  }
  swap_num(arr + i + 1, arr + high);
  return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}
