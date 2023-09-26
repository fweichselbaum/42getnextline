/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichs@student.42vienna.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:03:32 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/19 17:52:12 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strpos(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_move_buf(char *buf, int n)
{
	int	i;

	i = 0;
	while (buf[i + n])
	{
		buf[i] = buf[i + n];
		i++;
	}
	while (buf[i])
		buf[i++] = '\0';
}

char	*ft_append(char *str, const char *append, int n)
{
	int		i;
	int		str_len;
	char	*ptr;

	str_len = ft_strlen(str);
	ptr = ft_realloc(str, str_len, str_len + n + 1);
	if (!ptr)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		ptr[str_len + i] = append[i];
		i++;
	}
	ptr[str_len + i] = '\0';
	return (ptr);
}

void	*ft_realloc(void *p, int old_size, int new_size)
{
	unsigned char	*new;
	int				i;

	new = malloc(new_size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < new_size)
		new[i++] = 0;
	if (!p)
		return (new);
	i = 0;
	while (i < old_size)
	{
		new[i] = ((unsigned char *)p)[i];
		i++;
	}
	free(p);
	return (new);
}
