# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Colors
COLOR_BLUE_BOLD := \033[34;1;m
COLOR_CYAN_BOLD := \033[36;1;m
COLOR_YELLOW := \033[33m
COLOR_RESET := \033[0m

SRC_DIR := ..

TARGET_LIBRARY := $(SRC_DIR)/libft.a

SRCS = $(SRC_DIR)/ft_atoi.c \
	   $(SRC_DIR)/ft_bzero.c \
	   $(SRC_DIR)/ft_calloc.c \
	   $(SRC_DIR)/ft_isalnum.c \
	   $(SRC_DIR)/ft_isalpha.c \
	   $(SRC_DIR)/ft_isascii.c \
	   $(SRC_DIR)/ft_isdigit.c \
	   $(SRC_DIR)/ft_isprint.c \
	   $(SRC_DIR)/ft_itoa.c \
	   $(SRC_DIR)/ft_memchr.c \
	   $(SRC_DIR)/ft_memcmp.c \
	   $(SRC_DIR)/ft_memcpy.c \
	   $(SRC_DIR)/ft_memmove.c \
	   $(SRC_DIR)/ft_memset.c \
	   $(SRC_DIR)/ft_putchar_fd.c \
	   $(SRC_DIR)/ft_putendl_fd.c \
	   $(SRC_DIR)/ft_putnbr_fd.c \
	   $(SRC_DIR)/ft_putstr_fd.c \
	   $(SRC_DIR)/ft_split.c \
	   $(SRC_DIR)/ft_strchr.c \
	   $(SRC_DIR)/ft_strdup.c \
	   $(SRC_DIR)/ft_striteri.c \
	   $(SRC_DIR)/ft_strjoin.c \
	   $(SRC_DIR)/ft_strlcat.c \
	   $(SRC_DIR)/ft_strlcpy.c \
	   $(SRC_DIR)/ft_strlen.c \
	   $(SRC_DIR)/ft_strmapi.c \
	   $(SRC_DIR)/ft_strncmp.c \
	   $(SRC_DIR)/ft_strnstr.c \
	   $(SRC_DIR)/ft_strrchr.c \
	   $(SRC_DIR)/ft_strtrim.c \
	   $(SRC_DIR)/ft_substr.c \
	   $(SRC_DIR)/ft_tolower.c \
	   $(SRC_DIR)/ft_toupper.c

SRCS_BONUS = $(SRC_DIR)/ft_lstadd_back.c \
			 $(SRC_DIR)/ft_lstadd_front.c \
			 $(SRC_DIR)/ft_lstclear.c \
			 $(SRC_DIR)/ft_lstdelone.c \
			 $(SRC_DIR)/ft_lstiter.c \
			 $(SRC_DIR)/ft_lstlast.c \
			 $(SRC_DIR)/ft_lstmap.c \
			 $(SRC_DIR)/ft_lstnew.c \
			 $(SRC_DIR)/ft_lstsize.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(TARGET_LIBRARY)

$(TARGET_LIBRARY): $(OBJS)
	@echo "Creating library $(COLOR_BLUE_BOLD)$@$(COLOR_RESET)"
	@ar rcs $@ $^

bonus: $(TARGET_LIBRARY) $(OBJS_BONUS)
	@echo "Adding $(COLOR_BLUE_BOLD)bonus$(COLOR_RESET) to library"
	@ar rs $< $(OBJS_BONUS)
	@touch bonus

%.o: %.c
	@echo "Compiling $(COLOR_CYAN_BOLD)$<$(COLOR_RESET)"
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "$(COLOR_YELLOW)Cleaning object files$(COLOR_RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS) bonus

fclean: clean
	@echo "$(COLOR_YELLOW)Removing the library$(COLOR_RESET)"
	@rm -f $(TARGET_LIBRARY)

re: fclean all

TEST_DIR := .
SRCS_TEST := $(TEST_DIR)/main.c \
			 $(TEST_DIR)/test_ft_strlcpy.c \
			 $(TEST_DIR)/test_ft_strlcat.c \
			 $(TEST_DIR)/test_ft_strnstr.c \
			 $(TEST_DIR)/test_ft_strlen.c \
			 $(TEST_DIR)/test_ft_atoi.c \
			 $(TEST_DIR)/test_ft_bzero.c \
			 $(TEST_DIR)/test_ft_calloc.c \
			 $(TEST_DIR)/test_ft_isalnum.c \
			 $(TEST_DIR)/test_ft_isalpha.c \
			 $(TEST_DIR)/test_ft_isascii.c \
			 $(TEST_DIR)/test_ft_isdigit.c \
			 $(TEST_DIR)/test_ft_isprint.c \
			 $(TEST_DIR)/test_ft_toupper.c \
			 $(TEST_DIR)/test_ft_tolower.c \
			 $(TEST_DIR)/test_ft_itoa.c \
			 $(TEST_DIR)/test_ft_memchr.c \
			 $(TEST_DIR)/test_ft_memcmp.c \
			 $(TEST_DIR)/test_ft_memcpy.c \
			 $(TEST_DIR)/test_ft_strchr.c \
			 $(TEST_DIR)/test_ft_strrchr.c \
			 $(TEST_DIR)/test_ft_strncmp.c \
			 $(TEST_DIR)/test_ft_memset.c \
			 $(TEST_DIR)/test_ft_memmove.c \
			 $(TEST_DIR)/test_ft_putchar_fd.c \
			 $(TEST_DIR)/test_ft_putstr_fd.c \
			 $(TEST_DIR)/test_ft_putendl_fd.c \
			 $(TEST_DIR)/test_ft_putnbr_fd.c \
			 $(TEST_DIR)/test_ft_substr.c \
			 $(TEST_DIR)/test_ft_strjoin.c \
			 $(TEST_DIR)/test_ft_strtrim.c \
			 $(TEST_DIR)/test_ft_split.c \
			 $(TEST_DIR)/test_ft_strmapi.c \
			 $(TEST_DIR)/test_ft_striteri.c \
			 $(TEST_DIR)/test_ft_strdup.c \
			 $(TEST_DIR)/test_ft_lstnew.c

OBJS_TEST := $(SRCS_TEST:.c=.o)
UNAME_S := $(shell uname -s)
LDFLAGS := -L.. -lft
TEST_BIN := libft_tests
ifeq ($(UNAME_S),Linux)
	LDFLAGS += -lbsd
endif

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@echo "Compiling $(COLOR_CYAN_BOLD)$<$(COLOR_RESET)"
	@$(CC) -c $(CFLAGS) $< -o $@

test_run: bonus $(OBJS_TEST)
	@$(CC) $(CFLAGS) -g $(OBJS_TEST) $(OBJS) $(OBJS_BONUS) $(LDFLAGS) -o ${TEST_BIN}
	./${TEST_BIN} $(VERBOSE)

test_clean: fclean
	@rm -f $(OBJS_TEST) $(TEST_BIN)

test_re: test_run test_clean

.PHONY: all clean fclean re test_run test_clean
