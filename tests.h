/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkugan <mkugan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:18:21 by mkugan            #+#    #+#             */
/*   Updated: 2025/05/19 17:33:09 by mkugan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include "../libft.h"

#ifdef __linux__
# include <bsd/string.h>  // Linux
#else
# include <string.h>      // macOS and BSD
#endif

# define COLOR_RESET	"\x1b[0m"
# define COLOR_GREEN	"\x1b[38;5;10m"
# define COLOR_RED		"\x1b[38;5;52m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_MAGENTA	"\x1b[38;5;201m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_BOLD		"\x1b[1m"

//# define ICON_PASS	"🚀"
//# define ICON_FAIL	"🚧"

# define ICON_PASS "OK"
# define ICON_FAIL "KO"

# define PRINT_TEST_NAME(name) \
	printf("\n" COLOR_BOLD "%s" COLOR_RESET "\n", name)

# define PRINT_PASS(name) \
    printf(COLOR_GREEN "[" ICON_PASS "] %s" COLOR_RESET "\n", name)

# define PRINT_PASS_SHORT() \
    printf(COLOR_GREEN "[" ICON_PASS "] " COLOR_RESET)

# define PRINT_FAIL_SHORT() \
    printf(COLOR_RED "[" ICON_FAIL "] " COLOR_RESET)

# define PRINT_FAIL(name) \
    printf(COLOR_RED "[" ICON_FAIL "] %s" COLOR_RESET "\n", name)

# define PRINT_SUMMARY(total, passed) \
	printf(COLOR_MAGENTA "Summary: %d/%d passed." COLOR_RESET "\n\n", passed, total)

# define PRINT_SUMMARY_SHORT(total, passed) \
	printf(COLOR_MAGENTA "%d/%d\n" COLOR_RESET, passed, total)

void	print_string_diff(const char *expected, const char *result);
void	print_char_diff(char expected, char result);
void	print_sizet_diff(size_t expected, size_t result);
void	print_int_diff(int expected, int result);
void	print_mem_diff(void *expected, void *result, size_t num);
void	print_pointer_diff(void *expected, void *result);
char	*read_file(const char *filename);
void	print_arr_diff(char **arr1, char **arr2);

#endif
