/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:57:22 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/15 08:57:37 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_push_swap **ps)
{
	t_stack	**a;
	t_stack	**b;

	a = &(*ps)->a;
	b = &(*ps)->b;
	if ((*a)->num < (*a)->next->num && (*a)->next->num < (*a)->next->next->num)
		return ;
	if (!((*a)->next->next->num < (*a)->num
			&& (*a)->num < (*a)->next->num)
		&& !((*a)->next->next->num > (*a)->next->num
			&& (*a)->next->num < (*a)->num
			&& (*a)->next->next->num < (*a)->num))
	{
		if (*b && (*b)->next && (*b)->num <= (*b)->next->num - 1)
			run(SS, a, b);
		else
			run(SA, a, NULL);
	}
	if ((*a)->num < (*a)->next->num && (*a)->next->num > (*a)->next->next->num)
		run(RRA, a, NULL);
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
		run(RA, a, NULL);
}
