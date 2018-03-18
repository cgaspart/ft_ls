/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:23:33 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/22 10:23:36 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_skip_flag(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			i++;
		else
			break ;
	}
	return (i);
}