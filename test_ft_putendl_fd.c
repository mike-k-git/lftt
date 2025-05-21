/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:36:28 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:15:31 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

typedef struct s_ft_putendl_fd_test {
	const char *name;
	char	*str;
	const char *expected;
} t_ft_putendl_fd_test;

void	test_ft_putendl_fd(int verbose)
{
	int	total = 0;
	int	passed = 0;

	t_ft_putendl_fd_test tests[] = {
		{"Empty string.", "", "\n"},
		{"Hello world", "Hello world", "Hello world\n"},
	};

	PRINT_TEST_NAME("FT_PUTENDL_FD");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		const char *filename = "test_output.txt";
		int	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open");
			return ;
		}
		ft_putendl_fd(tests[i].str, fd);
		close(fd);
		char *result = read_file(filename);
		if (result && strcmp(result, tests[i].expected) == 0)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_string_diff(tests[i].expected, result);
			}
			else
				PRINT_PASS_SHORT();
			passed = passed + 1;
		}
		else
		{
			if (verbose)
				PRINT_FAIL(tests[i].name);
	  		else
	  			PRINT_FAIL_SHORT();
		}
		if (remove(filename) != 0)
		{
			perror("remove");
			return ;
		}
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
