/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:48:02 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:39:59 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_strnstr_test {
	const char *name;
	const char *big;
	const char *little;
	size_t      len;
} t_ft_strnstr_test;

void	test_ft_strnstr(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strnstr_test tests[] = {
		{ "Little at start.",		    "Loren ipsum dolor sit amet",	"Loren", 									26 },
		{ "Little isn't in big.",		"Loren ipsum dolor sit amet",	"Sea Otters",								26 },
		{ "Looking for empty string.",	"Loren ipsum dolor sit amet",	"",		  									26 },
		{ "Little is biger.",  			"Loren ipsum dolor sit amet",	"Lorem ipsum dolor sit amet, but bigger", 	26 },
		{ "Little is equal to big.",	"Loren ipsum dolor sit amet",	"Loren ipsum dolor sit amet",         		26 },
		{ "Little at the end.",			"Loren ipsum dolor sit amet",	"amet",						         		26 },
		{ "Len is too low.",			"Loren ipsum dolor sit amet",	"dolor",						         	5 },
	};

	PRINT_TEST_NAME("FT_STRNSTR");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result = ft_strnstr(tests[i].big, tests[i].little, tests[i].len);
		char	*expected = strnstr(tests[i].big, tests[i].little, tests[i].len);

		if ((result == NULL && expected == NULL) || (result == expected && strcmp(result, expected) == 0))
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
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
