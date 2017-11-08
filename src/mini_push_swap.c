/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:34:05 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:34:07 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			secondary_sort_part_2(t_pile **pilea, t_pile **pileb, int i)
{
	int		height;

	height = list_height(pilea);
	if (i <= (height / 2))
	{
		while (i > 0)
		{
			rotate_a(pilea, 1);
			i--;
		}
	}
	if (i > (height / 2))
	{
		while (i < height)
		{
			reverse_rotate_a(pilea, 1);
			i++;
		}
	}
	push_b(pilea, pileb);
}

void			third_sort_part_2(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	if (tmpa && tmpa->next != NULL && tmpa->ent > tmpa->next->ent)
		swap_a(&tmpa, 1);
	while (tmpb)
	{
		push_a(pilea, pileb);
		tmpb = *pileb;
	}
}

void			first_sort_part_2(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	int			smallest;
	int			i;
	int			height;

	tmpa = *pilea;
	while (tmpa && tmpa->next != NULL && tmpa->next->next != NULL &&
		check_sort(pilea) == 0)
	{
		height = list_height(pilea);
		smallest = find_smallest(pilea);
		while (tmpa->next != NULL && tmpa->next->next != NULL
			&& check_sort(pilea) == 0)
		{
			i = find_index(pilea, smallest);
			secondary_sort_part_2(pilea, pileb, i);
			smallest = find_smallest(pilea);
			tmpa = *pilea;
		}
	}
	third_sort_part_2(pilea, pileb);
}
