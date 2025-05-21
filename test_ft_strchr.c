/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:22:53 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:23:55 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_strchr_test {
	const char *name;
	const char *haystack;
	char c;
	int	cast;
} t_ft_strchr_test;

void	test_ft_strchr(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strchr_test tests[] = {
		{ "Found at start.",		    "Loren ipsum dolor sit amet",	'L',	0 },
		{ "Not found.",					"Loren ipsum dolor sit amet",	'4',	0 },
		{ "Found at the end.",			"Loren ipsum dolor sit amet.",	'.',	0 },
		{ "Found in the middle.",		"Lorem ipsum dolor sit amet",	's',	0 },
		{ "Found null-terminator.",		"Lorem ipsum dolor sit amet",	'\0',	0 },
		{ "Found with cast check.",		"Loren ipsum dolor sit amet",	'L',	1 },
	};

	PRINT_TEST_NAME("FT_STRCHR");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		if (tests[i].cast == 1)
			tests[i].c += 256;
		char	*result = ft_strchr(tests[i].haystack, tests[i].c);
		char	*expected = strchr(tests[i].haystack, tests[i].c);
		if (result == expected)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_pointer_diff(expected, result);
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
				print_pointer_diff(expected, result);
				print_string_diff(expected, result);
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
