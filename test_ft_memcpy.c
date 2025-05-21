/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:27:41 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 13:09:07 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_memcpy_test {
	const char *name;
	const unsigned char *src;
	size_t	n;
} t_ft_memcpy_test;

void	test_ft_memcpy(int verbose)
{
	int	total = 0;
	int	passed = 0;
	unsigned char src1[] = { 0xb };
	unsigned char src2[] = { 0xb, 0xb };
	unsigned char src3[] = { 0xb, 0xb, 0xb };
	unsigned char src4[] = { 0xa, 0xb, 0xc, 0xd, 0xe };
	unsigned char src5[] = { 0xa, 0xa, 0xa };
	t_ft_memcpy_test tests[] = {
		{ "Copy 1 byte.", src1, 1 },
		{ "Copy 2 bytes.", src2, 2 },
		{ "Copy 3 bytes.", src3, 3 },
		{ "Copy 5 different bytes.", src4, 5 },
		{ "Copy 3 oxa bytes.", src5, 3 },
	};

	PRINT_TEST_NAME("FT_MEMCPY");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		unsigned char buf1[tests[i].n];
		unsigned char buf2[tests[i].n];
		memset(buf1, 0x0, tests[i].n);
		memset(buf2, 0x0, tests[i].n);
		char	*result = (char *)ft_memcpy(buf1, tests[i].src, tests[i].n);
		char	*expected = (char *)memcpy(buf2, tests[i].src, tests[i].n);
		if (memcmp(result, expected, tests[i].n) == 0)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_mem_diff(expected, result, tests[i].n);
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
				print_mem_diff(expected, result, tests[i].n);
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
