/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:13:53 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/16 04:12:47 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	free_all(t_push_swap *ps)
{
	t_stack	*a;
	t_stack	*tmp;
	char	**arg;

	a = ps->a;
	arg = ps->arg;
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
		if (ps->bsplit == 1)
			free(*(arg++));
	}
	free(ps->arr);
	if (ps->bsplit == 1)
		free(ps->arg);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	init_struct(&ps, argc, argv);
	quick_sort((*ps).arr, 0, (*ps).size - 1);
	is_sorted((*ps).a);
	if (ps->size == 2 && ps->a->num > ps->a->next->num)
		run(SA, &ps->a, &ps->b);
	else if ((*ps).size <= 5)
		short_sort(&ps);
	else
		big_sort(&ps);
	free_all(ps);
	free(ps);
	return (0);
}
