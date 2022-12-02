/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:59:37 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/27 09:59:52 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}
