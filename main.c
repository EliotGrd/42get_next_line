//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

#include "get_next_line.h"

int main()
{
	int fd = 0;

	fd = open("file.txt" , O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
}
