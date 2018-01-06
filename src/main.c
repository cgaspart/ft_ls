/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:55:07 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/04 15:41:01 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_multi(int argc, char **argv)
{
	int		i;
	char	**multi;

	i = 0;
	if (argc > 2)
	{
		multi = ft_check_multi(argc, argv);
		while (multi[i])
		{
			ft_putstr(multi[i]);
			if (!ft_is_file(multi[i]))
				ft_putchar(':');
			ft_putchar('\n');
			ft_simple(multi[i]);
			if (multi[i + 1] != NULL)
				ft_putchar('\n');
			i++;
		}
	}
	else if (argc == 2 && ft_error_simple(argv[1], 1))
		ft_simple(argv[1]);
}

int				main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		ft_simple(".");
	if (argc >= 2)
		ft_multi(argc, argv);
	return (1);
}
