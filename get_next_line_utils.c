/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:07:46 by egiraud           #+#    #+#             */
/*   Updated: 2025/05/14 16:54:32 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t elem, size_t size)
{
	size_t	global_size;
	void	*tmp;
	unsigned char	*ptr;

	if (size != 0 && elem > (size_t)-1 / size)
		return (NULL);
	global_size = elem * size;
	tmp = malloc(global_size);
	if (!tmp)
		return (NULL);
	ptr = (unsigned char *)tmp;
	while (global_size--)
	{
		*ptr = 0;
		ptr++;
	}
	return (tmp);
}

int	ft_strchr(char *str, char c, int size)
{
	int	i;

	i = 0;
	while (str[i] && size)
	{
		if (str[i] == c)
			return (i);
		i++;
		size--;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*nstr;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	nstr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!nstr)
		return (NULL);
	while (str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = 0;
	return (nstr);
}

char	*ft_strjoin(char *s1, char *s2, int size)
{
	char	*nstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	nstr = malloc(sizeof(char) * (ft_strlen(s1) + size + 1));
	if (!nstr)
		return (NULL);
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	while (s2[j] && j < size)
		nstr[i++] = s2[j++];
	nstr[i] = 0;
	return (nstr);
}
