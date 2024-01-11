#include <stdio.h>
int main()
{
	int		fd;
	char	*str;
	
	// 1° test
	printf("Test 1\n\n");
	fd = open("empty", O_RDWR);
	str = get_next_line(1000);
	str = get_next_line(-1);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 2° test
	printf("Test 2\n\n");
	fd = open("empty", O_RDWR);
	str = get_next_line(fd);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 3° test
	printf("Test 3\n\n");
	fd = open("nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 4° test
	printf("Test 4\n\n");
	fd = open("41_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 5° test
	printf("Test 5\n\n");
	fd = open("41_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 6° test
	printf("Test 6\n\n");
	fd = open("42_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 7° test
	printf("Test 7\n\n");
	fd = open("42_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 8° test
	printf("Test 8\n\n");
	fd = open("43_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 9° test
	printf("Test 9\n\n");
	fd = open("43_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 10° test
	printf("Test 10\n\n");
	fd = open("multiple_nlx5", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 11° test
	printf("Test 11\n\n");
	fd = open("multiple_line_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 12° test
	printf("Test 12\n\n");
	fd = open("multiple_line_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 13° test
	printf("Test 13\n\n");
	fd = open("alternate_line_nl_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 14° test
	printf("Test 14\n\n");
	fd = open("alternate_line_nl_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 15° test
	printf("Test 15\n\n");
	fd = open("big_line_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);

	// 16° test
	printf("Test 16\n\n");
	fd = open("big_line_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}