/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:53:01 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/13 16:59:12 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arr(t_push_swap **ps)
{
	size_t	i;

	i = 0;
	(*ps)->arr = malloc(sizeof(int) * (*ps)->size);
	if (!(*ps)->arr)
		exit_on_error(1, "");
	while (i < (size_t)(*ps)->size)
	{
		(*ps)->arr[i] = ft_atoi((*ps)->arg[i]);
		i++;
	}
}
