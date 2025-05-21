/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:40:30 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:15:56 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

typedef struct s_ft_putnbr_fd_test {
	const char *name;
	int	nbr;
	const char *expected;
} t_ft_putnbr_fd_test;

void	test_ft_putnbr_fd(int verbose)
{
	int	total = 0;
	int	passed = 0;

	t_ft_putnbr_fd_test tests[] = {
		{"0", 0, "0"},
		{"-1", -1, "-1"},
		{"INT_MAX", 2147483647, "2147483647"},
		{"INT_MIN", -2147483648, "-2147483648"},
	};

	PRINT_TEST_NAME("FT_PUTNBR_FD");
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
		ft_putnbr_fd(tests[i].nbr, fd);
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
