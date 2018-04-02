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
}					t_opt;

typedef struct		s_data
{
	int				link;
	int				ownerlen;
	int				grplen;
	int				size;
	int				blocks;
}					t_data;

char				ft_type(char *dirname);
t_right				*ft_right(struct stat fstat);
void				ft_putright(t_right *right);
void				ft_simple(char	*dirname);
char				*ft_date_converter(char *time);
int					ft_error(char *dirname, int space);
int					ft_is_file(char *name);
char				**ft_check_dir(int argc, char **argv);
char				**ft_check_file(int argc, char **argv);
int					ft_arg_opt(char **argv, int argc, t_opt *option);
void				l_option(char *dirname, t_opt *option);
void				ft_print_l(t_data *data, int total, char **order);
char				**ft_get_ascii_tab(char *dirname, int a_option);
char				**ft_nf_arg_ascii_dir(int argc, char **argv);
char				**ft_nf_arg_ascii_file(int argc, char **argv);
char				**ft_f_arg_ascii_file(int argc, char **argv);
char				**ft_f_arg_ascii_dir(int argc, char **argv);
char				**ft_f_arg_revascii_dir(int argc, char **argv);
char				**ft_f_arg_revascii_file(int argc, char **argv);
void				ft_nf_multi(int argc, char **argv);
void				ft_f_simple(t_opt *option, char *dirname);
char				**ft_get_order(char *dirname, t_opt *option);
char				**ft_get_lorder(char *dirname, t_opt *option);
void				ft_f_multi(char **argfile, char **argdir, t_opt *option);
char				**ft_get_t_tab(char *dirname, char **order, int r_opt);
void				print_convert_date(char *time);
int					ft_getstat(char **order, t_data *data);
int					ft_error_np(char *dirname);
int					ft_get_right(t_right *right, char *this, int i);
void				ft_get_blocks(t_data *data);
int					owner_grp_check(struct passwd *duser, struct group *dgroup,
	t_data *data);
void				is_link(char *name, t_buffer *this);
#endif
