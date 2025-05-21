/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:16:20 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 20:08:42 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_isdigit(int verbose);
void	test_ft_isascii(int verbose);
void	test_ft_isprint(int verbose);
void	test_ft_toupper(int verbose);
void	test_ft_tolower(int verbose);
void	test_ft_itoa(int verbose);
void	test_ft_strchr(int verbose);
void	test_ft_strrchr(int verbose);
void	test_ft_memset(int verbose);
void	test_ft_memmove(int verbose);
void	test_ft_strncmp(int verbose);
void	test_ft_memcpy(int verbose);
void	test_ft_memchr(int verbose);
void	test_ft_memcmp(int verbose);
void	test_ft_bzero(int verbose);
void	test_ft_strlcpy(int	verbose);
void	test_ft_strlcat(int verbose);
void	test_ft_strnstr(int verbose);
void	test_ft_strlen(int verbose);
void	test_ft_atoi(int verbose);
void	test_ft_calloc(int verbose);
void	test_ft_isalpha(int verbose);
void	test_ft_isalnum(int verbose);
void	test_ft_putchar_fd(int verbose);
void	test_ft_putstr_fd(int verbose);
void	test_ft_putendl_fd(int verbose);
void	test_ft_putnbr_fd(int verbose);
void	test_ft_substr(int verbose);
void	test_ft_strjoin(int verbose);
void	test_ft_strtrim(int verbose);
void	test_ft_split(int verbose);
void	test_ft_strmapi(int verbose);
void	test_ft_striteri(int verbose);
void	test_ft_strdup(int verbose);
void	test_ft_lstnew(int verbose);

void	print_string_diff(const char *expected, const char *result)
{
    printf(COLOR_YELLOW "Expected: " COLOR_RESET "\"%s\"\n", expected);
    printf(COLOR_CYAN   "Result  : " COLOR_RESET "\"%s\"\n", result);
}

void	print_char_diff(char expected, char result)
{
    printf(COLOR_YELLOW "Expected: " COLOR_RESET "\"%d (%c)\"\n", expected, expected);
    printf(COLOR_CYAN   "Result  : " COLOR_RESET "\"%d (%c)\"\n", result, expected);
}

void	print_sizet_diff(size_t expected, size_t result)
{
    printf(COLOR_YELLOW "Expected: " COLOR_RESET "\"%zu\"\n", expected);
    printf(COLOR_CYAN   "Result  : " COLOR_RESET "\"%zu\"\n", result);
}

void	print_pointer_diff(void *expected, void *result)
{
    printf(COLOR_YELLOW "Expected: " COLOR_RESET "\"%p\"\n", expected);
    printf(COLOR_CYAN   "Result  : " COLOR_RESET "\"%p\"\n", result);
}

void	print_int_diff(int expected, int result)
{
    printf(COLOR_YELLOW "Expected: " COLOR_RESET "\"%d\"\n", expected);
    printf(COLOR_CYAN   "Result  : " COLOR_RESET "\"%d\"\n", result);
}

void	print_mem_diff(void *expected, void *result, size_t num)
{
	unsigned char	*e;
	unsigned char	*r;
	size_t	i;

	i = 0;
	e = (unsigned char *)expected;
	r = (unsigned char *)result;
    printf(COLOR_YELLOW "Expected: " COLOR_RESET);
	while (i++ < num)
		printf("%d ", *e++);
	printf("\n");
	printf(COLOR_CYAN   "Result  : " COLOR_RESET);
	i = 0;
	while (i++ < num)
		printf("%d ", *r++);
	printf("\n");
}

void	print_arr_diff(char **arr1, char **arr2)
{
    printf(COLOR_YELLOW "Expected: " COLOR_RESET);
	for (int i = 0; arr1[i] != NULL; i++)
	{
		printf("%s -> ", arr1[i]);
	}
	printf("NULL\n");
    printf(COLOR_CYAN "Result  : " COLOR_RESET);
	for (int i = 0; arr2[i] != NULL; i++)
	{
		printf("%s -> ", arr2[i]);
	}
	printf("NULL\n");
}

#define BUFFER_SIZE 1024

char *read_file(const char *filename)
{
	static char buffer[BUFFER_SIZE];
	int	fd = open(filename, O_RDONLY);
if (fd == -1)
		return (NULL);
	ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	close (fd);
	if (bytes_read >= 0)
		buffer[bytes_read] = '\0';
	return (buffer);
}

int	main(int argc, char* argv[])
{
	printf("Running Libft tests...\n\n");
	int v = 0;
	if (argc == 2)
		v = atoi(argv[1]);;
  	test_ft_atoi(v);
	test_ft_bzero(v);
	test_ft_calloc(v);
	test_ft_isalnum(v);
	test_ft_isalpha(v);
	test_ft_isascii(v);
	test_ft_isdigit(v);
	test_ft_isprint(v);
	test_ft_itoa(v);
	test_ft_memchr(v);
	test_ft_memcmp(v);
	test_ft_memcpy(v);
	test_ft_memmove(v);
	test_ft_memset(v);
	test_ft_putchar_fd(v);
	test_ft_putstr_fd(v);
	test_ft_putendl_fd(v);
	test_ft_putnbr_fd(v);
	test_ft_strchr(v);
	test_ft_strjoin(v);
	test_ft_strlcat(v);
	test_ft_strlcpy(v);
	test_ft_strlen(v);
	test_ft_strncmp(v);
	test_ft_strnstr(v);
	test_ft_strrchr(v);
	test_ft_strtrim(v);
	test_ft_substr(v);
	test_ft_tolower(v);
	test_ft_toupper(v);
	test_ft_split(v);
	test_ft_strmapi(v);
	test_ft_striteri(v);
	test_ft_strdup(v);
	test_ft_lstnew(v);
	printf("\nAll tests completed.\n");
	return (0);
}
