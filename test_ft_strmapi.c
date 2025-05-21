/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:14:50 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 18:32:01 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static char	ft_plusindex(unsigned int idx, char c)
{
	return (c + idx);
}

static char	ft_fakeuppercase(unsigned int idx, char c)
{
	if (idx > 127)
		return (0);
	return (c - 32);
}

typedef struct s_ft_strmapi_test {
	const char *name;
	const char *s;
	char (*f)(unsigned int, char);
	char *expected;
} t_ft_strmapi_test;

void	test_ft_strmapi(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strmapi_test tests[] = {
		{"'aaa' plus index", "aaa", ft_plusindex, "abc"},
		{"'aaa' to uppercase", "aaa", ft_fakeuppercase, "AAA"},
		{"\"\" empty string", "", ft_fakeuppercase, ""},
	};

	PRINT_TEST_NAME("FT_STRMAPI");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result = ft_strmapi(tests[i].s, tests[i].f);
		if (strcmp(tests[i].expected, result) == 0)
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
			{
				PRINT_FAIL(tests[i].name);
				print_string_diff(tests[i].expected, result);
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
