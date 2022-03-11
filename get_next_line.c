/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:54:05 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/11 21:12:55 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include<fcntl.h>

char		*fill_line(char *buff, char *line);
void		reffil_buffer(char *buff, size_t len);
size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strnjoin(char const *s1, char const *s2, size_t size);

//return the line
char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	int			check;

	printf("This is the Buff size: %d \n", BUFFER_SIZE);
	line = NULL;
	while (1)
	{
		check = 1;
		if (!buff[0])
			check = read(fd, buff, BUFFER_SIZE);
		printf("CHECK: %d\n", check);
		printf("BUFFER: %s\n", buff);
		line = fill_line(buff, line);
		printf("LINE: %s\n\n", line);
		if (!check || ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

char	*fill_line(char *buff, char *line)
{
	size_t	len;
	char	*aux;
	int		i;

	i = 0;
	/*aux = NULL;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
			aux = &buff[i];
		i ++;
	}*/
	aux = ft_strchr(buff, '\n');
	if (aux == NULL)
	{
		aux = ft_strnjoin(line, buff, BUFFER_SIZE);
		buff[0] = '\0';
		return (aux);
	}
	len = (size_t)aux - (size_t)buff;
	aux = ft_strnjoin(line, buff, len + ft_strlen(line) + 2);
	if (buff[len + 1])
		reffil_buffer(buff, len);
	else
		buff[0] = '\0';
	if (line != NULL)
	{
		free(line);
	}
	return (aux);
}

void	reffil_buffer(char *buff, size_t len)
{
	int	i;

	i = -1;
	while (++len < BUFFER_SIZE)
	{
		buff[++i] = buff[len];
	}
	while (++i < BUFFER_SIZE)
		buff[i] = '\0';
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("teste.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	free(line);
}
