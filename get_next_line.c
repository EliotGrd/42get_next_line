/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:05:39 by egiraud           #+#    #+#             */
/*   Updated: 2025/05/21 15:11:31 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_leftovers(char *stash)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	tmp = ft_strdup(stash + i + 1);
	free(stash);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*lining(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_to(int fd, char *stash)
{
	int		bytes_read;
	char	*tmp;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(stash, '\n', BUFFER_SIZE) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
			return (NULL);
		free(stash);
		stash = tmp;
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		return (stash = NULL, NULL);
	}
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	stash = read_to(fd, stash);
	if (!stash)
		return (NULL);
	line = lining(stash);
	if (!line)
	{
		free(stash);
		return (stash = NULL, NULL);
	}
	stash = fill_leftovers(stash);
	return (line);
}
