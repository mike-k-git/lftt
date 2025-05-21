/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:55:58 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 12:49:53 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_isprint_test {
	const char *name;
	int	c;
} t_ft_isprint_test;

void	test_ft_isprint(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_isprint_test tests[] = {
		{"First lowercase letter.", 'a'},
		{"Last lowercase letter.", 'z'},
		{"First uppercase letter.", 'A'},
		{"Last uppercase letter.", 'Z'},
		{"First digit.", '0'},
		{"Last digit.", '9'},
		{"First control character.", '\0'},
		{"Last control character.", 31},
		{"Space.", ' '},
		{"Slash.", '/'},
		{"Colon.", ':'},
		{"At sign.", '@'},
		{"Opening bracket.", '['},
		{"Grave accent.", '`'},
		{"Opening brace.", '{'},
		{"DEL", 127},
		{"Underflow.", -1},
		{"Overflow.", 128},
	};

	PRINT_TEST_NAME("FT_ISPRINT");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		int	result = ft_isprint(tests[i].c);
		int	expected = isprint(tests[i].c);
		if ((result != 0) == (expected != 0))
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
