/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:18:35 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/14 21:54:50 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE];
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
		if (!buff[fd][0])
			check = read(fd, buff[fd], BUFFER_SIZE);
		if (check > 0)
			line = fill_line(buff[fd], line);
		reffil_buffer(buff[fd]);
		if (!check || ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}
