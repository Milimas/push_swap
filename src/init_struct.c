/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:14:49 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/13 17:02:59 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*replace_tabs(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (*s == '\t')
			*s = ' ';
		s++;
	}
	return (str);
}

void	init_struct(t_push_swap **ps, int argc, char **argv)
{
	*ps = malloc(sizeof(t_push_swap));
	if (!*ps)
		exit_on_error(1, "init_struct():: Malloc failed");
	if (argc < 2)
		exit_on_error(0, "");
	(*ps)->arg = &argv[1];
	(*ps)->size = argc - 1;
	(*ps)->bsplit = 0;
	if (argc == 2)
	{
		replace_tabs(argv[1]);
		(*ps)->arg = ft_split(argv[1], ' ');
		(*ps)->size = (int)ft_wordcount(argv[1], ' ');
		(*ps)->bsplit = 1;
	}
	(*ps)->a = NULL;
	(*ps)->b = NULL;
	fill_arr(ps);
	fill_stack(ps);
}
