
INCLUDES := ./includes
SRCS := ./srcs/main.c ./srcs/eval.c ./srcs/helpers.c
CFLAGS := -Wall -Wextra -Werror
CC := gcc
TARGET := eval

all :
	@$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) -I $(INCLUDES)
	@echo eval created