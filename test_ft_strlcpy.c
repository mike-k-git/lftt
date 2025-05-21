/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:17:43 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:38:49 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_strlcpy_test {
	const char *name;
	const char *source;
	size_t      buf_size;
	size_t      copy_size;
} t_ft_strlcpy_test;

void	test_ft_strlcpy(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strlcpy_test tests[] = {
		{ "Basic ft_strlcpy.",                  "foo",         10, 3 },
		{ "Exact length of buffer.",            "hello wor",   10, 9 },
		{ "One more than buffer length.",       "world hell",  10, 10 },
		{ "More than buffer length",            "hello world", 10, 11 },
		{ "Buffer is unchanged if size 0.",     "foo",         10, 0 },
		{ "Copy empty string with size 0.",     "",            10, 0 },
		{ "Copy empty string in full buffer.",  "",            10, 10 },
		{ "Copy string into smaller buffer.",   "foo",         10, 2 },
		{ "Copy empty string into buffer of 1.", "",           10, 1 },
	};

	t_ft_strlcpy_test tests_len[] = {
		{"Use ft_strlcpy as ft_strlen #1",	"foo", 0, 0},
		{"Use ft_strlcpy as ft_strlen #2",	"hello world", 0, 0},
	};

	PRINT_TEST_NAME("FT_STRLCPY");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	buf1[tests[i].buf_size];
		char	buf2[tests[i].buf_size];
		memset(buf1, 0xAA, tests[i].buf_size);
		memset(buf2, 0xAA, tests[i].buf_size);
		size_t	result = ft_strlcpy(buf1, tests[i].source, tests[i].copy_size);
		size_t	expected = strlcpy(buf2, tests[i].source, tests[i].copy_size);
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

	size_t num_tests_len = sizeof(tests_len) / sizeof(tests_len[0]);
	for (size_t i = 0; i < num_tests_len; i++)
	{
		total = total + 1;
		char	*buf1 = NULL;
		char	*buf2 = NULL;
		size_t	result = ft_strlcpy(buf1, tests_len[i].source, tests_len[i].copy_size);
		size_t	expected = strlcpy(buf2, tests_len[i].source, tests_len[i].copy_size);
		if (result == expected)
		{
			if (verbose)
			{
				PRINT_PASS(tests_len[i].name);
				print_sizet_diff(expected, result);
			}
			else
				PRINT_PASS_SHORT();
			passed = passed + 1;
		}
		else
		{
			if (verbose)
			{
				PRINT_FAIL(tests_len[i].name);
				print_sizet_diff(expected, result);
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

