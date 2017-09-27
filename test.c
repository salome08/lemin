/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 12:25:18 by shazan            #+#    #+#             */
/*   Updated: 2016/03/08 12:25:20 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

char			**tab_test_syntax(char *str, char delimit, int nb_w)
{
	char	**tab_str;
	int		i;

	i = 0;
	tab_str = ft_strsplit(str, delimit);
	while (tab_str[i])
	{
		if (nb_w == 3 && i > 0)
		{
			if (!is_number(tab_str[i]))
				ft_error(3);
		}
		i++;
	}
	if (i != nb_w)
		ft_error(3);
	return (tab_str);
}

int				wich_command_is_it(char *str, t_all *all)
{
	if (!ft_strcmp(str, "##start"))
		all->indic = 1;
	if (!ft_strcmp(str, "##end"))
		all->indic = 2;
	return (20);
}

int				is_com(char *str, t_all *all)
{
	if (!ft_strncmp(str, "#", 1))
	{
		if (!ft_strncmp(str, "##", 2))
			wich_command_is_it(str, all);
		return (1);
	}
	return (0);
}

int				is_number(char *str)
{
	int		str_int;
	char	*str2;

	str_int = ft_atoi(str);
	str2 = ft_itoa(str_int);
	if (ft_strcmp(str2, str) != 0)
		return (0);
	return (1);
}

int				does_salle_exist(char **data_lien, t_all *all)
{
	t_llist		*tmp;
	int			a;
	int			b;

	a = 0;
	b = 0;
	tmp = all->list_salle;
	while (tmp)
	{
		if (!ft_strcmp(data_lien[0], tmp->data[0]))
			a = 1;
		if (!ft_strcmp(data_lien[1], tmp->data[0]))
			b = 1;
		if (a + b == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
