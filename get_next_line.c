/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:54:05 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/14 21:53:54 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	int			check;
	int			i;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (NULL);
	i = 1;
	line = NULL;
	while (i)
	{
		check = 1;
		if (!buff[0])
			check = read(fd, buff, BUFFER_SIZE);
		if (check > 0)
			line = fill_line(buff, line);
		reffil_buffer(buff);
		if (!check || ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}
