/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichs@student.42vienna.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:39:23 by fweichse          #+#    #+#             */
/*   Updated: 2023/10/04 17:23:44 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(s + i) = '\0';
		i++;
	}
}

int	read_buf(int fd, char *buf, char *str, char **ret)
{
	int	bytes;

	if (ft_strlen(buf) == 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			ft_bzero(buf, BUFFER_SIZE + 1);
			*ret = NULL;
			return (0);
		}
		if (bytes == 0)
		{
			*ret = str;
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	char		*read;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_bzero(buf, BUFFER_SIZE + 1), NULL);
	while (1)
	{
		if (!read_buf(fd, buf, str, &read))
			return (read);
		if (ft_strpos(buf, '\n') == -1)
		{
			str = ft_append(str, buf, ft_strlen(buf));
			ft_bzero(buf, BUFFER_SIZE + 1);
			if (!str)
				return (NULL);
		}
		else
		{
			str = ft_append(str, buf, ft_strpos(buf, '\n') + 1);
			return (ft_move_buf(buf, ft_strpos(buf, '\n') + 1), str);
		}
	}
	return (NULL);
}
