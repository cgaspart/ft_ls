/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:55:07 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:28:21 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_argsimple(char *dirname, char *option)
{
	int		a_option;
	t_data	*data;
	char	**order;

	a_option = 0;
	if (ft_strchr(option, 'a'))
		a_option = 1;
	if (ft_strchr(option, 'l'))
	{
		order = ft_get_ascii_tab(dirname, a_option);
		data = ft_getdata(dirname, a_option);
		ft_sort_lst(&data, order);
		ft_print_l(&data);
	}
}

int				main(int argc, char **argv)
{
	char	*option;

	if (argc == 1)
		ft_simple(".");
	if (argc == 2 && !ft_argcheck(argv))
		ft_simple(argv[1]);
	if (argc == 2 && (option = ft_argcheck(argv)))
		ft_argsimple(".", option);
	return (1);
}
