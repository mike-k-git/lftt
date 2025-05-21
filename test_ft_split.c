/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:47:18 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 17:32:09 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	ft_arrcmp(char **arr1, char **arr2)
{
	while (*arr1)
	{
		if (!*arr2)
			return (1);
		size_t arr1_len = ft_strlen(*arr1);
		size_t arr2_len = ft_strlen(*arr2);
		if (arr1_len < arr2_len)
			return (-1);
		else if (arr1_len > arr2_len)
			return (1);
		size_t cmp = ft_strncmp(*arr1, *arr2, arr1_len);
		if (cmp != 0)
			return (cmp);
		arr1++;
		arr2++;
	}
	if (*arr2)
		return (-1);
	return (0);
}

typedef struct s_ft_split_test {
	const char *name;
	char *s;
	char delimiter;
	char **expected;
} t_ft_split_test;

void	test_ft_split(int verbose)
{
	int	total = 0;
	int	passed = 0;
	char *res1[] = { "apple", "banana", "orange", NULL };
	char *res2[] = { "one", "three", NULL };
	char *res3[] = { "hello", NULL };
	char *res4[] = { "hello", "world", NULL };
	char *res5[] = { NULL };
	char *res6[] = { "hello world", NULL };
	t_ft_split_test tests[] = {
		{"Simple string with a single delimiter.", "apple,banana,orange", ',', res1},
		{"String with multiple delimiters in a row.", "one,,three", ',', res2},
		{"String without delimiters.", "hello", ',', res3},
		{"String starts with a delimiter.", ",hello", ',', res3},
		{"String ends with a delimiter.", "hello,", ',', res3},
		{"Delimiter appears only once.", "hello-world", '-', res4},
		{"Empty string.", "", '-', res5},
		{"String containing only delimiter.", "////", '/', res5},
		{"Delimiter is a space.", "hello world", ' ', res4},
		{"No delimiter in the string.", "hello world", '.', res6},
	};

	PRINT_TEST_NAME("FT_SPLIT");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	**result = ft_split(tests[i].s, tests[i].delimiter);
		if (ft_arrcmp(result, tests[i].expected) == 0)
		{
			if (verbose)
	  		{
				PRINT_PASS(tests[i].name);
				print_arr_diff(result, tests[i].expected);
			}
			else
	  		{
				PRINT_PASS_SHORT();
			}	
			passed = passed + 1;
		}
		else
		{
			if (verbose)
			{
				PRINT_FAIL(tests[i].name);
				print_arr_diff(result, tests[i].expected);
			}
			else
	  		{
				PRINT_FAIL_SHORT();
			}
		}
		if (result)
		{
			for (int i = 0; result[i] != NULL; i++) {
        		free(result[i]);
    		}
			free(result);
		}
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
