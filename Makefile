# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 13:12:42 by lgaultie          #+#    #+#              #
#    Updated: 2019/04/12 16:20:31 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS += -Wall -Werror -Wextra
OBJDIR = obj
SRCDIR = src
LIBDIR	= libft
INCDIR	= $(LIBDIR)
HEAD	= $(SRCDIR)/ft_printf.h

SRCS =	main.c					\
		ft_printf.c				\
		ft_analyse.c			\
		ft_d_i.c				\
		ft_c.c					\
		ft_s.c					\
		ft_f.c					\
		ft_oxcapsx.c			\
		ft_flags.c				\
		ft_accuracy.c			\
		ft_width.c				\
		ft_p.c					\
		ft_which_flag.c			\
		ft_intlen.c				\
		ft_itoa.c				\
		ft_itoa_base.c			\
		ft_memalloc.c			\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_strdup.c				\
		ft_strjoin.c			\
		ft_strlen.c				\
		ft_strncpy.c			\
		ft_strnew.c				\
		ft_strsub.c				\
		ft_tolower.c			\
		ft_atoi.c				\
		ft_bzero.c				\
		ft_memset.c				\
		ft_nb_len_base.c		\
		ft_strcat.c				\
		ft_strcpy.c				\
		ft_plus_minus.c			\
		ft_only_conv.c			\
		ft_width_prc.c			\
		ft_hhh_lll.c			\
		ft_strcmp.c				\
		ft_strndup.c			\
		ft_width_prc_minus.c 	\
		ft_width_prc2.c			\
		ft_width2.c				\
		ft_active_flags.c		\
		ft_flags2.c

CFLAGS += -I$(INCDIR)
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB		= $(LIBDIR)/libft.a

_GREEN=\e[32m
_YELLOW=\e[33m
_BLUE=\e[34m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "compiling... "
	@ar rcs $@ $^
	@printf "[$(_GREEN)✓$(_END)]\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/%.o: $(LIBDIR)/%.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... "
	@rm -rf $(OBJDIR)
	@printf "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@printf "fclean... "
	@rm -f $(NAME)
	@rm -rf ft_printf.dSYM
	@rm -rf a.out.dSYM
	@rm -rf a.out
	@printf "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re
