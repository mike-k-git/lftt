#include "tests.h"

typedef struct s_ft_()_test {
	const char *name;
} t_ft_()_test;

void	test_ft_()(int verbose)
{
	int	total = 0;
	int	passed = 0;
	t_ft_()_test tests[] = {
	};

	PRINT_TEST_NAME("FT_{}");
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; i < num_tests; i++)
	{
		total = total + 1;
		int	result = ft_();
		int	expected = ();
		if (result == expected)
		{
			if (verbose)
	  		{
				PRINT_PASS(tests[i].name);
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
			}
			else
	  		{
				PRINT_FAIL_SHORT();
			}
		}
	}
	if (verbose)
		PRINT_SUMMARY(total, passed);
	else
		PRINT_SUMMARY_SHORT(total, passed);
}
