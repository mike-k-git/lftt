/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:34:20 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 19:07:08 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	ft_plusindex(unsigned int idx, char *c)
{
	*c += idx;
}

static void	ft_fakeuppercase(unsigned int idx, char *c)
{
	if (idx > 127)
		*c = 0;
	*c -= 32;
}

typedef struct s_ft_striteri_test {
	const char *name;
	char *s;
	void (*f)(unsigned int, char *);
	char *expected;
} t_ft_striteri_test;

void	test_ft_striteri(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_striteri_test tests[] = {
		{"'aaa' plus index", "aaa", ft_plusindex, "abc"},
		{"'aaa' to uppercase", "aaa", ft_fakeuppercase, "AAA"},
		{"\"\" empty string", "", ft_fakeuppercase, ""},
	};

	PRINT_TEST_NAME("FT_STRITERI");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*test_str = strdup(tests[i].s);
		if (!test_str)
			return ;
		ft_striteri(test_str, tests[i].f);
		if (strcmp(tests[i].expected, test_str) == 0)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_string_diff(tests[i].expected, test_str);
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
				print_string_diff(tests[i].expected, tests[i].s);
			}
			else
				PRINT_FAIL_SHORT();
		}
		if (test_str)
			free(test_str);
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
