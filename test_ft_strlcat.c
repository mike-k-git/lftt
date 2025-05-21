/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:48:02 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:28:48 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_strlcat_test {
	const char *name;
	const char *source;
	const char *dest;
	size_t      buf_size;
	size_t		buf_size_arg;
} t_ft_strlcat_test;

void	test_ft_strlcat(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strlcat_test tests[] = {
		{ "ft_strlcat into empty buffer",	"foo",			"",         	10, 10 },
		{ "append more",       				" bar",			"foo",      	10, 10 },
		{ "and more to buffer limit",		"!!",			"foo bar",  	10, 10 },
		{ "one more character",				"!",			"foo bar!!",	10, 10 },
		{ "truncation",						"hello world",	"",				10, 10 },
		{ "lie about buffer length",		"sausage",		"",				10, 5 },
		{ "add more up to real size",		"saus",			"bacon eggs",	10, 10 },
		{ "no change with a size 0",		"sausbacon",	"!!",			10, 0 },
		{ "appending empty string",			"sausbacon",	"",				10, 0 },
		{ "empty string to empty buffer",	"",				"",				10, 0 },
		{ "append to smaller buffer",		"foo",			"",				10, 2 },
		{ "append empty string",			"",				"f",			10, 10 },
	};

	PRINT_TEST_NAME("FT_STRLCAT");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	buf1[tests[i].buf_size];
		char	buf2[tests[i].buf_size];
		memset(buf1, 0xAA, tests[i].buf_size);
		memset(buf2, 0xAA, tests[i].buf_size);
		strcpy(buf1, tests[i].dest);
		strcpy(buf2, tests[i].dest);
		size_t	result = ft_strlcat(buf1, tests[i].source, tests[i].buf_size_arg);
		size_t	expected = strlcat(buf2, tests[i].source, tests[i].buf_size_arg);
		if (result == expected && memcmp(buf1, buf2, tests[i].buf_size) == 0)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_sizet_diff(expected, result);
				print_mem_diff(buf1, buf2, tests[i].buf_size);
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
				print_sizet_diff(expected, result);
				print_mem_diff(buf1, buf2, tests[i].buf_size);
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
