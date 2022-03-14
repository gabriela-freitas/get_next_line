/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:54:08 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/14 21:52:54 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*fill_line(char *buff, char *line);
void		reffil_buffer(char *buff);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);

#endif
