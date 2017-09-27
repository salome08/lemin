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

void		keep_salle(char **data, t_all *all)
{
	static int count = 0;

	if (count == 0)
		all->list_salle = ft_create_salle(data);
	else
	{
		ft_add_salle(all, data);
	}
	count = 1;
}

t_llist		*ft_create_salle(char **data)
{
	t_llist *elem;

	elem = (t_llist *)malloc(sizeof(t_llist));
	elem->next = NULL;
	elem->voisin = NULL;
	elem->data = data;
	return (elem);
}

void		ft_add_salle(t_all *all, char **data)
{
	t_llist *tmp;

	tmp = all->list_salle;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_salle(data);
}

t_llist		*ft_create_salle2(char **data)
{
	t_llist *elem;

	elem = (t_llist *)malloc(sizeof(t_llist));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

void		ft_add_voisin(t_llist *voisin, char **data)
{
	t_llist *tmp;

	tmp = voisin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_salle(data);
}
