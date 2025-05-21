/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:55:43 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 19:15:48 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_strdup_test {
	const char *name;
	const char *s;
	char *expected;
} t_ft_strdup_test;

void	test_ft_strdup(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strdup_test tests[] = {
		{"Normal string.", "Hello World", "Hello World"},
		{"Empty string.", "", ""},
		{"Null-terminator in the middle.", "Hello\0World", "Hello"},
	};

	PRINT_TEST_NAME("FT_STRDUP");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result = ft_strdup(tests[i].s);
		if (strcmp(result, tests[i].expected) == 0 && &result != &tests[i].expected)
		{
			if (verbose)
	  		{
				PRINT_PASS(tests[i].name);
				print_string_diff(tests[i].expected, result);
				print_pointer_diff(tests[i].expected, result);
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
				print_pointer_diff(tests[i].expected, result);
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
