# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/11 14:16:29 by vtenneke       #+#    #+#                 #
#    Updated: 2020/01/23 13:40:45 by vtenneke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRCS		=	ft_char_string.c ft_conv_vars.c ft_hex_long.c\
				ft_hex_longlong.c ft_int_long.c ft_int_longlong.c ft_misc.c\
				ft_prep_hex.c ft_prep_int.c ft_print_hex.c ft_print_int.c\
				ft_print_pointer.c ft_print_un.c ft_printf.c ft_prep_size.c\
				ft_un_int_long.c ft_un_int_longlong.c
LIBSRCS		=	ft_putchar_fd.c ft_putstr_fd.c ft_isdigit.c ft_atoi.c\
				ft_strlen.c
CFILES		=	$(SRCS:%=srcs/%)
LIBCFILES	=	$(LIBSRCS:%=libft/%)
OFILES		=	$(CFILES:.c=.o)
LIBOFILES	=	$(LIBCFILES:.c=.o)
INCLUDES	=	./includes
FLAGS		=	-Wall -Werror -Wextra

# COLORS
WHITE	= \x1b[37;01m
CYAN	= \x1b[36;01m
PINK	= \x1b[35;01m
BLUE	= \x1b[34;01m
YELLOW	= \x1b[33;01m
GREEN	= \x1b[32;01m
RED		= \x1b[31;01m
BLACK	= \x1b[30;01m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(OFILES) $(LIBOFILES)
	@echo "$(YELLOW)Linking the library..."
	@ar rc $(NAME) $(OFILES) $(LIBOFILES)
	@ranlib $(NAME)
	@echo "$(GREEN)Done!"

%.o: %.c
	@echo "$(CYAN)Compiling:	$(WHITE)$<"
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean: clean_b
	@echo "$(YELLOW)Cleaning..."
	@echo "$(GREEN)Done cleaning!"

fclean: clean_b
	@echo "$(RED)Full cleaning..."
	@rm -f $(NAME)
	@echo "$(GREEN)Done cleaning!"

clean_b:
	@rm -f $(LIBOFILES)
	@rm -f $(OFILES)
	@rm -f $(BOFILES)

re: fclean all

bonus: all
