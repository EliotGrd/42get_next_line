//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

#include "get_next_line.h"

int main()
{
	int	secure = 0;
	int fd = open("file.txt" , O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	while (str != NULL && secure < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		secure++;
	}
	close(fd);
}
