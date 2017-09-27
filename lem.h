/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 12:21:14 by shazan            #+#    #+#             */
/*   Updated: 2016/03/08 12:21:18 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include <fcntl.h>
# include "libft/libft.h"
# define YELLOW "\x1b[33m"
# define GREEN "\x1b[32m"
# define MAGENTA "\x1b[35m"
# define RESET "\033[0m"

typedef struct			s_llist
{
	char				**data;
	struct s_llist		*voisin;
	struct s_llist		*next;
}						t_llist;

typedef	struct			s_map
{
	char				*data;
	struct s_map		*next;
}						t_map;

typedef struct			s_all
{
	int				indic;
	int				nb_entree;
	int				nb_sortie;
	int				fourmis;
	char			**start;
	char			**end;
	t_llist			*list_salle;
	t_llist			*list_lien;
	t_llist			*chemin;
	t_llist			*path;
	t_llist			*final_path;
	t_map			*map;
}						t_all;

void					parse(t_all *all);
void					init_all(t_all *all);
char					**tab_test_syntax(char *str, char delimit, int nb_w);
void					keep_com(char *str, t_all *all);
int						wich_command_is_it(char *str, t_all *all);
int						is_com(char *str, t_all *all);
int						is_number(char *str);
void					keep_salle(char **data, t_all *all);
t_llist					*ft_create_salle(char **data);
void					ft_add_salle(t_all *all, char **data);
void					keep_lien(char **data, t_all *all);
t_llist					*ft_create_lien(char **data);
void					ft_add_lien(t_all *all, char **data);
void					affiche_cell(t_all *all);
void					ft_error(int i);
int						does_salle_exist(char **data_lien, t_all *all);
void					nombre_entsort(t_all *all);
void					algo(t_all *all);
void					ft_add_voisin(t_llist *voisin, char **data);
void					keep_chemin(t_all *all);
void					find_near(t_all *all);
void					affiche_chemin(t_all *all);
int						recursive(t_all *all, t_llist *start);
int						is_in_chemin(char **data, t_llist *chemin);
int						end_in_first(t_all *all, t_llist *start);
t_llist					*find_voisin_voisin(t_all *all, char *data);
t_llist					*ft_create_salle2(char **data);
void					ft_add_chemin(t_llist *chemin, char **data);
void					affiche_lem(t_all *all);
void					ft_add_path(t_all *all, char **data);
void					reverse_list(t_all *all);
void					parse2(char *line, t_all *all);
void					get_map(t_all *all, char *line);
t_map					*ft_create_map(char *data);
void					ft_add_map(t_all *all, char *data);
void					aff_map(t_all *all);
#endif
