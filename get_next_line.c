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

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (line);
}

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
