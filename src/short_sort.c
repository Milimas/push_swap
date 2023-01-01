/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:15:44 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/15 01:40:55 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

void	push_in_place(t_stack **a, t_stack **b)
{
	if ((*b)->num == 0)
		run(PA, a, b);
	while (*b)
	{
		if (((*b)->num == (*a)->num - 1 || (*b)->num == get_last(*a)->num + 1)
			|| ((*b)->num == 4 && get_min(*a) == (*a)->num))
			run(PA, a, b);
		else if ((*b)->num - (*a)->num < 3
			&& get_last(*a)->num != (*b)->num + 1 && (*b)->num < 3)
			run(RA, a, b);
		else
			run(RRA, a, b);
	}
	while ((*a)->num != 0)
	{
		if ((*a)->num > 2)
			run(RA, a, NULL);
		else
			run(RRA, a, NULL);
	}
}

void	sort_5(t_push_swap **ps)
{
	t_stack	**a;
	t_stack	**b;

	a = &(*ps)->a;
	b = &(*ps)->b;
	if ((*a)->num == 4)
		run(RA, a, b);
	is_sorted(*a);
	run(PB, a, b);
	if ((*a)->num - 1 == (*a)->next->num && (*a)->num == 0)
		run(SA, a, b);
	else if (get_stacksize(*a) == 4)
		run(PB, a, b);
	sort_3(ps);
	push_in_place(a, b);
}

void	short_sort(t_push_swap **ps)
{
	t_stack	*a;
	t_stack	*b;

	set_value_from_index(ps, (*ps)->a);
	a = (*ps)->a;
	b = (*ps)->b;
	if ((*ps)->size == 3)
		sort_3(ps);
	else
		sort_5(ps);
}
