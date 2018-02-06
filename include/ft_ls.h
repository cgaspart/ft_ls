/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:56:54 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:06:07 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct		s_right
{
	int				owner;
	int				group;
	int				other;
}					t_right;

typedef struct		s_opt
{
	int				l;
	int				upper_r;
	int				a;
	int				r;
	int				t;
	int				u;
	int				f;
	int				g;
}					t_opt;

typedef struct		s_data
{
	char			*name;
	char			type;
	t_right			*right;
	int				link;
	char			*owner;
	char			*grp;
	int				size;
	char			*date;
	struct s_data	*next;
}					t_data;

char				ft_type(char *dirname);
t_right				*ft_right(struct stat fstat);
void				ft_putright(t_right *right);
void				ft_simple(char	*dirname);
char				*ft_date_converter(char *time);
int					ft_error_simple(char *dirname, int mod);
int					ft_is_file(char *name);
char				**ft_check_dir(int argc, char **argv);
char				**ft_check_file(int argc, char **argv);
int					ft_arg_opt(char **argv, int argc, t_opt *option);
t_data				*ft_getdata(char **order);
void				ft_print_l(t_data **data);
char				**ft_get_ascii_tab(char *dirname, int a_option);
#endif
