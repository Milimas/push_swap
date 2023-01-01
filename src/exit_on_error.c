/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_on_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:12:08 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/13 16:58:44 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_on_error(int error_number, char *message)
{
	int	fd;

	fd = !!error_number + 1;
	(void)message;
	if (fd > 1)
		ft_putstr("Error\n", fd);
	exit(error_number);
}
