# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 11:11:37 by cgaspart          #+#    #+#              #
#    Updated: 2018/01/30 10:03:02 by cgaspart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_PATH = src
OBJ_PATH = obj
CPPFLAGS = -Iinclude
LDFLAGS = -L./libft
LDLIBS = -lft
CFLAGS = -Werror -Wall -Wextra -g
CC = clang
SRC_NAME = main.c\
	  ft_type.c\
	  ft_right.c\
	  ft_putright.c\
	  ft_date_converter.c\
	  ft_simple.c\
	  ft_error.c\
	  ft_is_file.c\
	  ft_arg_opt.c\
	  l_option.c\
	  ft_print_l.c\
	  ft_get_ascii_tab.c\
	  ft_nf_arg_ascii.c\
	  ft_f_arg_ascii.c\
	  ft_f_arg_revascii.c\
	  ft_nf_multi.c\
	  ft_f_simple.c\
	  ft_get_order.c\
	  ft_f_multi.c\
	  ft_get_t_tab.c\
	  ft_error_np.c\
	  ft_l_option.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) -g $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	make -C libft clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
