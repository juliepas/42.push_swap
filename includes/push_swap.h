/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:36:35 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:36:36 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct			s_pile
{
	int					ent;
	struct s_pile		*next;
}						t_pile;

void					parseur(t_pile **pilea, int argc, char **argv, int l);
void					add_struct(t_pile **pilea, int argv);
void					swap_a(t_pile **pilea, int i);
void					swap_b(t_pile **pileb, int i);
void					swap_a_et_b(t_pile **pilea, t_pile **pileb);
void					swap_a_et_b_checker(t_pile **pilea, t_pile **pileb);
void					push_a(t_pile **pilea, t_pile **pileb);
void					push_a_checker(t_pile **pilea, t_pile **pileb);
void					push_b(t_pile **pilea, t_pile **pileb);
void					push_b_checker(t_pile **pilea, t_pile **pileb);
void					rotate_a(t_pile **pilea, int i);
void					rotate_b(t_pile **pileb, int i);
void					rotate_a_et_b(t_pile **pilea, t_pile **pileb);
void					rotate_a_et_b_checker(t_pile **pilea, t_pile **pileb);
void					reverse_rotate_a(t_pile **pilea, int i);
void					reverse_rotate_b(t_pile **pileb, int i);
void					reverse_rotate_a_et_b(t_pile **pilea, t_pile **pileb);
void					reverse_rotate_a_et_b_checker(t_pile **pilea,
	t_pile **pileb);
void					first_sort(t_pile **pilea, t_pile **pileb);
int						find_mediane(t_pile **pilea, int height, int argc);
int						list_height(t_pile **pilex);
int						find_smallest(t_pile **pilea);
int						find_index(t_pile **pilea, int value);
void					afficher_liste(t_pile **pilea, t_pile **pileb);
int						find_place_value_b(t_pile **pilex, int value);
void					first_sort_part_2(t_pile **pilea, t_pile **pileb);
int						check_sort(t_pile **pilex);
int						find_value(t_pile **pilex, int index);
void					third_sort_part_2(t_pile **pilea, t_pile **pileb);
void					rm_liste(t_pile **pilea);
long long int			ft_longatoi(const char *str);
void					rm_tab(char **tab);

#endif
