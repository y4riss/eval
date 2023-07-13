
INCLUDES := ./includes
SRCS := ./srcs/main.c ./srcs/eval.c
CFLAGS := -Wall -Wextra -Werror
CC := gcc
TARGET := eval

all :
	$(CC) $(SRCS) -o $(TARGET) -I $(INCLUDES)