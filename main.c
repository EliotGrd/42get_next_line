/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:34:46 by egiraud           #+#    #+#             */
/*   Updated: 2025/05/20 20:42:59 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
printf("%ld", sysconf(_SC_OPEN_MAX));*/

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
