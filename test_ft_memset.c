/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:39:41 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:08:46 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_memset_test {
	const char *name;
	size_t		buf_size;
	size_t		n;
	size_t		zeroed;
	size_t		offset;
} t_ft_memset_test;

void	test_ft_memset(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_memset_test tests[] = {
		{"Zero entire array.", 5, 5, 0, 0},
		{"Zero first three bytes.", 5, 3, 0, 0},
		{"Zero none.", 3, 0, 0, 0},
		{"Single byte buffer.", 1, 1, 0, 0},
		{"Array is already zeroed.", 3, 3, 1, 0},
		{"Zero only last byte.", 5, 1, 0, 4},
		{"Zero two bytes in the middle.", 5, 2, 0, 2},
	};

	PRINT_TEST_NAME("FT_MEMSET");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	buf1[tests[i].buf_size];
		char	buf2[tests[i].buf_size];
		if (tests[i].zeroed)
		{
			memset(buf1, 0x00, tests[i].buf_size);
			memset(buf2, 0x00, tests[i].buf_size);
		}
		else
		{
			memset(buf1, 0xAA, tests[i].buf_size);
			memset(buf2, 0xAA, tests[i].buf_size);
		}
		ft_memset(buf1 + tests[i].offset, 0x0, tests[i].n);
		memset(buf2 + tests[i].offset, 0x0, tests[i].n);
		if (memcmp(buf1, buf2, tests[i].buf_size) == 0)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_mem_diff(buf2, buf1, tests[i].buf_size);
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
				print_mem_diff(buf2, buf1, tests[i].buf_size);
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
