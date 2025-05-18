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
	int	start;

	i = 0;
	start = 0;
	if (contain_eol == 0)
		return (ft_strdup(""));
	else
	{
		
		while (buffer[i] != '\n')
			i++;
		start = BUFFER_SIZE - i;
		i = 0;
		line = ft_calloc(sizeof(char), BUFFER_SIZE - start);
		while (start < BUFFER_SIZE)
		{
			line[i] = buffer[start];
			start++;
			i++;
		}
		return (line);
	}
}

char	*read_fd(int fd, char *buffer)
{
	//char	*ret_str;
	int		nb_read;

	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read < BUFFER_SIZE)
		printf("end");
	return (buffer);
}

char	*get_next_line(int fd)
{
	int			contain_eol;
	int			i;
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	contain_eol = 0;
	line = NULL;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (ft_strchr(buffer, '\n', BUFFER_SIZE) == 1)
		contain_eol = 1;
	line = init_line(line , buffer, contain_eol);
	while (ft_strchr(buffer, '\n', BUFFER_SIZE) == 0)
	{
		buffer = read_fd(fd, buffer);
		if (ft_strchr(buffer, '\n', BUFFER_SIZE) == 0)
			line = ft_strjoin(line, buffer, BUFFER_SIZE);
	}
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = ft_strjoin(line, buffer, i + 1);
	//if (ft_strchr(line, '\n', ft_strlen(line)))
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
