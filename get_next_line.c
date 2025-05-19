/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:54:51 by egiraud           #+#    #+#             */
/*   Updated: 2025/05/14 17:01:28 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
#include "get_next_line.h"

char	*init_line(char *line, char *buffer, int contain_eol)
{
	int	i;
	int	add_from;

	i = 0;
	add_from = 0;
	if (contain_eol == 0)
		return (ft_strdup(""));
	else
	{
		
		while (buffer[i] != '\n')
			i++;
		add_from = BUFFER_SIZE - i - 2;
		i = 0;
		line = ft_calloc(sizeof(char), add_from + 1);
		while (add_from < BUFFER_SIZE)
		{
			line[i] = buffer[add_from];
			add_from++;
			i++;
		}
		return (line);
	}
}

char	*end_line(char *line, char *buffer)
{
	int	i;

	i = 0;
	while(i < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		i++;
	return (line);
}

char	*get_line(int fd, char *buffer)
{
	char	*line_tmp;
	int		nb_read;
	int		contain_eol;

	line_tmp = NULL;
	contain_eol = 0;
	if (ft_strchr(buffer, '\n', BUFFER_SIZE) == 1)
		contain_eol = 1;
	line_tmp = init_line(line_tmp , buffer, contain_eol);
	nb_read = 1;
	while (nb_read > 0 && !ft_strchr(buffer, '\n', BUFFER_SIZE))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buffer);
			free(line_tmp);
			return (NULL);
		}
		if (!ft_strchr(buffer, '\n', nb_read))
			line_tmp = ft_strjoin(line_tmp, buffer, nb_read);
		else
			line_tmp = end_line(line_tmp, buffer);
	}
	return (line_tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!buffer)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
		if (!buffer)
			return (NULL);
	}
	line = get_line(fd, buffer);
	if (!line)
	{
		printf("\nerrorline");
		return (NULL);
	}
	return (line);
}


// vas pas s'arreter a la fin du fichier i guess
// faire renvoyer a strchr -1 s'il s'arrete avant BUF_SIZE
// parcourir 
// s'arreter au \n
// save a chaque fois dans un static pour 
// reprendre au bon endroit au prochain appel
// free ce qu'il faut
//
//buf = read
// line = appeler get_line (buf )
//
// dans line 
// line = strjoin(line, new)
//
