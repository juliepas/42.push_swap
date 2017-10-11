/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:37:10 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:37:15 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			reverse_third_sort(t_pile **pileb, t_pile **pilea)
{
	t_pile		*tmpa;
	int			i;
	int			height;
	int			small_a;

	tmpa = *pilea;
	height = list_height(pileb);
	small_a = find_smallest(pilea);
	i = find_index(pileb, find_smallest(pileb));
	if (i < (height / 2))
		while (i >= 0)
		{
			(tmpa->ent > small_a) ? rotate_a_et_b(pilea, pileb)
			: rotate_b(pileb, 1);
			i--;
		}
	if (i >= (height / 2))
		while (i < (height - 1))
		{
			(tmpa->ent > small_a) ?
				reverse_rotate_a_et_b(pilea, pileb)
				: reverse_rotate_b(pileb, 1);
			i++;
		}
}

void			third_sort(t_pile **pilea, t_pile **pileb, int mediane)
{
	t_pile		*tmpa;
	int			i;
	int			height;

	tmpa = *pilea;
	height = list_height(pileb);
	i = (height >= 2) ? find_place_value_b(pileb, tmpa->ent) : 0;
	if (i <= (height / 2))
		while (i > 0)
		{
			(tmpa->ent > mediane) ?
				rotate_a_et_b(pilea, pileb) : rotate_b(pileb, 1);
			i--;
			tmpa = *pilea;
		}
	else if (i > (height / 2))
		while (i < height)
		{
			(tmpa->ent > mediane) ?
				reverse_rotate_a_et_b(pilea, pileb)
				: reverse_rotate_b(pileb, 1);
			i++;
			tmpa = *pilea;
		}
	push_b(pilea, pileb);
}

void			secondary_sort(t_pile **pilea, t_pile **pileb, int i, int med)
{
	t_pile	*tmpb;
	int		height;
	int		value;

	tmpb = *pileb;
	height = list_height(pilea);
	value = find_value(pilea, i);
	if (i <= (height / 2))
		while (i > 0)
		{
			(tmpb && tmpb->next && tmpb->ent > value) ?
				rotate_a_et_b(pilea, pileb) : rotate_a(pilea, 1);
			i--;
			tmpb = *pileb;
		}
	if (i > (height / 2))
		while (i < height)
		{
			(tmpb && tmpb->next && tmpb->ent > value) ?
				reverse_rotate_a_et_b(pilea, pileb)
				: reverse_rotate_a(pilea, 1);
			i++;
			tmpb = *pileb;
		}
	third_sort(pilea, pileb, med);
}

int				put_first_last(t_pile **pilea, t_pile **pileb, int argc)
{
	int i;
	int j;
	int med;
	int last;

	last = list_height(pilea);
	i = find_index(pilea, find_smallest(pilea));
	med = find_mediane(pilea, last, argc);
	j = find_index(pilea, med);
	if ((i > j && i > (last - j)) ||
		((last - i) > (last - j) && (last - i) > j))
	{
		secondary_sort(pilea, pileb, i, med);
		j = find_index(pilea, med);
		secondary_sort(pilea, pileb, j, med);
	}
	else
	{
		secondary_sort(pilea, pileb, j, med);
		i = find_index(pilea, find_smallest(pilea));
		secondary_sort(pilea, pileb, i, med);
	}
	return (med);
}

void			first_sort(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	int			firstheight;
	int			med;
	int			i;

	firstheight = list_height(pilea);
	while (list_height(pilea) > 2 && check_sort(pilea) == 0)
	{
		med = put_first_last(pilea, pileb, firstheight);
		while (check_sort(pilea) == 0)
		{
			tmpa = *pilea;
			i = 0;
			while (tmpa && tmpa->ent > med)
			{
				i++;
				tmpa = tmpa->next;
			}
			if (tmpa == NULL)
				break ;
			secondary_sort(pilea, pileb, i, med);
		}
		reverse_third_sort(pileb, pilea);
	}
	first_sort_part_2(pilea, pileb);
}
