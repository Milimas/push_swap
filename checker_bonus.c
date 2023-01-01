/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:16:11 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/16 08:59:22 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap_bonus.h"

void	free_all(t_push_swap *ps)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;
	char	**arg;

	a = ps->a;
	b = ps->b;
	arg = ps->arg;
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
		if (ps->bsplit == 1)
			free(*(arg++));
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
	free(ps->arr);
	if (ps->bsplit == 1)
		free(ps->arg);
}

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
}

int	check_action(char *action)
{
	if (iseq(action, SA)
		||iseq(action, SB)
		|| iseq(action, SS)
		|| iseq(action, PA)
		|| iseq(action, PB)
		|| iseq(action, RA)
		|| iseq(action, RB)
		|| iseq(action, RR)
		||iseq(action, RRA)
		|| iseq(action, RRB)
		|| iseq(action, RRR))
		return (1);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
		{
			ft_putstr("KO\n", 1);
			return (0);
		}
		else
			stack = stack->next;
	}
	ft_putstr("OK\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	char		*action;

	init_struct(&ps, argc, argv);
	quick_sort((*ps).arr, 0, (*ps).size - 1);
	action = get_next_line(0);
	while (action)
	{
		if (action[2] == '\n')
			action[2] = 0;
		if (action[3] == '\n')
			action[3] = 0;
		if (!check_action(action))
			exit_on_error(1, "Invalid instuction");
		run(action, &ps->a, &ps->b);
		free(action);
		action = get_next_line(0);
	}
	if (!ps->b)
		is_sorted(ps->a);
	else
		ft_putstr("KO\n", 1);
	free_all(ps);
	free(ps);
	return (0);
}
