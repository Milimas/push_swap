/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_from_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:19:46 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/15 09:19:49 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arr_index(t_push_swap *ps, int number)
{
	int	size;

	size = ps->size;
	while (size >= 0)
	{
		if (ps->arr[size-- - 1] == number)
			return (size);
	}
	return (-1);
}

void	set_value_from_index(t_push_swap **ps, t_stack *stack_a)
{
	int	i;
	int	*ar;

	i = 0;
	ar = (*ps)->arr;
	while (stack_a)
	{
		stack_a->num = get_arr_index(*ps, stack_a->num);
		stack_a = stack_a->next;
	}
	while (i < (*ps)->size)
	{
		*ar++ = i++;
	}
}
