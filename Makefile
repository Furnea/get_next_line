NAME = libgnl.a

CC = cc
BUFFER_SIZE ?= 42
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=$(BUFFER_SIZE)

AR = ar rcs
RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
HEADER = get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
