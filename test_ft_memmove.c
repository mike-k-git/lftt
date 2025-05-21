/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:52:40 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 16:35:41 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_memmove_test {
	const char *name;
	unsigned char *dest;
	unsigned char *src;
	size_t d_offset;
	size_t s_offset;
	size_t n;
	size_t buff_size;
	int	overlapping;
} t_ft_memmove_test;

void	test_ft_memmove(int verbose)
{
	int	total = 0;
	int	passed = 0;
	unsigned char arr1[] = { 65, 66, 67, 68, 69, 0, 45 };
	unsigned char arr2[] = { 0, 0, 0, 0, 0, 0, 0 };
	unsigned char big_arr1[99];
	unsigned char big_arr2[100];
	memset(big_arr1, 0, 99);
	memset(big_arr2, 1, 100);
	unsigned char arr3[] = { 67, 68, 67, 68, 69, 0, 45 };
	t_ft_memmove_test tests[] = {
		{ "Fill zeroed array with data.", arr2, arr1, 0, 0, 7, 7, 0 },
		{ "Overlapping with n = 0.", arr1, arr1, 0, 2, 0, 7, 1 },
		{ "Overlapping with n = 2.", arr1, arr1, 0, 2, 2, 7, 1 },
		{ "Copying backwards.", arr3, arr3, 1, 0, 2, 7, 1 },
		{ "Source equals destination (no-op).", arr1, arr1, 0, 0, 7, 7, 1 },
		{ "Zero length copy.", arr1, arr1, 0, 0, 0, 7, 1},
		{ "Large copy.", big_arr1, big_arr2, 0, 0, 100, 100, 0 },
	};

	PRINT_TEST_NAME("FT_MEMMOVE");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result;
		char	*expected;
		char buf1[tests[i].buff_size];
		char buf2[tests[i].buff_size];
		memset(buf1, 0, tests[i].buff_size);
		memset(buf2, 0, tests[i].buff_size);
		memcpy(buf1, tests[i].dest, tests[i].buff_size);
		memcpy(buf2, tests[i].dest, tests[i].buff_size);
		if (tests[i].overlapping)
		{
			result = (char *)ft_memmove(buf1 + tests[i].d_offset, buf1 + tests[i].s_offset, tests[i].n);
			expected = (char *)memmove(buf2 + tests[i].d_offset, buf2 + tests[i].s_offset, tests[i].n);
		}
		else
		{
			result = (char *)ft_memmove(buf1 + tests[i].d_offset, tests[i].src + tests[i].s_offset, tests[i].n);
			expected = (char *)memmove(buf2 + tests[i].d_offset, tests[i].src + tests[i].s_offset, tests[i].n);
		}
		if (memcmp(buf1, buf2, tests[i].buff_size) == 0)
		{
			if (verbose)
			{
				PRINT_PASS(tests[i].name);
				print_mem_diff(buf2, buf1, tests[i].buff_size);
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
				print_mem_diff(buf2, buf1, tests[i].buff_size);
				print_mem_diff(expected, result, tests[i].buff_size);
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
