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

void			algo(t_all *all)
{
	t_llist *tmp_salle;

	tmp_salle = all->list_salle;
	find_near(all);
	while (ft_strcmp(tmp_salle->data[0], all->start[0]))
		tmp_salle = tmp_salle->next;
	all->chemin = ft_create_salle2(&tmp_salle->data[0]);
	all->path = ft_create_salle2(&all->end[0]);
	if (!recursive(all, tmp_salle))
		ft_error(5);
	reverse_list(all);
	affiche_lem(all);
}

void			reverse_list(t_all *all)
{
	t_llist *tmp;

	tmp = all->path;
	while (tmp)
	{
		if (all->final_path)
			ft_add_path(all, &tmp->data[0]);
		else
			all->final_path = ft_create_salle2(&tmp->data[0]);
		tmp = tmp->next;
	}
	all->final_path = all->final_path->next;
}

void			find_near(t_all *all)
{
	t_llist *tmp_lien;
	t_llist *tmp_salle;

	tmp_lien = all->list_lien;
	while (tmp_lien)
	{
		tmp_salle = all->list_salle;
		while (ft_strcmp(tmp_salle->data[0], tmp_lien->data[0]))
			tmp_salle = tmp_salle->next;
		if (tmp_salle->voisin)
			ft_add_voisin(tmp_salle->voisin, &tmp_lien->data[1]);
		else
			tmp_salle->voisin = ft_create_salle(&tmp_lien->data[1]);
		tmp_salle = all->list_salle;
		while (ft_strcmp(tmp_salle->data[0], tmp_lien->data[1]))
			tmp_salle = tmp_salle->next;
		if (tmp_salle->voisin)
			ft_add_voisin(tmp_salle->voisin, &tmp_lien->data[0]);
		else
			tmp_salle->voisin = ft_create_salle(&tmp_lien->data[0]);
		tmp_lien = tmp_lien->next;
	}
}

int				recursive(t_all *all, t_llist *current)
{
	t_llist *tmp_voisin;

	if (!ft_strcmp(current->data[0], all->end[0]))
		return (1);
	ft_add_chemin(all->chemin, &current->data[0]);
	tmp_voisin = current->voisin;
	while (tmp_voisin)
	{
		if (!is_in_chemin(&tmp_voisin->data[0], all->chemin))
			if (recursive(all, find_voisin_voisin(all, tmp_voisin->data[0])))
			{
				ft_add_chemin(all->path, &current->data[0]);
				return (1);
			}
		tmp_voisin = tmp_voisin->next;
	}
	return (0);
}

t_llist			*find_voisin_voisin(t_all *all, char *data)
{
	t_llist *tmp;

	tmp = all->list_salle;
	while (tmp)
	{
		if (!ft_strcmp(tmp->data[0], data))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
