/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:04:18 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 15:25:14 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_strjoin_test {
	const char *name;
	const char *s1;
	const char *s2;
	const char *expected;
} t_ft_strjoin_test;

void	test_ft_strjoin(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strjoin_test tests[] = {
		{"Two non-empty strings.", "Hello,", " World!", "Hello, World!"},
		{"First string empty.", "", "Test", "Test"},
		{"Second string empty.", "Test", "", "Test"},
		{"Both strings empty", "", "", ""},
		{"Embedded null character.", "Hello\0World", "Test", "HelloTest"},
		{"Multibyte characters.", "你好", "世界", "你好世界"},
	};

	PRINT_TEST_NAME("FT_STRJOIN");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result = ft_strjoin(tests[i].s1, tests[i].s2);
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
