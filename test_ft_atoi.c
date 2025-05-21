/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:52:09 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 12:32:55 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_atoi_test {
	const char *name;
	const char *str;
} t_ft_atoi_test;

void	test_ft_atoi(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_atoi_test tests[] = {
		{"Zero.", "0"},
		{"Multidigit number.", "123"},
		{"Negative sign.", "-123"},
		{"Positive sign.", "+123"},
		{"Whitespaces + positive.", "   42"},
		{"Whitespaces + negative.", "   -123"},
		{"Other Whitespaces.", "\t\n  13"},
		{"Leading zeros positive.", "00000013"},
		{"Leading zeros negative.", "-00000013"},
		{"Digits and letters.", "13aoe"},
		{"Whitespaces, digits and letters.", "     13aoe"},
		{"Letters and digits.", "aoe13"},
		{"Two negative signs.", "--13"},
		{"Two positive signs.", "++13"},
		{"Empty string.", ""},
		{"Only plus sign.", "+"},
		{"Only minus sign.", "-"},
		{"INT_MAX.", "2147483647"},
		{"INT_MIN", "-2147483648"},
		{"Overflow.", "2147483648"},
		{"Underflow", "-2147483649"},
		{"Complex example #1", "  +0000012345abc"},
		{"Complex example #2", "   -00123 456"},
		{"Complex example #3", "123 456"},

	};

	PRINT_TEST_NAME("FT_ATOI");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		int	result = ft_atoi(tests[i].str);
		int	expected = atoi(tests[i].str);
		if (result == expected)
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
