/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:41:02 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 12:41:49 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_calloc_test {
	const char *name;
	size_t		nmemb;
	size_t		size;
	int			nul;
} t_ft_calloc_test;

void	test_ft_calloc(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_calloc_test tests[] = {
		{"Basic ft_calloc.", 5, sizeof(int), 0},
		{"Zero 'size'", 5, 0, 0},
		{"Zero 'nmemb'", 0, 5, 0},
		{"Zero both 'size' and 'nmemb'", 0, 0, 0},
		{"Overflow", SIZE_MAX, SIZE_MAX, 1}
	};

	PRINT_TEST_NAME("FT_CALLOC");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char *buf1 = (char *)ft_calloc(tests[i].nmemb, tests[i].size);
		char *buf2 = (char *)calloc(tests[i].nmemb, tests[i].size);
		if (tests[i].nul == 1)
		{
			if (buf1 == NULL && buf2 == NULL)
			{
				if (verbose)
				{
					printf("Both buffers are null.\n");
					PRINT_PASS(tests[i].name);
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
					printf("Expected: '%p', Result: '%p'",buf2, buf1);
	  			}
	  			else
	  				PRINT_FAIL_SHORT();
			}
		}
		else if (buf1 != NULL && buf2 != NULL)
		{
			if (tests[i].nmemb * tests[i].size == 0)
			{
				if (verbose)
				{
					printf("The non-NULL buffer is returned (safe to free).\n");
					PRINT_PASS(tests[i].name);
				}
				else
					PRINT_PASS_SHORT();
				passed = passed + 1;
			}
			else if (memcmp(buf1, buf2, tests[i].nmemb * tests[i].size) == 0)
			{
				if (verbose)
				{
					PRINT_PASS(tests[i].name);
					print_mem_diff(buf2, buf1, tests[i].nmemb * tests[i].size);
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
					print_mem_diff(buf2, buf1, tests[i].nmemb * tests[i].size);
				}
	  			else
	  				PRINT_FAIL_SHORT();
			}
		}
		else
		{
			if (verbose)
			{
				PRINT_FAIL(tests[i].name);
				printf("Expected: '%p', Result: '%p'",buf2, buf1);
			}
	  		else
	  			PRINT_FAIL_SHORT();
		}
		if (buf1)
			free(buf1);
		if (buf2)
			free(buf2);
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
