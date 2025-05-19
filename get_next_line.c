/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:05:39 by egiraud           #+#    #+#             */
/*   Updated: 2025/05/19 21:31:07 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stash
//remplir jusqu'au buffer du \n dans un tmp
//couper l'apres \n et return
//
//remplir le stash de l'apres \n
#include "get_next_line.h"

char	*fill_leftovers(char *stash)
{
	char	*tmp;
	int		i;
	
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		//faire en sorte de faire comprendre que c eof
	tmp = ft_strdup(stash + i + 1);
	//free(stash) ?
	return (tmp);
}

char	*get_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	//veriff if (!stash || !stash[0])
	//	return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[j] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else 
		line = ft_substr(stash, 0, i);
	return (line);
//rechecker ici que les index sont bien les bons
}

char	*read_to()
{
	
	//NULL TERMINATE STASH
}

char	*get_next_line(int fd)
{
	char	*line;
	static char *stash[OPEN_MAX];
	
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_to(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = fill_leftovers(stash[fd]);
	return (line);
}
