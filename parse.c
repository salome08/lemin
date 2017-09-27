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

void		parse(t_all *all)
{
	int		step;
	char	*line;

	step = 1;
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, ""))
			break ;
		get_map(all, line);
		if (is_com(line, all))
			continue ;
		if (step == 1)
			parse2(line, all);
		else
		{
			if (all->indic > 0)
				keep_com(line, all);
			if (!is_com(line, all) && !ft_strchr(line, '-'))
				keep_salle(tab_test_syntax(line, ' ', 3), all);
			if (!is_com(line, all) && ft_strchr(line, '-'))
				keep_lien(tab_test_syntax(line, '-', 2), all);
		}
		step++;
	}
}

void		get_map(t_all *all, char *line)
{
	if (all->map)
		ft_add_map(all, line);
	else
		all->map = ft_create_map(line);
}

void		aff_map(t_all *all)
{
	t_map *tmp;

	tmp = all->map;
	while (tmp)
	{
		ft_putstr(MAGENTA);
		ft_putstr(tmp->data);
		ft_putstr(RESET);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void		parse2(char *line, t_all *all)
{
	if (!is_number(line) || ft_atoi(line) <= 0)
		ft_error(2);
	all->fourmis = ft_atoi(line);
}
