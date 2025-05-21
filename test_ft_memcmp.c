/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:59:28 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:01:11 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_memcmp_test {
	const char *name;
	const char *s1;
	const char *s2;
	size_t n;
} t_ft_memcmp_test;

void	test_ft_memcmp(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_memcmp_test tests[] = {
		{ "Two memory areas are the same when compared with zero bytes.", "", "", 0 },
		{ "The first 2 bytes of 'foo' and 'foobar' are equal.", "foo", "foobar", 2 },
		{ "The first 3 bytes of 'foo' and 'foobar' are equal.", "foo", "foobar", 3},
		{ "The first 4 bytes of 'foo' and 'foobar' are not equal.", "foo", "foobar", 4},
		{ "The first byte of 'foo' and 'bar' are equal.", "foo", "bar", 1},
		{ "The first 3 bytes of 'foo' and 'bar' are not equal.", "foo", "bar", 3},
		{ "'foo' is lexicographically less than 'moo'", "foo", "moo", 4},
		{ "'moo' is lexicographically greater than 'foo'", "moo", "foo", 4},
		{ "'oomph' is lexicographically less than 'oops' for the first 3 bytes", "oomph", "oops", 4},
		{ "'foo' is lexicographically less than 'foobar' for the first 4 bytes", "foo", "foobar", 4},
		{ "'foobar' is lexicographically greater than 'foo' for the first 4 bytes", "foobar", "foo", 4},
	};

	PRINT_TEST_NAME("FT_MEMCMP");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		int	result = ft_memcmp(tests[i].s1, tests[i].s2, tests[i].n);
		int	expected = memcmp(tests[i].s1, tests[i].s2, tests[i].n);
		if ((result == 0) == (expected == 0))
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_int_diff(expected, result);
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
				print_int_diff(expected, result);
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
