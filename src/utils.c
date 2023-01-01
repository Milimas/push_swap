/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:01:58 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/13 13:15:25 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	second = (*stack)->next;
	swap_num(&(*stack)->num, &(*stack)->next->num);
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	if ((*src)->next)
	{
		*src = (*src)->next;
		tmp->next = NULL;
	}
	else
		*src = NULL;
	add_front(dest, tmp);
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	add_back(stack, tmp);
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next)
		if (before_last->next->next)
			before_last = before_last->next;
	else
		break ;
	before_last->next->next = *stack;
	*stack = before_last->next;
	before_last->next = NULL;
}
