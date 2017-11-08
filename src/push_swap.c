/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:34:32 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:34:33 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			little_sort(t_pile **pilea)
{
	t_pile *tmpa;

	tmpa = *pilea;
	while (check_sort(pilea) == 0)
	{
		if (tmpa->ent > tmpa->next->ent)
			swap_a(pilea, 1);
		else
			reverse_rotate_a(pilea, 1);
		tmpa = *pilea;
	}
}

int				main(int argc, char **argv)
{
	t_pile		*pilea;
	t_pile		*pileb;
	int			l;

	l = 0;
	pilea = NULL;
	pileb = NULL;
	if (argc > 1 && ft_strcmp(argv[1], "-l") == 0)
		l = 1;
	parseur(&pilea, argc, argv, l);
	if (check_sort(&pilea) == 0)
	{
		if (list_height(&pilea) <= 3)
			little_sort(&pilea);
		if (list_height(&pilea) <= 5)
			first_sort_part_2(&pilea, &pileb);
		else
			first_sort(&pilea, &pileb);
	}
	if (l == 1)
		afficher_liste(&pilea, &pileb);
	while(1);
	return (0);
}
