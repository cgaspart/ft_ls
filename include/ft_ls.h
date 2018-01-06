/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:56:54 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/06 10:53:32 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
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

char				*ft_type(char *dirname);
t_right				*ft_right(struct stat fstat);
void				ft_putright(t_right *right);
void				ft_simple(char	*dirname);
char				*ft_date_converter(char *time);
int					ft_error_simple(char *dirname, int mod);
int					ft_is_file(char *name);
char				**ft_check_dir(int argc, char **argv);
char				**ft_check_file(int argc, char **argv);

#endif
