/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 02:52:51 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/10/26 01:33:37 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*protect_on_error(char *buff, int fd)
{
	if (fd < 0)
		return (0);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lremind[OPEN_MAX];
	char		*buff;
	char		*tmp;

	while (!gl_strchr(lremind[fd], '\n'))
	{
		buff = get_buff(fd);
		if (!buff)
		{
			line = lremind[fd];
			lremind[fd] = NULL;
			return (protect_on_error(line, fd));
		}
		lremind[fd] = gl_strjoin(lremind[fd], buff);
		free(buff);
	}
	line = gl_substr(lremind[fd],
			0, gl_strchr(lremind[fd], '\n') - lremind[fd] + 1);
	tmp = lremind[fd];
	lremind[fd] = gl_substr(gl_strchr(lremind[fd], '\n') + 1,
			0, gl_strchr(lremind[fd], 0) - lremind[fd]);
	free(tmp);
	return (line);
}
