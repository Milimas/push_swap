/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:17:54 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/14 22:55:57 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->num == number)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	get_rot(t_stack *stack, int number)
{
	int	index;
	int	size;

	index = get_index(stack, number);
	size = get_stacksize(stack);
	if (index <= size / 2 && index >= 0)
		return (1);
	if (index > size / 2 && index >= 0)
		return (-1);
	return (0);
}

int	load_chunks(t_push_swap **ps)
{
	int	chunk;
	int	num;

	num = 0;
	chunk = 15;
	if ((*ps)->size >= 500)
		chunk = 30;
	while ((*ps)->a)
	{
		if ((*ps)->a->num - chunk < num)
		{
			num++;
			run(PB, &(*ps)->a, &(*ps)->b);
			if ((*ps)->b && (*ps)->b->num < num)
				run (RB, &(*ps)->a, &(*ps)->b);
		}
		else
			run(RA, &(*ps)->a, &(*ps)->b);
	}
	return (num);
}

void	big_sort(t_push_swap **ps)
{
	int	num;
	int	rot;

	set_value_from_index(ps, (*ps)->a);
	num = load_chunks(ps);
	while (num--)
	{
		rot = get_rot((*ps)->b, num);
		if (rot == 1)
			while ((*ps)->b->num != num)
				run(RB, &(*ps)->a, &(*ps)->b);
		if (rot == -1)
			while ((*ps)->b->num != num)
				run(RRB, &(*ps)->a, &(*ps)->b);
		run(PA, &(*ps)->a, &(*ps)->b);
	}
}
