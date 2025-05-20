#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
//#include "get_next_line_bonus.h"

//cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -Iget_next_line.h -o gnl -g
//cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c -Iget_next_line_bonus.h -o gnlbonus -g


void description(int test_num)
{
    printf("Running test %d: ", test_num);
    if (test_num == 1)
        printf("Empty file\n");
	else if (test_num == 2)
		printf("Single \\n\n");
    else if (test_num == 3)
        printf("Multiple lines ending with \\n\n");
    else if (test_num == 4)
        printf("No newline at EOF\n");
    else if (test_num == 5)
        printf("Single long line\n");
	else if (test_num == 6)
		printf("Single long line no \\n\n");
    else if (test_num == 7)
        printf("Only newlines\n");
	else if (test_num == 8)
		printf("Mixed\n");
    else
        printf("Custom or unknown test\n");
}

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    char    filename[32];
    int     test_num;

    if (argc != 2)
        return(printf("Need: %s <test_number>\n", argv[0]), 1);
    test_num = atoi(argv[1]);
    if (test_num <= 0)
        return(printf("Invalid test number: %s\n", argv[1]), 1);
    snprintf(filename, sizeof(filename), "test%d", test_num);
    description(test_num);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return(printf("Error opening file"), 1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}


/*
int main(void)
{
	int	fd = open("test99", O_RDONLY);
	//get_next_line(fd);
	close(fd);
	get_next_line(fd);
}
*/

/*
//BONUS
int main()
{
	int fd[9];

	fd[0] = open("test1", O_RDONLY);
	fd[1] = open("test2", O_RDONLY);
	fd[2] = open("test3", O_RDONLY);
	fd[3] = open("test4", O_RDONLY);
	fd[4] = open("test5", O_RDONLY);
	fd[5] = open("test6", O_RDONLY);
	fd[6] = open("test7", O_RDONLY);
	fd[7] = open("test8", O_RDONLY);

	printf("%s\n", get_next_line(fd[0]));
	printf("%s\n", get_next_line(fd[1]));
	printf("%s\n", get_next_line(fd[3]));
	printf("%s\n", get_next_line(fd[7]));
	printf("%s\n", get_next_line(fd[3]));
	printf("%s\n", get_next_line(fd[2]));
	printf("%s\n", get_next_line(fd[7]));
	printf("%s\n", get_next_line(fd[2]));
	printf("%s\n", get_next_line(fd[7]));
	printf("%s\n", get_next_line(fd[6]));
	printf("%s\n", get_next_line(fd[4]));
	printf("%s", get_next_line(fd[5]));
	//printf("%s", get_next_line(fd[8]));

	int i = 0;
	while (i < 8)
	{
		close(fd[i]);
		i++;
	}
}
*/

