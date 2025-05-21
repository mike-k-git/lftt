/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:37:58 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 16:45:29 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_strtrim_test {
	const char *name;
	const char *s1;
	const char *set;
	const char *expected;
} t_ft_strtrim_test;

void	test_ft_strtrim(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_strtrim_test tests[] = {
		{"Removing leading and trailing spaces.", " Hello, World! ", " ", "Hello, World!"},
		{"Removing specific characters.", "///abcde///", "/", "abcde"},
		{"Empty string.", "", "abc", ""},
		{"Removing digits from egdes.", "123abc132", "123", "abc"},
		{"No characters to remove.", "Hello", "abc", "Hello"},
		{"Removing multiple characters from both sides.", ">>>hello<<<", "><", "hello"},
		{"Removing special characters.", "!!!hello!!!", "!", "hello"},
		{"Removing newlines and tabs.", "\n\thello\n\t", "\n\t", "hello"},
	};

	PRINT_TEST_NAME("FT_STRTRIM");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		char	*result = ft_strtrim(tests[i].s1, tests[i].set);
		if (strcmp(result, tests[i].expected) == 0)
		{
			if (verbose)
	  		{
				PRINT_PASS(tests[i].name);
				print_string_diff(tests[i].expected, result);
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
				print_string_diff(tests[i].expected, result);
			}
			else
	  		{
				PRINT_FAIL_SHORT();
			}
		}
		if (result)
			free(result);
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
