# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/11 14:16:29 by vtenneke       #+#    #+#                 #
#    Updated: 2019/11/19 13:51:04 by vtenneke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRCS		=	ft_printf ft_converters_cti ft_converters_u utilities/ft_chr_str\
				utilities/ft_hex utilities/ft_int_dec_ll utilities/ft_int\
				utilities/ft_un_int utilities/ft_hex_ll utilities/ft_general_utils
LIBSRCS		=	ft_putchar_fd ft_putstr_fd
CFILES		=	$(SRCS:%=srcs/%.c)
LIBCFILES	=	$(LIBSRCS:%=libft/%.c)
OFILES		=	$(CFILES:.c=.o)
LIBOFILES	=	$(LIBCFILES:.c=.o)
INCLUDES	=	./includes
FLAGS		=	-Wall -Werror -Wextra -Wno-unused-parameter

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

$(NAME): $(OFILES)
	@echo "$(YELLOW)Linking the library..."
	@ar rc $(NAME) $(OFILES)
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

re: fclean all

bonus: $(OFILES) $(LIBOFILES)
	@echo "$(YELLOW)Linking the bonusses into the library..."
	@ar rc $(NAME) $(OFILES) $(LIBOFILES)
	@ranlib $(NAME)
	@echo "$(GREEN)Done!"