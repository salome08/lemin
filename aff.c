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

void		affiche_lem(t_all *all)
{
	int			i;
	t_llist		*tmp_path;

	i = 1;
	while (i <= all->fourmis)
	{
		tmp_path = all->final_path;
		while (tmp_path)
		{
			ft_putstr(YELLOW);
			ft_putstr("L");
			ft_putnbr(i);
			ft_putstr(RESET);
			ft_putstr("-");
			ft_putstr(GREEN);
			ft_putstr(tmp_path->data[0]);
			ft_putstr(RESET);
			ft_putstr("\n");
			tmp_path = tmp_path->next;
		}
		i++;
	}
}

int			end_in_first(t_all *all, t_llist *start)
{
	t_llist *tmp2;

	tmp2 = start->voisin;
	{
		while (tmp2)
		{
			if (!ft_strcmp(tmp2->data[0], all->end[0]))
				return (1);
			tmp2 = tmp2->next;
		}
	}
	return (0);
}

int			is_in_chemin(char **data, t_llist *chemin)
{
	t_llist *tmp;

	tmp = chemin;
	while (tmp)
	{
		if (!ft_strcmp(data[0], tmp->data[0]))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_map		*ft_create_map(char *data)
{
	t_map	*elem;

	elem = (t_map *)malloc(sizeof(t_map));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

void		ft_add_map(t_all *all, char *data)
{
	t_map *tmp;

	tmp = all->map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_map(data);
}
