//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

#include "get_next_line.h"

int main()
{
	int fd = open("file.txt" , O_RDONLY);
	char *str = get_next_line(fd);
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
}
