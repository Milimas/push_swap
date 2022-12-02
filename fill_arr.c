/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:53:01 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/27 12:39:46 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arr(t_arr **arr, int argc, char **argv)
{
	size_t i;

	i = 0;
	if (!*arr)
		*arr = malloc(sizeof(t_arr));
	if (!argc || !*arr)
	{
		printf("argc arr");
		return ;
	}
	(*arr)->size = argc - 1;
	(*arr)->a = malloc(sizeof(int) * (*arr)->size);
	if (!(*arr)->a)
		return ;
	while (i < (*arr)->size)
	{
		(*arr)->a[i] = atoi(argv[i + 1]);
		i++;
	}
	(*arr)->head = (*arr)->a;
}
