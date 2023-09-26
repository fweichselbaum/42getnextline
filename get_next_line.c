/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichs@student.42vienna.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:39:23 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/22 16:51:38 by fweichse         ###   ########.fr       */
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
			ft_move_buf(buf, ft_strpos(buf, '\n') + 1);
			return (str);
		}
	}
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

// int main()
// {
// 	printf("%d\n", BUFFER_SIZE);
// 	// int fd = open("lines_around_10.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(1)) != NULL)
// 	{
// 		printf("line: %p %s\n", line, line);
// 		free(line);
// 	}
// 	// close(fd);
// }

// void	debug(char *line)
// {
// 	printf("line: %p\n", line);
// 	if (!line)
// 		return ;
// 	puts("===================");
// 	int i = 0;
// 	while (line[i])
// 	{
// 		printf("%3d '%c'\n", line[i], line[i]);
// 		i++;
// 	}
// 	fflush(NULL);
// 	free(line);
// }

// int main(int argc, char **argv)
// {
// 	int fd = open("/home/fabian/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
// 	printf("fd %d\n", fd);
// 	debug(get_next_line(fd));
// 	debug(get_next_line(fd));
// 	debug(get_next_line(fd));
// 	debug(get_next_line(fd));
// 	debug(get_next_line(fd));
// 	debug(get_next_line(fd));
// 	debug(get_next_line(fd));
// 	return 0;
// }