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

void		keep_lien(char **data, t_all *all)
{
	static int count = 0;

	if (!does_salle_exist(data, all))
		ft_error(4);
	if (count == 0)
		all->list_lien = ft_create_lien(data);
	else
	{
		ft_add_lien(all, data);
	}
	count = 1;
}

t_llist		*ft_create_lien(char **data)
{
	t_llist *elem;

	elem = (t_llist *)malloc(sizeof(t_llist));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

void		ft_add_lien(t_all *all, char **data)
{
	t_llist *tmp;

	tmp = all->list_lien;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_lien(data);
}

void		ft_add_chemin(t_llist *chemin, char **data)
{
	t_llist *tmp;

	tmp = chemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_salle2(data);
}

void		ft_add_path(t_all *all, char **data)
{
	t_llist *tmp;

	tmp = ft_create_salle2(data);
	tmp->next = all->final_path;
	all->final_path = tmp;
}
