/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:57:36 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 15:25:33 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_substr_test {
	const char *name;
	const char *s;
	unsigned int start;
	size_t len;
	const char *expected;
} t_ft_substr_test;

void	test_ft_substr(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_substr_test tests[] = {
		{"Valid substring within bounds.", "Hello, World!", 7, 5, "World"},
		{"Substring that is at the Start of the string.", "Hello, World!", 0, 5, "Hello"},
		{"Substring that exceeds the length of the string.", "Hello, World!", 0, 25, "Hello, World!"},
		{"Start index beyond string length.", "Hello, World!", 25, 10, ""},
		{"Empty string.", "", 0, 10, ""},
		{"Negative start index.", "Hello, World!", -1, 10, ""},
		{"Start index equals string length.", "Hello, World!", 13, 1, ""},
		{"Zero length requested.", "Hello, World!", 1, 0, ""},
		{"Substring in the middle of the string.", "Hello, World!", 2, 3, "llo"},
		{"Substring equal to the entire string.", "Hello, World!", 0, 13, "Hello, World!"},
	};

	PRINT_TEST_NAME("FT_SUBSTR");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result = ft_substr(tests[i].s, tests[i].start, tests[i].len);
		if (strcmp(result, tests[i].expected) == 0)
		{
			if (verbose)
	  		{
				PRINT_PASS(tests[i].name);
				print_string_diff(tests[i].expected, result);
			}
			else
	  		{
				PRINT_PASS_SHORT();
			}	
			passed = passed + 1;
		}
		else
		{
			if (verbose)
			{
				PRINT_FAIL(tests[i].name);
				print_string_diff(tests[i].expected, result);
			}
			else
	  		{
				PRINT_FAIL_SHORT();
			}
		}
		if (result)
			free(result);
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
