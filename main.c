/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 12:25:18 by shazan            #+#    #+#             */
/*   Updated: 2016/05/24 15:39:36 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			main(void)
{
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	init_all(all);
	parse(all);
	if (!all->start || !all->end)
		ft_error(1);
	aff_map(all);
	ft_putstr("\n");
	algo(all);
	return (0);
}

void		init_all(t_all *all)
{
	all->list_salle = NULL;
	all->path = NULL;
	all->start = NULL;
	all->list_lien = NULL;
	all->map = NULL;
	all->chemin = NULL;
	all->end = NULL;
	all->final_path = NULL;
	all->nb_entree = 0;
	all->nb_sortie = 0;
	all->indic = 0;
	all->fourmis = 0;
}

void		keep_com(char *str, t_all *all)
{
	if (all->indic == 1)
		all->start = tab_test_syntax(str, ' ', 3);
	if (all->indic == 2)
		all->end = tab_test_syntax(str, ' ', 3);
	all->indic = 0;
}

void		ft_error(int i)
{
	if (i == 1)
		ft_putstr("ERROR\n");
	if (i == 2)
		ft_putstr("Need number of Lemin\n");
	if (i == 3)
		ft_putstr("ERROR syntaxe\n");
	if (i == 4)
		ft_putstr("ERROR tube, room does not exist\n");
	if (i == 5)
		ft_putstr("ERROR, no path found\n");
	exit(0);
}
