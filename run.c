/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:11:08 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/29 04:31:25 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run(char *action, t_stack **a, t_stack **b)
{
	if (iseq(action, SA) || iseq(action, SS))
		swap(a);
	if (iseq(action, SB) || iseq(action, SS))
		swap(b);
	if (iseq(action, PB))
		push(b, a);
	if (iseq(action, PA))
		push(a, b);
	if (iseq(action, RA) || iseq(action, RR))
		rotate(a);
	if (iseq(action, RB) || iseq(action, RR))
		rotate(b);
	if (iseq(action, RRA) || iseq(action, RRR))
		rev_rotate(a);
	if (iseq(action, RRB) || iseq(action, RRR))
		rev_rotate(b);
	printf("%s", action);
	// printf(" ====> a ");
	// print_stack(*a);
	// printf("\t b ");
	// print_stack(*b);
	printf("\n");
}

