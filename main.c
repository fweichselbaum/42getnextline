// #include "get_next_line.h"
// #include <fcntl.h>
// #include <string.h>
// #include <stdio.h>

// int nstrcmp(char *s1, char *s2)
// {
// 	if (!s1)
// 		return ((int)s2);
// 	if (!s2)
// 		return ((int)s1);
// 	return (strcmp(s1, s2));
// }

// void test_gnl(int fd, char *expected)
// {
// 	char *real = get_next_line(fd);
// 	int comp = nstrcmp(real, expected);
// 	if (comp != 0)
// 	{
// 		puts("== FAILED ==");
// 		printf("Expected '%s'\n", expected);
// 		printf("Real     '%s'\n", real);
// 		free(real);
// 		exit(0);
// 	}
// 	free(real);
// }

// int main()
// {
// 	char *name = "read_error.txt";
// 	int fd = open(name, O_RDONLY);
// 	puts("1");
// 	/* 1 */ test_gnl(fd, "aaaaaaaaaa\n");
// 	puts("2");
// 	/* 2 */ test_gnl(fd, "bbbbbbbbbb\n");
// 	puts("3");
// 	// set the next read call to return -1
// 	/* 3 */ test_gnl(fd - 100, NULL);
// 	close(fd);
// 	fd = open(name, O_RDONLY);
// 	puts("4");
// 	/* 4 */ test_gnl(fd, "aaaaaaaaaa\n");
// 	puts("5");
// 	/* 5 */ test_gnl(fd, "bbbbbbbbbb\n");
// 	puts("6");
// 	/* 6 */ test_gnl(fd, "cccccccccc\n");
// 	puts("7");
// 	/* 7 */ test_gnl(fd, "dddddddddd\n");
// 	puts("8");
// 	/* 8 */ test_gnl(fd, NULL);
// 	close(fd);
// }