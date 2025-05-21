/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:25:12 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:34:30 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_strlen_test {
	const char *name;
	const char *str;
} t_strlen_test;

void	test_ft_strlen(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_strlen_test tests[] = {
		{"Empty string.", ""},
		{"Single character.", "a"},
		{"Typical word.", "hello"},
		{"String with spaces.", "hello world"},
		{"String with special characters", "!@#$%^&*()"},
		{"String with escape sequences", "hello\nworld"},
		{"String with embedded null character", "hel\0lo"},
	};

	PRINT_TEST_NAME("FT_STRLEN");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		size_t	result = ft_strlen(tests[i].str);
		size_t	expected = strlen(tests[i].str);
		if (result == expected)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_sizet_diff(expected, result);
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
				print_sizet_diff(expected, result);
			}
			else
	  			PRINT_FAIL_SHORT();
		}
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
