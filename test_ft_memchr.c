/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:28:19 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 12:57:23 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_memchr_test {
	const char *name;
	const char *haystack;
	char c;
	size_t	n;
	int	cast;
} t_ft_memchr_test;

void	test_ft_memchr(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_memchr_test tests[] = {
		{ "Found at start.",		    "Loren ipsum dolor sit amet",	'L',	1, 0 },
		{ "Not found.",					"Loren ipsum dolor sit amet",	'l',	26, 0 },
		{ "Scan zero bytes.",			"Loren ipsum dolor sit amet",	'L',	0, 0 },
		{ "Found in the middle.",		"Lorem ipsum dolor sit amet",	's',	9, 0 },
		{ "Found with cast check.",		"Loren ipsum dolor sit amet",	'L',	1, 1 },
	};

	PRINT_TEST_NAME("FT_MEMCHR");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		if (tests[i].cast == 1)
			tests[i].c += 256;
		char	*result = (char *)ft_memchr(tests[i].haystack, tests[i].c, tests[i].n);
		char	*expected = (char *)memchr(tests[i].haystack, tests[i].c, tests[i].n);
		if (result == expected)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_pointer_diff(expected, result);
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
				print_pointer_diff(expected, result);
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
