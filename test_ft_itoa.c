/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:30:26 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 15:26:07 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_itoa_test {
	const char *name;
	int	n;
} t_ft_itoa_test;

void	test_ft_itoa(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_itoa_test tests[] = {
		{"0", 0},
		{"-123", -123},
		{"456", 456},
		{"-1", -1},
		{"100000", 100000},
		{"999", 999},
		{"-2147483648", (-2147483647 - 1)},
		{"2147483647", 2147483647},
		{"100", 100},
		{"-5000", -5000},
	};

	PRINT_TEST_NAME("FT_ITOA");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result = ft_itoa(tests[i].n);
		char	*expected = (char *)tests[i].name;
		if (strcmp(result, expected) == 0)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_string_diff(expected, result);
			}
			else
				PRINT_PASS_SHORT();
			passed = passed + 1;
		}
		else
		{
			if (verbose)
			{
				PRINT_FAIL(tests[i].name);
				print_string_diff(expected, result);
			}
	  		else
	  			PRINT_FAIL_SHORT();
		}
		if (result)
			free(result);
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
