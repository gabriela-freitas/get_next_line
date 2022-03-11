/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:53:58 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/11 19:51:41 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include<fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont ++;
	return (cont);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize <= len_d)
		return (dstsize + ft_strlen(src));
	else
		len_s += len_d;
	i = 0;
	while (src[i] != '\0' && len_d < dstsize - 1)
	{
			dst[len_d] = src[i];
			i ++;
			len_d++;
	}
	dst[len_d] = '\0';
	return (len_s);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (src_len && dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (i || !src_len || dstsize == 1)
		dest[i] = '\0';
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i ++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

/* um join diferente porque eu quero juntar a line
com a buff mas so ate ft_strlen(line) + len */
char	*ft_strnjoin(char const *line, char const *buff, size_t size)
{
	char	*str;


	printf("entrei!!!!\n");
	str = (char *)malloc(size * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (line == NULL)
	{
		ft_strlcpy(str, buff, size + 1);
		printf("to saindo do join\n");
		return (str);
	}
	printf("antes do strlcpy\n");
	printf("len do s1:%lu\n", ft_strlen(line));
	ft_strlcpy(str, line, ft_strlen(line) + 1);
	ft_strlcat(str, buff, size);
	printf("depois do strlcat\n");
	return (str);
}
