/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:55:50 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 20:11:04 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_ft_lstnew_test {
	const char *name;
	char *content;
} t_ft_lstnew_test;

void	test_ft_lstnew(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_lstnew_test tests[] = {
		{"'Hello' as content", "Hello"},
	};

	PRINT_TEST_NAME("FT_LSTNEW");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		t_list	*result = ft_lstnew(tests[i].content);
		if (strcmp(tests[i].content, result->content) == 0 && (result->next == NULL))
		{
			if (verbose)
	  		{
				PRINT_PASS(tests[i].name);
				printf("<\"%s\", %p>\n", (char *)result->content, result->next);
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
				printf("<\"%s\", %p>\n", (char *)result->content, result->next);
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
